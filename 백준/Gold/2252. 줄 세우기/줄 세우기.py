import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**8)

N, M = list(map(int, input().split()))

# 노드 생성
class Node:
    def __init__(self, val):
        self.adj = []
        self.val = val
        self.visited = 0

vertex = [None]
for n in range(N):
    vertex.append(Node(n+1))

for m in range(M):
    u, v = list(map(int, input().split()))
    vertex[u].adj.append(vertex[v])

result = []
def dfs(v : Node):
    if v.visited == 1:
        return

    v.visited = 1
    
    for a in v.adj:
        dfs(a)
        
    result.append(v.val)

for i in range(1, N+1):
    dfs(vertex[i])

result.reverse()
print(*result)