import itertools
import sys
input = sys.stdin.readline

N = int(input())

number = list(map(int, input().split()))
cnt = list(map(int, input().split()))
op = []
if cnt[0] != 0:
    op.extend(['+']*cnt[0])
if cnt[1] != 0:
    op.extend(['-']*cnt[1])
if cnt[2] != 0:
    op.extend(['x']*cnt[2])
if cnt[3] != 0:
    op.extend(['/']*cnt[3])

permutations = itertools.permutations(op)

result = []
temp = number[0]
for p in permutations:
    temp = number[0]
    for i in range(len(p)):
        if p[i] == '+':
            temp += number[i+1]
        elif p[i] == '-':
            temp -= number[i+1]
        elif p[i] == 'x':
            temp *= number[i+1]
        elif p[i] == '/':
            temp = int(temp / number[i+1])
    result.append(temp)

print(max(result))
print(min(result))