#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <fstream>
#include <stack>
#include <map>
using namespace std;

vector<string> split_string(string);
//int visit[100001] = { false, };
map<int, bool> visit;

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < cities.size(); ++i) {
		int x = cities[i][0];
		int y = cities[i][1];
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	if (c_lib <= c_road)
		return c_lib * n;

	// 백터를 넣을 스택 선언
	stack<vector<int>> st;

	int maxDist = 0;
	int countSeparateArea = 0;
	int cityDemendingRoad;
	vector<int> cur;
	while (true) {

		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (visit[i] == false) {
				visit[i] = true;
				
				if (graph[i].size() != 0)	// 새로만든 visit map 이라면 없을수 있다
				{
					st.push(graph[i]);
					++countSeparateArea;
				}
				else
					++countSeparateArea;
				flag = false;
				break;
			}
			// auto iter == visit.end())
		}
		// 스텍에 넣을 새로운 city 노드가 없는 경우
		if (flag == true)
		{
			cityDemendingRoad = n - countSeparateArea;
			return countSeparateArea * c_lib + cityDemendingRoad * c_road;
		}

		while (!st.empty()) {
			cur = st.top();
			st.pop();
			for (auto i : cur) {
				// 벡터 안에 값이 그래프에서 마킹한 곳이라면 push와 visit
				if (visit[i] == false) // map에 키가 없으면 false로 생성이 된다.
				{
					st.push(graph[i]);
					visit[i] = true;
					++maxDist;
				}
			}
		}

	}

	return countSeparateArea * c_lib + cityDemendingRoad * c_road;
}
int main()
{
	ofstream fout("result.txt");

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string nmC_libC_road_temp;
		getline(cin, nmC_libC_road_temp);

		vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

		int n = stoi(nmC_libC_road[0]);

		int m = stoi(nmC_libC_road[1]);

		int c_lib = stoi(nmC_libC_road[2]);

		int c_road = stoi(nmC_libC_road[3]);

		vector<vector<int>> cities(m);
		for (int i = 0; i < m; i++) {
			cities[i].resize(2);

			for (int j = 0; j < 2; j++) {
				cin >> cities[i][j];
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		long result = roadsAndLibraries(n, c_lib, c_road, cities);
		cout << result << "\n";
		fout << result << "\n";
	}

	fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
