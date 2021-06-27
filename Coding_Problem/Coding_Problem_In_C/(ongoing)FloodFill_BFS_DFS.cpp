// Flood Fill
// https://trello-attachments.s3.amazonaws.com/5d3670afb1d231324efa90cc/5e78e425b923f41887dd0b4a/e60681e1ee09a9d31ca516743e27883c/Recursive_Flood_Fill.gif
// 주어진 좌표와 같은 색의 주변을 탐색하여
// 조건에 맞으면 색을 바꿈
// BFS 또는 DFS로 구현 가능

#include <iostream>
#include <cstring>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <algorithm>
#include <functional>
#define MAX 101
#define INF 987654321
using namespace std;
using Point = vector<int>;
int visit[MAX][MAX];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
void MakeItDiamond_DFS(Point pos, vector<vector<int>>& map)
{
	int cr = pos[0];
	int cc = pos[1];
	visit[cr][cc] = true;
	map[cr][cc] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nr = cr + dr[i];
		int nc = cc + dc[i];
		//int nr = -1;
		//int nc = 0;
		bool flag = false;
		flag |= nr < 0 || nc < 0;
		flag |= nr >= map.size() || nc >= map.size();
		if (flag)
			continue;
		if (!visit[nr][nc] && map[nr][nc] == 0) {
			visit[nr][nc] = true;
			map[nr][nc] = 1;
			MakeItDiamond_DFS({ nr,nc }, map);
		}
	}
}

void printMap(vector<vector<int>> m)
{
	for (const auto& it : m)
	{
		for (const auto& jt : it)
		{
			if (jt == -1)		cout << "■";
			else if (jt == 0)	cout << "□";
			else if (jt == 1)	cout << "◆";
		}
		cout << endl;
	}
}

int main()
{
	vector<vector<int>> map1 =
	{
		{0,0,0,-1,0,0,0},
		{0,0,0,-1,0,0,0},
		{0,0,-1,0,0,0,0},
		{-1,-1,0,0,0,-1,-1},
		{0,0,0,0,-1,0,0},
		{0,0,0,-1,0,0,0},
		{0,0,0,-1,0,0,0},
	};
	printMap(map1);
	cout << endl;
	memset(visit, false, sizeof(visit));
	MakeItDiamond_DFS({ 3,3 }, map1);
	printMap(map1);
	return 0;
}