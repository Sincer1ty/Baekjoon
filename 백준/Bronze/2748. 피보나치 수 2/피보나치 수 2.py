import sys
input = sys.stdin.readline
n = int(input())

def fib(n, memo = {}):
    if n in memo:
        return memo[n]
    if n <= 2:
        memo[n] = 1
        return memo[n]
    memo[n] = fib(n-1, memo) + fib(n-2, memo)
    return memo[n]

print(fib(n))