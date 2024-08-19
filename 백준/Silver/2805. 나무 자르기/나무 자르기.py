import sys
input = sys.stdin.readline

# 나무의 수, 가져가려는 나무의 길이
N, M = map(int, input().split())

height = list(map(int, input().split()))

maxH = max(height)
minH = 0
m = 0
H = -1
while m != M:
    preH = H
    H = (minH + maxH) // 2
    if H == preH:
        break
    
    m = 0
    for h in height:
        if h-H > 0:
            m += h-H
            
    if m > M:
        minH = H
    else : # 작으면
        maxH = H
    
print(H)
