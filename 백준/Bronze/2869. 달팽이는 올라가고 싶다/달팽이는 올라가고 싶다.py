import sys
input = sys.stdin.readline

A, B, V = map(int, input().split())

result = (V - A) // (A-B)
if (V - A) % (A-B):
    result += 1

print(result + 1)