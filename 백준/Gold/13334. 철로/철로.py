import heapq
import sys
input = sys.stdin.readline

n = int(input())

trail = []
for _ in range(n):
    home, office = map(int, input().split())
    if home > office:
        home, office = office, home
    trail.append([home, office])

# 끝점 기준으로 정렬
trail.sort(key=lambda x: x[1])

# 철로의 길이 : d
d = int(input())

result = 0
startPoints = []
count = 0
for home, office in trail:
    trailS = office - d
    trailE = office

    # 집 & 사무실 모두 철로에 포함되는 최대 사람 수 구하기
    while startPoints and startPoints[0] < trailS:
        heapq.heappop(startPoints)
        count -=1

    if office - home <= d:
        heapq.heappush(startPoints, home)
        count +=1

    if result < count:
        result = count

print(result)
