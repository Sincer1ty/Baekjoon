import sys
input = sys.stdin.readline

N = int(input())

size = []
for _ in range(N):
    size.append(list(map(int, input().split())))

matrix = [[0] * N for _ in range(N)]

for _ in range(1, N):
    for i in range(N-_):
        j= i+_
        matrix[i][j] = float('inf')  # 초기값을 무한대로 설정
        for k in range(i, j):
            cost = matrix[i][k] + matrix[k+1][j] + size[i][0] * size[k][1] * size[j][1]
            matrix[i][j] = min(matrix[i][j], cost)

print(matrix[0][N-1])
