// baekjoon problem / 2667
// ������ȣ���̱� (BFS)
// �켱 ��(-1)�� ����� N�� ����� �ʰ� �Ѵ�.
// 1�� ������ ���������� �Ϸ� BFS ����
// visit�� 1�� �������鼭 Ž��
// ���ﶧ���� result++
// result ����� vector�� �ְ� sort �Ͽ� ���
// �ݷ� : 1�� Ȧ�� �ִ� ������ ���� �� �ִ�

#include <iostream>
#include <cstring>	// memset
#include <queue>
#include <vector>
#include <algorithm> // sort
using namespace std;

#define MAX 26

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0, 1,-1,0 };
int visit[MAX][MAX];

int BFS(int r, int c)
{
	int result = 1;
	queue<pair<int,int>> que;
	que.push(make_pair(r, c));
	visit[r][c] = 0;
	while (!que.empty())
	{
		int cr = que.front().first;
		int cc = que.front().second;
		que.pop();
		for (size_t i = 0; i < 4; i++)
		{
			int nr = cr + dy[i];
			int nc = cc + dx[i];
			if (visit[nr][nc] == 1)
			{
				visit[nr][nc] = 0;
				que.push(make_pair(nr, nc));
				result++;
			}
		}
	}
	return result;
}

int main()
{
	memset(visit, -1, sizeof(visit));
	int N;
	cin >> N;
	for (size_t i = 1; i <= N; i++)
	{
		string input;
		cin >> input;
		for (size_t j = 1; j <= N; j++)
		{
			visit[i][j] = input[j-1] - '0';
		}
	}
	vector<int> result;
	for (size_t r = 1; r <= N; r++)
	{
		for (size_t c = 1; c <= N; c++)
		{
			if (visit[r][c] == 1) {
				result.push_back(BFS(r,c));
			}
		}
	}
	cout << result.size();
	sort(result.begin(), result.end());
	for (auto it : result) {
		cout << endl;
		cout << it;
	}

	return 0;
}