T = int(input())

list = [None] * T
for i in range(T):
    list[i] = int(input())

def isPrime(N): # 소수 판별
    if N == 1:
        return 0
    for x in range(2, N): #1과 자기 자신을 제외한 수
        if N % x == 0: # 나누어 떨어지면
            return 0 # 소수 아님
    return 1

for idx in range(T):
    for x in range(list[idx]//2, 1, -1):
        if isPrime(x) and isPrime(list[idx]-x):
            print(f"{x} {list[idx]-x}")
            break