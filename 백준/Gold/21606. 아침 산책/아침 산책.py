import sys
input = sys.stdin.readline

# 정점의 수
N = int(input())
isInside = list(map(int, input().strip()))

class Node:
    def __init__(self, val):
        self.adj = []
        self.val = val
        self.color = "white"

vertex = [None]
for i in range(N):
    vertex.append(Node(i+1))
for _ in range(N-1):
    u, v = map(int, input().split())
    vertex[u].adj.append(vertex[v])
    vertex[v].adj.append(vertex[u])

count = 0
def dfs(v):
    global count
    
    v.color = 'gray'
    for a in v.adj:
        if a.color == 'gray':
            continue
        elif not isInside[a.val -1]:
            dfs(a)
        else:
            count+=1
    return

for i, v in enumerate(isInside):
    if isInside[i]:
        dfs(vertex[i + 1])
        for k, j in enumerate(vertex):
            if k == 0:
                continue
            j.color = 'white'

print(count)