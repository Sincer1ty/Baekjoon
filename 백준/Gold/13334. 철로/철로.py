import sys
import heapq

input = sys.stdin.readline

n = int(input())

trails = []
for _ in range(n):
    home, office = map(int, input().split())
    trails.append((min(home, office), max(home, office)))

d = int(input())

trails.sort(key=lambda x: x[1])  # 끝점 기준으로 정렬

result = 0
start_points = []
count = 0

for end in trails:
    while start_points and start_points[0] < end[1] - d:
        heapq.heappop(start_points)
        count -= 1
    
    if end[1] - end[0] <= d:
        heapq.heappush(start_points, end[0])
        count += 1
    
    result = max(result, count)

print(result)