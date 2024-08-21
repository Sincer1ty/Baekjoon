import sys
input = sys.stdin.readline

# 집 N개, 공유기 C개
N, C = map(int, input().split())

home = []
for _ in range(N):
    home.append(int(input()))

home.sort()

def can_place_routers(distance):
    count = 1  # 첫 번째 집에 공유기 설치
    last_position = home[0]
    
    for i in range(1, N):
        if home[i] - last_position >= distance:
            count += 1
            last_position = home[i]
            if count == C:
                return True
    return False

# 이분 탐색으로 최소 거리의 최댓값을 찾음
left, right = 1, home[-1] - home[0]
result = 0

while left <= right:
    mid = (left + right) // 2
    if can_place_routers(mid):
        result = mid
        left = mid + 1
    else:
        right = mid - 1

print(result)
