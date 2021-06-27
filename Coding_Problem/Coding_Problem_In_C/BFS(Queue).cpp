#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 10; // �� �� ��
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0,1,0,-1 };
int group_id;
int group[MAX_SIZE * MAX_SIZE]
int map[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];

void bfs(int x, int y) {

	queue< pair<int, int> > q; // �̿��� ť, (x,y) -> (��, ��)
	q.push(make_pair(x, y)); // pair�� ���� queue�� �ֽ��ϴ�.

	// ó�� x,y�� �湮 �߱⶧����
	visited[x][y] = true;
	groups[group_id]++;

	while (!q.empty()) {

		// ť�� ���� ���Ҹ� ������
		x = q.front().first;
		y = q.front().second;
		q.pop();

		// �ش� ��ġ�� �ֺ��� Ȯ��
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// ������ ����� �ʰ�
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				// ���̸鼭 �湮���� �ʾҴٸ� -> �湮
				if (map[nx][ny] == 1 && visited[nx][ny] == false) {
					visited[nx][ny] = true;

					// �ش� ������ ���� ���� ������Ŵ
					groups[group_id]++;

					// ť�� ���� nx,ny�� �߰�
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}