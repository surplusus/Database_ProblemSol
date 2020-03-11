// baekjoon problem / 2667 
// 단지번호붙이기

#include <iostream>
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
	int i = 0;
	for (auto & row : map)	// auto & 는 역으로 값을 넣을 수도 있다.
		for (auto & col : row)
		{
			char tmp;
			while (1)
			{
				tmp = getchar();
				if (tmp != '\n')
				{
					col = tmp - '0';
					break;
				}
			}
		}
}

bool IsInArea(int x, int y)
{
	if (x < 0 || y < 0 || x >= map.size() || y >= map.size())
		return false;
	else
		return true;
}

int DFS(int y, int x)
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
			if (map[i][j] == 1)
				rank.insert(DFS(i, j));
		}
	}

	cout << rank.size() << endl;
	for (auto i : rank)
		cout << i << endl;
	return 0;
}
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool check[30][30];
int n, arr[30][30], num[1010], cnt;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y) {
	check[x][y] = true;
	num[cnt]++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (!check[nx][ny] && arr[nx][ny]) dfs(nx, ny);
		}
	}
}
int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %1d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j] && arr[i][j]) dfs(i, j), cnt++;
		}
	}
	printf("%d\n", cnt);
	sort(num, num + cnt);
	for (int i = 0; i < cnt; i++) printf("%d\n", num[i]);
}
*/
