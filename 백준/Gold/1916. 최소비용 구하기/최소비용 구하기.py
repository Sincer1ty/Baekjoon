import sys
import heapq

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())

# 노드 별 경로 초기화
vertex =[None]
adj = {}
q = []
for n in range(N):
    vertex.append(10**8)
    adj[n+1] = []

for m in range(M):
    u, v, w = list(map(int, sys.stdin.readline().split()))
    adj[u].append((v, w))

start, dest = list(map(int, sys.stdin.readline().split()))

vertex[start] = 0

for n in range(N):
    heapq.heappush(q, [vertex[n+1], n+1])

while len(q):
    u = heapq.heappop(q)

    for a in adj[u[1]]:

        if vertex[a[0]] > vertex[u[1]]+a[1]:
            vertex[a[0]] = vertex[u[1]]+a[1]
            for h in q:
                if h[1] == a[0]:
                    h[0] = vertex[a[0]]
    heapq.heapify(q)

print(vertex[dest])
