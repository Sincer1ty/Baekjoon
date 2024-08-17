import sys
input = sys.stdin.readline

# 수열의 크기
N = int(input())

A = list(map(int, input().split()))

stk = []
result = [-1 for _ in range(N)]

for i in range(N):
    while stk and A[stk[-1]] < A[i]:
        result[stk.pop()] = A[i]

    stk.append(i)

print(*result)
