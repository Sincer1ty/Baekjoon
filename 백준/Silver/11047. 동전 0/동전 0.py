import sys
input = sys.stdin.readline

N, K = map(int, input().split())

coin = []
for _ in range(N):
    coin.append(int(input()))

coin.reverse()

count = 0
for c in coin:
    if c > K:
        continue
    count += K // c
    K %= c

print(count)