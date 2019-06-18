// baekjoon problem / 2667 
// 단지번호붙이기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visit;
void InitMap()
{
	int size;
	cin >> size;
	map = vector<vector<int>>(size, vector<int>(size));
	// bool 형은 기본생성자에 false가 들어간다.
	visit = vector<vector<bool>>(size, vector<bool>(size));
	// range-based loop 이용 값 입력
	for (auto & row : map)	// auto & 는 역으로 값을 넣을 수도 있다.
		for (auto & col : row)
			cin >> col;
}

bool IsInArea(int x, int y)
{
	if (x < 0 || y < 0 || x >= map.size() || y >= map.size())
		return false;
	else
		return true;
}

int DFS(int x, int y)
{
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int dist = 0;
	visit[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (IsInArea(nx, ny) && visit[ny][nx] == false && map[ny][nx] == 1)
		{
			dist = max(dist, 1 + DFS(nx, ny));
		}
	}
	visit[y][x] = false;
	return dist;
}
int main()
{
	InitMap();

	set<int> rank;

	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map.size(); j++)
		{
			rank.insert(DFS(i, j));
		}
	}
	return 0;
}