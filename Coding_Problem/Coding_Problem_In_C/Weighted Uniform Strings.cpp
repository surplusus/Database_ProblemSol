// HackerRank problem 
// Weighted Uniform Strings

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> weightedUniformStrings(string s, vector<int> queries) {
	vector<int> v_str;
	vector<string> result;
	vector<int> v_comp;
	int idx = 0;
	while (idx < s.length())
		v_str.push_back(s[idx++] - 'a' + 1);
	v_str.push_back(-1);

	int plus = 0;
	for (int i = 0; i < s.length(); i++)
	{
		plus += v_str[i];
		v_comp.push_back(plus);
		if (v_str[i] != v_str[i + 1])
		{
			plus = 0;
		}
	}

	for (int i = 0; i < queries.size(); ++i)
	{
		if (find(v_comp.begin(), v_comp.end(), queries[i]) != v_comp.end())
			result.push_back("Yes");
		else
			result.push_back("No");
	}
	return result;
}

int main()
{

	string s;
	getline(cin, s);

	int queries_count;
	cin >> queries_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> queries(queries_count);

	for (int i = 0; i < queries_count; i++) {
		int queries_item;
		cin >> queries_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		queries[i] = queries_item;
	}

	vector<string> result = weightedUniformStrings(s, queries);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];

		if (i != result.size() - 1) {
			cout << "\n";
		}
	}

	cout << "\n";

	return 0;
}