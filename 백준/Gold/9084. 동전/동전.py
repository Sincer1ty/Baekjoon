import sys
input = sys.stdin.readline
T = int(input())

for _ in range(T):
    N = int(input())
    coin = list(map(int, input().split()))
    M = int(input())
    c=[]
    for i in range(M+1):
        if i % coin[0] == 0:
            c.append(1)
        else:
            c.append(0)

    def case(m):
        for i in coin[1:]:
            for j in range(i, M+1):
                c[j] += c[j - i]

    case(M)
    print(c[M])