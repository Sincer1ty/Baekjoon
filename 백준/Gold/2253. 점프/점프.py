import sys
input = sys.stdin.readline
N, M = map(int, input().split()) # N : 총 돌수, M : 장애물 돌 수

obstacle = []
for _ in range(M):
    obstacle.append(int(input()))

def sum(n):
    result = 0 
    for i in range(1, n):
        result+=i
        if n<=result:
            return i

normalSpeed = sum(N)

matrix = [[float('inf')] * (normalSpeed+2) for _ in range(N+1)]
matrix[1][0] = 0

for i in range(2, len(matrix)):
    if i in obstacle:
        continue
    for v in range(1, normalSpeed+1):
        matrix[i][v] = min(matrix[i-v][v-1],matrix[i-v][v],matrix[i-v][v+1]) +1

answer = min(matrix[N])
if answer == float('inf'):
    print(-1)
else:
    print(answer)
