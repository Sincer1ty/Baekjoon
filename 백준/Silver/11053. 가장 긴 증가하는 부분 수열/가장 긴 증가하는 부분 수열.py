import sys
input = sys.stdin.readline

N = int(input())
seq = list(map(int, input().split()))

sSeq = list(sorted(set(seq)))

matrix = [[0]*(N+1) for _ in range(len(sSeq)+1)]

for i in range(1, len(sSeq)+1):
    for j in range(1, N+1):
        if seq[j-1] == sSeq[i-1]:
            matrix[i][j] = matrix[i-1][j-1] + 1
        else:
            matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j])

print(matrix[len(sSeq)][N])