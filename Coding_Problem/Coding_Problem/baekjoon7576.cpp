// baekjoon problem / 7576 
// �丶��

#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int box[1001][1001];
int visit[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
	// ���� ����ĭ m, ����ĭ n
	int m, n;
	cin >> m >> n;
	queue<pair<int, int>> tomato;
	// �Է¹��� ��� box�� �ֱ�
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> box[i][j];
			// ���� �丶��(1) ������
			if (box[i][j] == 1)
			{
				// �丶�� ť�� �ְ�
				tomato.push(make_pair(i, j));
				// ���� �丶�� �ִ°�(��� ���� ���¸� 0)
				visit[i][j] = 0;
			}
			// ���ڰ� ��������� �湮����
			else if (box[i][j] == -1)
				visit[i][j] = 0;
			else
				visit[i][j] = -1;
		}
	}
	// ���������� ���� �丶�䰡 ���� ������
	
	// ����Ž��
	int nx, ny, ripeTomato, minDate;
	ripeTomato = minDate = 0;
	while (!tomato.empty())
	{
		// ������ ���� ���
		int y = tomato.front().first;
		int x = tomato.front().second;
		// ������ �ϳ��� ������
		tomato.pop();
		for (int i = 0; i < 4; i++)
		{
			// Ž�� ��ǥ
			ny = y + dy[i];
			nx = x + dx[i];
			// Ž�� ��ǥ(�����¿�)�� ���� ��? 
			if (0 <= nx && nx <= m && 0 <= ny && ny <= n) // ����ĭ m, ����ĭ n
				// Ž�� ��ǥ�� ������ �丶��?(box 0,visit -1)
				// box -1 : �丶�� ���� / visit 0 :���� �丶��)
				if (box[ny][nx] == 0 && visit[ny][nx] == -1)
				{
					// visit ǥ��
					visit[ny][nx] = visit[y][x] + 1;
					// ������ �ֺ��� ���� �;����� ť�� �ֱ�
					tomato.push(make_pair(ny, nx));
				}
		}
		minDate++;
	}
	
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// ������ �丶�䰡 ���� �������� -1 ��� ����
			if (box[i][j] == 0 && visit[i][j] == -1)
			{
				cout << -1;
				return 0;
			}
			result = max(result, visit[i][j]);
		}
	}
	cout << result;
	return 0;
}