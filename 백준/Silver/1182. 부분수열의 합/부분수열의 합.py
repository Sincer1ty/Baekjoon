from itertools import combinations

NS= input().split()
N = int(NS[0])
S = int(NS[1])

source = input().split()

count = 0

for i in range(1,N+1):
    com = combinations(source, i)
    
    for c in com:
        plus = 0
        for n in c:
            plus += int(n)
           
        if plus == S:
            count +=1

print(count)
    