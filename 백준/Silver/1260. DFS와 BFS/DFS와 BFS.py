N, M, V = input().split()
N = int(N)
M = int(M)

class Node:
    def __init__(self, val):
        self.adj = []
        self.val = val
        self.color = "white"
        self.u = None

vertex = [None]
for n in range(N):
    vertex.append(Node(n+1))

for m in range(M):
    edge = list(map(int, input().split()))
    vertex[edge[0]].adj.append(vertex[edge[1]])
    vertex[edge[1]].adj.append(vertex[edge[0]])

for n in range(N):
    vertex[n+1].adj.sort(key=lambda v: v.val)

def dfs(v):
    if v.color == 'gray':
        return

    v.color = 'gray'
    print(v.val, end=' ')
    for a in v.adj:
        dfs(a)

import queue

q = queue.Queue()

def bfs(s):
    s.color = 'gray'

    q.put(s)
    
    while q.qsize():
        u = q.get()

        print(u.val, end=' ')

        for a in u.adj:
            if a.color != 'gray':
                a.color = 'gray'
                q.put(a)

dfs(vertex[int(V)])
print()
for n in range(N):
    vertex[n+1].color = 'white'

bfs(vertex[int(V)])
