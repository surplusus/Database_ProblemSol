// baekjoon problem / 1753 
// 최단경로

#include <iostream>
#include <vector>
//#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
int V, E, K;
int u, v, w;
const int INF = 987654321;
const int MAX_V = 20001;
//const int MAX_E = 300001;
typedef pair<int, int> Node;	// pair<cost, index>
vector<Node> edge[MAX_V];	// edge weight
int dist[MAX_V];	// distance from startPoint(K)

struct cmp {
	bool operator()(Node x, Node y) {
		return x.first > y.first;	// 부등호 위치에 주의
	}
};


void dijkstra()
{
	//fill(&dist[0], &dist[MAX_V], INF);
	//dist.resize(MAX_V, INF);
	for (int i = 1; i <= V; i++)
		dist[i] = INF;
	
	dist[K] = 0;

	// cmp가 없으면 pair.first 기준으로 찾는다
	// 하지만 pair.first가 같으면 같은 pair.second기준으로 정렬한다. 
	// 이 문제에서 원하는건 무조건 cost기준으로 뽑는것이 효율적이므로 cmp 꼭 만들어야됨
	priority_queue<Node, vector<Node>, cmp> que; 
	que.push({ 0,K });

	while (!que.empty())
	{
		int curCost = que.top().first;
		int curNode = que.top().second;
		que.pop();

		if (dist[curNode] < curCost)
			continue;

		for (int i = 0; i < edge[curNode].size(); ++i)
		{
			int nextNode = edge[curNode][i].second;
			int nextCost = curCost + edge[curNode][i].first;

			if (dist[nextNode] > nextCost)
			{
				dist[nextNode] = nextCost;
				que.push({ nextCost, nextNode });
			}
		}
	}

	for (int i = 1; i <= V; ++i)
	{
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false); // iostream을 stdio.h와 동기화시킴
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		edge[u].push_back(Node{ w, v });
	}
	
	dijkstra();

	return 0;
}