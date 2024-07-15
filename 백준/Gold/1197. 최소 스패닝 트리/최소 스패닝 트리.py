V, E = input().split()
V = int(V)
E = int(E)

edge = []
for e in range(E):
    edge.append(list(map(int, input().split())))

edge.sort(key=lambda e: e[2])

A = []

for v in range(V):
    A.append(v+1)

w = 0

def find(v):
    if v != A[v-1]:
        A[v-1] = find(A[v-1])
    return A[v-1]
        
for e in edge:
    
    u = e[0]
    v = e[1]
    # u의 head 랑 v의 head 비교
    if find(u) != find(v):
        if find(u) < find(v):
            A[find(v)-1] = find(u) #v
        else:
            A[find(u)-1] = find(v) #u
        w += e[2]

print(w)