import sys
input = sys.stdin.readline

# 모든 컴퓨터 연결
# 중간에 거쳐도 상관 X
# 연결 비용 최소로
N = int(input())
M = int(input())

edge = []
for _ in range(M):
	a, b, c = map(int, input().split())
	edge.append([a, b, c])

# 최소 신장 트리
edge.sort(key=lambda e: e[2])

parent = []
for v in range(N+1):
    parent.append(v)

def find(v):
    if v != parent[v]:
        parent[v] = find(parent[v])
    return parent[v]

cost = 0
for e in edge:
	u, v, w = e

	# u의 head 랑 v의 head 비교
	if find(u) != find(v):
		if find(u) < find(v):
			parent[find(v)] = find(u) #v
		else:
			parent[find(u)] = find(v) #u
		cost += w

print(cost)
