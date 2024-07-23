import sys
input = sys.stdin.readline
N, K = map(int, input().split())

products = []
for _ in range(N):
    products.append(list(map(int, input().split())))

matrix = [[0] * (K+1) for _ in range(N+1)]

for i in range(1, len(matrix)):
    w = products[i-1][0]
    v = products[i-1][1]
    for j in range(1, len(matrix[i])):
        if w <= j:
            matrix[i][j] = max(matrix[i-1][j-w] + v, matrix[i-1][j])
        else:
            matrix[i][j] = matrix[i-1][j]

print(matrix[N][K])
