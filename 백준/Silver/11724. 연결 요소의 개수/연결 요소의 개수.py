import sys

sys.setrecursionlimit(10**6)

N, M = list(map(int, sys.stdin.readline().split()))

class Node:
    def __init__(self, val):
        self.adj = []
        self.val = val
        self.color = 0

vertex = [None]
for n in range(N):
    vertex.append(Node(n+1))

for m in range(M):
    u, v = list(map(int, sys.stdin.readline().split()))
    vertex[u].adj.append(vertex[v])
    vertex[v].adj.append(vertex[u])

def dfs(v):
    if v.color == 1:
        return

    v.color = 1
    for a in v.adj:
        dfs(a)

count=0
for v in range(N):
    if vertex[v+1].color ==0:
        dfs(vertex[v+1])
        count+=1

print(count)