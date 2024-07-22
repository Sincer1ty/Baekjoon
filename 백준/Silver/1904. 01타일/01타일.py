import sys
input = sys.stdin.readline
n = int(input())

def fib(n, memo = {}):
    memo[0] = 1
    memo[1] = 1
    i = 2
    while i != n+1:
        if n in memo:
            break
        memo[i] = (memo[i-1] % 15746 + memo[i-2] % 15746) % 15746
        i+=1
    return memo[n]

print(fib(n))