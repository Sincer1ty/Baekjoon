from queue import Queue
import sys
input = sys.stdin.readline

N, M, K, X = list(map(int, input().split()))

adj = {}
distance = [None]
for n in range(N):
    adj[n+1] = []
    distance.append(10**8)

for m in range(M):
    u, v = list(map(int, input().split()))
    adj[u].append(v)

q = Queue()
def dijkstra():
    distance[X] = 0

    q.put(X)

    while q.qsize():
        v = q.get()

        for a in adj[v]:
            if distance[a] > distance[v]+1:
                distance[a] = distance[v]+1
                q.put(a)

dijkstra()

if K in distance:
    for i in range(1, N+1):
        if distance[i] == K:
            print(i)
else:
    print(-1)