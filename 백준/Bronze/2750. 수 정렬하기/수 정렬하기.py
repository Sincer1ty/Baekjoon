T = int(input())

list=[]
for i in range(T):
    list.append(int(input()))

for k in range(T):
    for j in range(T-k-1):
        if list[j] > list[j+1]:
            list[j], list[j+1] = list[j+1], list[j]

for idx in range(len(list)):
    print(list[idx])