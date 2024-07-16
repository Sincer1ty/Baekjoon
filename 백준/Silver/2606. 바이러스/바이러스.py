import sys


computer = int(sys.stdin.readline())
edge = int(sys.stdin.readline())

class Node:
    def __init__(self, val):
        self.adj = []
        self.val = val
        self.color = 0

vertex = [None]
for n in range(computer):
    vertex.append(Node(n+1))

for m in range(edge):
    u, v = list(map(int, sys.stdin.readline().split()))
    vertex[u].adj.append(vertex[v])
    vertex[v].adj.append(vertex[u])

count = -1
def dfs(v):
    global count
    if v.color == 1:
        return

    v.color = 1
    count+=1
    for a in v.adj:
        
        dfs(a)

dfs(vertex[1])

print(count)