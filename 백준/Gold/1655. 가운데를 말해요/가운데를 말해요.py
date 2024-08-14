import sys
input = sys.stdin.readline

import heapq

minq = []
maxq = []

N = int(input())
for i in range(N):
    num = int(input())
    
    if len(maxq) == len(minq):
        heapq.heappush(maxq, -num)
    else:
        heapq.heappush(minq, num)
    
    if minq and maxq and minq[0] < maxq[0]*-1:
        min = heapq.heappop(maxq) * -1
        max = heapq.heappop(minq)
        heapq.heappush(minq, min)
        heapq.heappush(maxq, max * -1)

    print(maxq[0]*-1)