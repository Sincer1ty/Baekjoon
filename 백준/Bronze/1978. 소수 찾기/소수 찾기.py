T = int(input())

list = [None] * T
list = input().split()

def check(N):
    if N == 1:
        return 0
    for x in range(2, N): #1과 자기 자신을 제외한 수
        if N % x == 0:
            return 0
    return 1

count = 0
for i in range(0, T):
    n = int(list[i])
    count += check(n)
print(count)