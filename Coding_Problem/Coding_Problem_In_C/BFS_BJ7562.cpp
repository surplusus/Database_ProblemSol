// baekjoon problem / 2931
// 나이트의 이동(BFS)

#include<iostream>
#include<queue>
#include<vector>
#include<cstring>	//memset
#define MAX 300
using namespace std;

bool visit[MAX][MAX];
int I;	// 체스판의 크기
//int dx[] = { -1,-2,-2,-1,1,2,2,1 };
//int dy[] = { -2,-1,1,2,2,1,-1,-2 };

typedef struct _coord
{
	int x;
	int y;
	int t;
 //   explicit _coord(int _x, int _y, int _t) : x(_x), y(_y), t(_t) {}
	//explicit _coord(int _x, int _y) : x(_x), y(_y), t(0) {}
	//explicit _coord() : x(0), y(0), t(0) {}
} Coord;
Coord Start, End;
Coord dir[8] = {
	{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}
};

void Input()
{
	cin >> I;
	cin >> Start.x >> Start.y;
	cin >> End.x >> End.y;
}

void BFS(int sx, int sy)
{
	memset(visit, false, sizeof(visit));
	queue<Coord> que;
	Coord nCoord;
	nCoord.x = sx; nCoord.y = sy; nCoord.t = 0;
	que.push(nCoord);
	visit[sy][sx] = true;

	while (!que.empty())
	{
		int cy = que.front().y;
		int cx = que.front().x;
		int time = que.front().t;
		que.pop();

		if (cy == End.y && cx == End.x) {
			cout << time << endl;
			break;
		}
		for (size_t i = 0; i < 8; i++)
		{
			int ny = cy + dir[i].y;
			int nx = cx + dir[i].x;
			
			if (ny < 0 || ny >= I || nx < 0 || nx >= I)
				continue;
			if (visit[ny][nx])
				continue;

			visit[ny][nx] = true;
			Coord nC; nC.x = nx; nC.y = ny; nC.t = time + 1;
			que.push(nC);
		}
	}
}

int main(void)
{
	int N;
	cin >> N;
	while (N--)
	{
		Input();
		BFS(Start.x, Start.y);
	}
	return 0;
}