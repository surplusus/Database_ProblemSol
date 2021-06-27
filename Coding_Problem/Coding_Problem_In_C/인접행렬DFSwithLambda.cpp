// ������������� DFS
// ��� �׷����� ����Ǿ� �ִ��� Ȯ��
// DFS �Լ��� ���ٷ� ����

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
using Point = vector<int>;
int nV, nE;
int map[MAX][MAX];

bool isGraphConnected(vector<vector<int>>& G)
{
	vector<bool> visit(G.size(), false);
	function<void(int)> dfs = [&](int i) {
		visit[i] = true;
		for (int j = 0; j < nV; j++)
		{
			if (G[j][i] == 1 && !visit[j])
			{
				cout << i << "���� " << j << "�� �̵�\n";
				dfs(j);
			}
		}
	};
	dfs(0);
	for (size_t i = 0; i < G.size(); ++i)
		if (!visit[i])	return false;
	return true;
}

int main()
{
	vector<vector<int>> direction =
	{
		{0,1,1,0,0},
		{1,0,1,1,0},
		{1,1,0,1,1},
		{0,1,1,0,1},
		{0,0,1,1,0},
	};
	vector<vector<int>> indirection =
	{
		{1,2},
		{1,3},
		{2,3},
		{2,4},
		{3,4},
	};
	nV = 5;	nE = 5;
	cout << isGraphConnected(direction) << endl;
	cout << bool(isGraphConnected(indirection)) << endl;
	return 0;
}