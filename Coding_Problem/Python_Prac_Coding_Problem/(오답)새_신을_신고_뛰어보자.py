N = int(input())
M = [[] * N for i in range(N)]
for i in range(N):
    M[i] = list(map(int, input().split()))

result = 0
visit = []

def DFS(r, c, visit):
    global result
    global N
    cur = int(M[r][c])
    if r == N -1 and c == N -1:
        visit.append([r,c])
        result += 1
    elif cur > 0:
        if r + cur < N:
            visit.append([r,c])
            DFS(r + cur, c, visit)
        if c + cur < N:
            visit.append([r,c])
            DFS(r, c + cur, visit)

DFS(0,0, visit)
print(result)
for i in visit:
    print(i[0], i[1])