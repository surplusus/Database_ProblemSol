// baekjoon problem / 7576 
// 토마토

#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int box[1001][1001];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
	// 상자 가로칸 n, 세로칸 m
	int m, n;
	cin >> m >> n;
	queue<pair<int, int>> tomato;
	// 2차원 백터 동적 할당후 -1(안익은토마토)로 초기화
	vector<vector<int>> visit(n,(vector<int>(m,-1)));
	// 입력받은 대로 box에 넣기
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> box[i][j];
			// 익은 토마토(1) 있으면
			if (box[i][j] == 1)
			{
				// 토마토 큐에 넣고
				tomato.push(make_pair(i, j));
				// 익은 토마토 있는곳(모두 익은 상태면 0)
				visit[i][j] = 0;
			}
			// 상자가 비어있으면 방문포기
			else if (box[i][j] == -1)
				visit[i][j] = 0;
		}
	}
	// 여러군데서 익은 토마토가 있을 수있음
	
	// 완전탐색
	int nx, ny, ripeTomato, minDate;
	ripeTomato = minDate = 0;
	while (!tomato.empty())
	{
		// 꺼내기 전에 기록
		int x = tomato.front().second;
		int y = tomato.front().first;
		// 익은건 하나씩 꺼낸다
		tomato.pop();
		for (int i = 0; i < 4; i++)
		{
			// 탐색 좌표
			nx = x + dx[i];
			ny = y + dy[i];
			// 탐색 좌표(상하좌우)가 상자 안? 
			if (0 <= nx && nx <= n && 0 <= ny && ny <= m)
				// 탐색 좌표에 안익은 토마토?(box 0,visit -1)
				// box -1 : 토마토 없음 / visit 0 :익은 토마토)
				if (box[ny][nx] == 0 && visit[ny][nx] == -1)
				{
					// visit 표시
					visit[ny][nx] = visit[y][x] + 1;
					// 익은거 주변은 이제 익었으니 큐에 넣기
					tomato.push(make_pair(ny, nx));
				}
		}
		minDate++;
	}
	
	int result = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// 덜익은 토마토가 아직 남았으면 -1 출력 끝냄
			if (box[i][j] == 0 && visit[i][j] == -1)
			{
				cout << -1;
				return 0;
			}
			result += max(result, visit[i][j]);
		}
	}
	cout << result;
	return 0;
}