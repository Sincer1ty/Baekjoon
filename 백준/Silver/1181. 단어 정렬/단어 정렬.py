T = int(input())

list = []
for i in range(T):
    temp = input()
    if not (temp in list):
        list.append(temp)

list.sort()
list.sort(key=len)

for l in list:    
    print(l)
