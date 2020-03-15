// baekjoon problem / 2667
// 단지번호붙이기 (BFS)
// 우선 벽(-1)을 만들어 N을 벗어나지 않게 한다.
// 1이 나오면 시작점으로 하려 BFS 시작
// visit에 1을 지워가면서 탐색
// 지울때마다 result++
// result 결과를 vector에 넣고 sort 하여 출력
// 반례 : 1이 홀로 있는 단지가 있을 수 있다

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