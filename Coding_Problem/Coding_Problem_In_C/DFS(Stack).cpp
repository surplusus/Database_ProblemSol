#include <iostream>
#include <string>
#include <stack>
using namespace std;

const int MAX_SIZE = 10; // �� �� ��
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

		// ������ top ���� ������
		x = s.top().first;
		y = s.top().second;
		s.pop();

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

					s.push(make_pair(x, y)); // push�ϴ� ����̱� ������ ���� ��ġ�� �־��ش�.
					s.push(make_pair(nx, ny)); // ���ÿ� ���� nx,ny�� Ǫ��
				}
			}
		}
	}
}