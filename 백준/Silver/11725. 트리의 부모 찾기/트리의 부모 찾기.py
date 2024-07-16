import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**8)

N = int(input())

class Node:
    def __init__(self, val):
        self.adj = []
        self.val = val
        self.color = 0

vertex = [None]
for n in range(N):
    vertex.append(Node(n+1))

for n in range(N-1):
    u, v = list(map(int, input().split()))
    vertex[u].adj.append(vertex[v])
    vertex[v].adj.append(vertex[u])

parent = [None]*(N+1)
def dfs(pre, now):
    if now.color == 1:
        return

    now.color = 1
    if pre:
        parent[now.val] = pre.val
    for a in now.adj:
        dfs(now, a)
    

dfs(vertex[0], vertex[1])

for p in range(2, N+1):
    print(parent[p])