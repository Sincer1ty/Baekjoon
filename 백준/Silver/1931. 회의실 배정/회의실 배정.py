import sys
input = sys.stdin.readline

N = int(input()) # 회의실 수

time = []
for _ in range(N):
    start, end = map(int, input().split())
    time.append([start, end])

time.sort()
time.sort(key=lambda x:x[1])

now_t = 0
count = 0
for s, e in time:
    if now_t <= s:
        now_t = e
        count+=1

print(count)
