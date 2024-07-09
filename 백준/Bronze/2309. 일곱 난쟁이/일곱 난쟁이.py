numbers = [None] * 9
for i in range(9):
    numbers[i] = int(input()) 

import itertools

# 조합 생성
combinations = list(itertools.combinations(numbers, 7))

for c in combinations:
    if sum(c) == 100:
        result = list(c)

result.sort()
for i in result:
    print(i)
