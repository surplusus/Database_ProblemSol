#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 10; // Çà ¿­ ¼ö
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0,1,0,-1 };
int group_id; 
int group[MAX_SIZE * MAX_SIZE]
int map[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];


void DFS_recursion(int x, int y) {
	visit[x][y] = true;
	group[group_id]++;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (map[nx][ny] == 1 && visit[nx][ny] == false){
			DFS_recursion(nx, ny);
			}
		}
	}
}