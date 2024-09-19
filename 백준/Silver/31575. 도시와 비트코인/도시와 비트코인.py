import sys
input = sys.stdin.readline

N, M = map(int, input().split())

city = []
for _ in range(M):
    city.append(list(map(int, input().split())))

import queue

q = queue.Queue()

visited = []
for _ in range(M):
    visited.append([0] * N)

# 우, 하
dx = [0, 1]
dy = [1, 0]

def bfs(x, y):
    q.put([x, y])
    visited[x][y] = 1

    while q.qsize():
        pos = q.get()
        x = pos[0]
        y = pos[1]

        if x == M-1 and y == N-1:
            return 1
        for i in range(2):
            if x+dx[i] == -1 or y+dy[i] == -1 or x+dx[i] == M or y+dy[i] == N:
                continue
            if city[x+dx[i]][y+dy[i]] == 1 and visited[x+dx[i]][y+dy[i]] == 0:
                q.put([x+dx[i], y+dy[i]])
                visited[x+dx[i]][y+dy[i]] = 1
    return 0
            
if bfs(0, 0):
    print("Yes")
else:
    print("No")
