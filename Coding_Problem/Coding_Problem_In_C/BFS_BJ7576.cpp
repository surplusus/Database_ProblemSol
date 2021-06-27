// baekjoon problem / 7576 
// �丶��

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
	// ���� ����ĭ n, ����ĭ m
	int m, n;
	cin >> m >> n;
	queue<pair<int, int>> tomato;
	// 2���� ���� ���� �Ҵ��� -1(�������丶��)�� �ʱ�ȭ
	vector<vector<int>> visit(n,(vector<int>(m,-1)));
	// �Է¹��� ��� box�� �ֱ�
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
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
		}
	}
	// ���������� ���� �丶�䰡 ���� ������
	
	// ����Ž��
	int nx, ny, ripeTomato, minDate;
	ripeTomato = minDate = 0;
	while (!tomato.empty())
	{
		// ������ ���� ���
		int x = tomato.front().second;
		int y = tomato.front().first;
		// ������ �ϳ��� ������
		tomato.pop();
		for (int i = 0; i < 4; i++)
		{
			// Ž�� ��ǥ
			nx = x + dx[i];
			ny = y + dy[i];
			// Ž�� ��ǥ(�����¿�)�� ���� ��? 
			if (0 <= nx && nx <= n && 0 <= ny && ny <= m)
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
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// ������ �丶�䰡 ���� �������� -1 ��� ����
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