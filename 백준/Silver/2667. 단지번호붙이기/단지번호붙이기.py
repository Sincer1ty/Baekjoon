import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
home = [list(map(int, input().rstrip())) for _ in range(N)]

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

def bfs(x, y):
    q = deque([(x, y)])
    home[x][y] = 0  # 방문한 집은 0으로 표시
    count = 1

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < N and 0 <= ny < N and home[nx][ny] == 1:
                home[nx][ny] = 0
                q.append((nx, ny))
                count += 1
    return count

complex_counts = []
for i in range(N):
    for j in range(N):
        if home[i][j] == 1:
            complex_counts.append(bfs(i, j))

complex_counts.sort()  # 오름차순 정렬

print(len(complex_counts))
for count in complex_counts:
    print(count)