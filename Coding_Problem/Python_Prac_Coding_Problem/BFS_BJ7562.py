## baekjoon problem / 2931
## 나이트의 이동(BFS)
from sys import stdin
from collections import deque

input = stdin.readline

dx = (-2,-1,1,2,2,1,-1,-2)
dy = (1,2,2,1,-1,-2,-2,-1)

def BFS():
    que = deque()
    que.append((sx, sy))
    
    while que:
        cx, cy = que.popleft()

        if cx == ex and cy == ey:
            print(visit[cy][cx])
            return

        for i in range(8):
            nx, ny = cx+dx[i], cy+dy[i]
            if nx < 0 or nx >= I or ny < 0 or ny >= I:
                continue
            if not visit[ny][nx]:
                visit[ny][nx] = visit[cy][cx] + 1
                que.append((nx,ny))

for _ in range(int(input())):
    I = int(input())
    sx, sy = map(int, input().split())
    ex, ey = map(int, input().split())
    visit = [[0] * I for _ in range(I)]
    BFS()
