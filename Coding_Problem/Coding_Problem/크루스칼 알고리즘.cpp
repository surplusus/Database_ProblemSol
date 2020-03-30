#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using Node = tuple<int, int, int>;
using CMP = function<bool(const Node&, const Node&)>;
int node[10001];
int solution(int V, vector<vector<int>> cost)
{
	memset(node, 0, sizeof(node));
	int answer = 0;	// weight Sum
	//priority_queue < pair<int,pair<int, int>>>pq;
	CMP cmp = [](const Node& lhs, const Node& rhs) {
		return get<0>(lhs) < get<0>(rhs);
	};
	priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
	//priority_queue<Node, vector<Node>, less<Node>> pq;
	priority_queue<int> q;
	for (auto i : { 7,4,1,3,56,7,3,1,2 })
		q.push(i);
	for (int i = 0; i < cost.size(); i++)
	{
		int S, E, H;
		S = cost[i][0];
		E = cost[i][1];
		H = cost[i][2];
		//pq.push(make_pair(-H, make_pair(S, E)));
		pq.push(make_tuple(H, S, E));
	}

	for (int i = 0; i < V; i++)
	{
		node[i] = i;
	}
	//while (!pq.empty()) {
	//	cout << get<0>(pq.top()) << get<1>(pq.top())<< get<2>(pq.top()) << " ";
	//	pq.pop();
	//	cout << endl;
	//}
	//while (!q.empty()) {
	//	cout << q.top() << " ";
	//	q.pop();
	//	cout << endl;
	//}

	int p, c;

	while (!pq.empty()) {
		//int a = pq.top().second.first;
		//int b = pq.top().second.second;
		int a = get<1>(pq.top());
		int b = get<2>(pq.top());
		

		p = min(node[a], node[b]);
		c = max(node[a], node[b]);

		if (p == c) {
			pq.pop();
			continue;
		}

		for (int i = 1; i <= V; ++i) {
			if (node[i] == c) {
				node[i] = p;
			}
		}

		//answer += -pq.top().first;
		answer += get<0>(pq.top());
		pq.pop();
	}

	return answer;
}

bool isGraphConnected(vector<vector<int>>& G);
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
	cout << solution(3, ex) << endl;
	vector<vector<int>> ex4 = {
	{0,1, 0},
	{0,1, 0},
	{0,1, 0},
	};
	vector<vector<int>> ex5 = {
	{0,1},
	{1,0},
	};
	cout << isGraphConnected(ex4) << endl;
	cout << isGraphConnected(ex5) << endl;
	return 0;
}

