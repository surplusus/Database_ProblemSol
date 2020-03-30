#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define MAX 1001
#define INF 987654321
using namespace std;

vector<pair<int, int>> v[MAX];
vector<int> map;

vector<int> dijkstra(int V)
{
	//vector<int> map = vector<int>(V + 1, INF);
	vector<int> map;
	map.assign(V + 1, INF);
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 1));
	map[1] = 0;

	while (!pq.empty())
	{
		int top = pq.top().second;			//top
		int top_weight = pq.top().first;	//weight
		pq.pop();

		if (map[top] < top_weight)
			continue;

		for (int i = 0; i < v[top].size(); i++)
		{
			int cur = v[top][i].first;
			int weight = v[top][i].second - top_weight;

			if (map[cur] > weight)
			{
				map[cur] = weight;
				pq.push(make_pair(-weight, cur));
			}
		}
	}
	return map;
}

int solution(int V, vector<vector<int>> cost)
{
	int answer = 0;
	for (int i = 0; i < cost.size(); i++)
	{
		int S, E, H;
		S = cost[i][0];
		E = cost[i][1];
		H = cost[i][2];
		v[S].push_back(make_pair(E, H));
	}

	map = dijkstra(V);

	for (int i = 1; i <= V; i++)
	{
		/*if (answer < map[i])
			answer = map[i];*/
		answer += map[i];
	}

	return answer;
}

int main()
{
	vector<vector<int>> ex = {
		{1,2,2},
		{1,3,1},
		{2,3,1},
	};
	vector<vector<int>> ex2 = {
		{1,2,1},
	{1,3,1},
	{1,4,2},
	{2,5,3},
	{3,4,2},
	{4,5,3},
	};
	vector<vector<int>> ex3 = {
	{1,2,2},
	{1,3,2},
	{1,4,55},
	{2,5,55},
	{3,4,1},
	{4,5,1},
	};
	cout << solution(5, ex2) << endl;
	return 0;
}