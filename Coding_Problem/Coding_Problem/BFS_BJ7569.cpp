// baekjoon problem / 7569
// 토마토2 (BFS)(3차원 배열 사용)
// 벽을 따로 만들지 않고 -1로 만든다
// 안 익은 토마토(cntUnripe)를 새어 놓고
// 익은 토마토 주변으로 BFS하면서 익은 토마토로 바꿔놓고 안 익은 토마토를 지운다
// 처음 익은 토마토가 존재하지 않으면 -1
// 마지막에 BFS를 끝났음에도 안 익은 토마토가 존재하면 갈 수없는 경로가 있는 것으로 -1
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 101
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };
int map[MAX][MAX][MAX];
int N, M, H;
int cntUnripe = 0;	// 아직 안 익은 토마토의 갯수
typedef struct _coord
{
	int n, m, h;
	_coord() : n(0), m(0), h(0) {}
	_coord(int _n, int _m, int _h) : n(_n), m(_m), h(_h) {}
} Coord;
queue<Coord> que;

void BFS()
{
	int n, m, h;
	int day = 0;
	
	if (cntUnripe == 0)
	{
		cout << 0 << endl;
		return;
	}
	if (que.empty())
	{
		cout << -1 << endl;
		return;
	}

	queue<Coord> backQue;
	while(true)
	{
		while (!que.empty())
		{
			n = que.front().n;	m = que.front().m;	h = que.front().h;
			que.pop();

			for (size_t i = 0; i < 6; i++)
			{
				int cn = n + dx[i];	int cm = m + dy[i];	int ch = h + dh[i];
				if (cn < 0 || cm < 0 || ch < 0 || cn >= N || cm >= M || ch >= H) // 범위를 벗어나면 continue
					continue;
				if (map[cn][cm][ch] == 0) // -1 : 토마토가 없는곳 // 1 : 익은 토마토 // 0 : 안 익은 토마토
				{
					backQue.push(Coord(cn, cm, ch));
					map[cn][cm][ch] = 1;
					cntUnripe--;
				}
			}
		}
		if (backQue.empty())
			break;
		que.swap(backQue);
		day++;
	}

	if (cntUnripe > 0)
		cout << -1 << endl;
	else
		cout << day << endl;
}

int main()
{
	cin >> N >> M >> H;
	memset(map, -1, sizeof(map));
	for (size_t h = 0; h < H; h++)
	{
		for (size_t m = 0; m < M; m++)
		{
			for (size_t n = 0; n < N; n++)
			{
				int inp;
				cin >> inp;
				if (inp == 0)
					cntUnripe++;
				map[n][m][h] = inp;
				if (inp == 1)
					que.push(Coord(n, m, h));
			}
		}
	}

	BFS();
	return 0;
}