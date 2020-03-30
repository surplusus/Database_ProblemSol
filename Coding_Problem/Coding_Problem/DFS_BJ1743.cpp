// baekjoon problem / 1743
// ���Ĺ� ������(BFS/DFS)
// BFS�� DFS�� ������ Ǯ �� �ִ�
// ��¶�� map ������ �˻��ؾ��ϹǷ� DFS�� Ǯ����
// main���� ������ Ž������ �ʾҰ� �����Ⱑ ������ DFS �Լ��� �θ���
// DFS�� �Բ� cnt�� �Ѱ��ش� (ó�� �ҷ����� ���� �����Ѵ�)

#include <iostream>
#include <cstring>
#include <vector>
#include <cstring>
#include <tuple>
#include <algorithm>
#include <functional>
#define MAX 101
#define INF 987654321
using namespace std;
using Node = tuple<int, int>;
bool map[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
vector<Node> trash;
int result, N, M, K;

void DFS(Node v, int& cnt)
{
	int r = get<0>(v);
	int c = get<1>(v);
	visit[r][c] = true;
	cnt++;

	for (int i = 0; i < 4; ++i)
	{
		int nr = r + dy[i];
		int nc = c + dx[i];
		if (nr <= 0 || nc <= 0 || nr > N || nc > M)
			continue;
		if (!visit[nr][nc] && map[nr][nc] == true)
		{
			visit[nr][nc] = true;
			DFS(Node(nr, nc), cnt);
		}
	}
}

int main()
{
	//cin >> N >> M >> K;
	//memset(map, false, sizeof(map));
	//memset(visit, false, sizeof(visit));
	//while (K--)
	//{
	//	int r, c;
	//	cin >> r >> c;
	//	map[r][c] = true;
	//	trash.emplace_back(r, c);
	//}
	N = 3; M = 4; K = 5;
	vector<vector<int>> ex =
	{
		{3,2},
		{2,2},
		{3,1},
		{2,3},
		{1,1},
	};
	for (size_t i = 0; i < K; i++)
	{
		int r = ex[i][0];
		int c = ex[i][1];
		map[r][c] = true;
		trash.emplace_back(r, c);
	}
	result = 0;
	for (size_t i = 0; i < trash.size(); i++)
	{
		int r, c;
		tie(r, c) = trash[i];
		if (!visit[r][c])
		{
			int cnt = 0;
			DFS(trash[i], cnt);
			result = max(cnt, result);
		}
	}
	cout << result << endl;
	return 0;
}