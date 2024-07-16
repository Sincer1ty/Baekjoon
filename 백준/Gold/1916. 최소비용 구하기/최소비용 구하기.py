import sys
import heapq

sys.setrecursionlimit(10**8)

class Node:
    def __init__(self, value) -> None:
        self.adj = {}
        self.value = value
        self.distance = 9999999999

    def __lt__(self, other):
        return  self.distance < other.distance
         
def Dijkstra(start:Node):
    q = []
    heapq.heappush(q, start)
    
    q.append(start)

    
    while len(q):
        cur = heapq.heappop(q)
        nodes = list(cur.adj.keys())
        for n in nodes:
            if n.distance > cur.distance+cur.adj[n]:
                n.distance = cur.distance+cur.adj[n]
                heapq.heappush(q, n)

# 입력
N = int(sys.stdin.readline())
M = int(sys.stdin.readline())

# 노드 배열 초기화
nodes = [None]
for i in range(N):
    nodes.append(Node(i+1))

# 간선 배열 초기화
for _ in range(M):
    input = sys.stdin.readline().split()
    a = nodes[int(input[0])]
    b = nodes[int(input[1])]
    dist = int(input[2])
    
    # 중복 간선 있을 경우 비용 높은건 무시
    if b in a.adj and a.adj[b] < dist:
        continue
    a.adj[b] = dist

# 시작, 끝점
input = sys.stdin.readline().split()
start = nodes[int(input[0])]
end = nodes[int(input[1])]

# 로직 구현
start.distance = 0
Dijkstra(start)

print(end.distance)