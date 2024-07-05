T = int(input())

list = [None] * T
for t in range(0, T):
    R, S = input().split()
    list[t] = (int(R),S)

for t in range(0,T):
    P=""
    for s in list[t][1]:
        for r in range(0, list[t][0]):
            P += s
    print(P)