#include <iostream>
#include <string>
#include <stack>
using namespace std;

const int MAX_SIZE = 10; // 행 열 수
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0,1,0,-1 };
int group_id;
int group[MAX_SIZE * MAX_SIZE]
int map[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];

void DFS_stack(int x, int y) {
	stack<pair<int, int> > s;
	s.push({ x,y });

	groups[group_id]++;

	while (!s.empty()) {

		// 스택의 top 원소 꺼내기
		x = s.top().first;
		y = s.top().second;
		s.pop();

		// 해당 위치의 주변을 확인
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 지도를 벗어나지 않고
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				// 집이면서 방문하지 않았다면 -> 방문
				if (map[nx][ny] == 1 && visited[nx][ny] == false) {
					visited[nx][ny] = true;

					// 해당 단지의 집의 수를 증가시킴
					groups[group_id]++;

					s.push(make_pair(x, y)); // push하는 경우이기 때문에 현재 위치도 넣어준다.
					s.push(make_pair(nx, ny)); // 스택에 현재 nx,ny도 푸시
				}
			}
		}
	}
}