def Hanoi(N, A, B, C):
    if N == 1:
        print(f"{A} {C}")
    else:
        Hanoi(N-1, A, C, B)
        print(f"{A} {C}")
        Hanoi(N-1, B, A, C)

n = int(input())

print(2**n-1)
if n <= 20:
    Hanoi(n, 1, 2, 3)