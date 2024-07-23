import sys
input = sys.stdin.readline

equation = input()

nList = equation.strip().split('-')

if '+' in nList[0]:
    equation = list(map(int, nList[0].split('+')))
    nList[0] = str(sum(equation))
    result = int(nList[0])
else:
    result = int(nList[0])
for i in range(1, len(nList)):
    if '+' in nList[i]:
        equation = list(map(int, nList[i].split('+')))
        nList[i] = str(sum(equation))
    result -= int(nList[i])
    
print(result)
