import sys


T = int(input())

sys.setrecursionlimit(10**8)

source = [[None]*T]*T
for i in range(T):
    source[i] = input().split()

count0 = 0
count1=0
def checkColor(x, y, n):
    global count0, count1
    flag = source[x][y]

    Flag2 = True
    for i in range(n):
        for j in range(n):
            if source[x+i][y+j] != flag:
                Flag2 = False
                break
        if not Flag2:
            break
    if Flag2:
        if flag == '0':
            count0+=1
        else:
            count1+=1
    else:    
        mid = n//2
        checkColor(x,y,mid)

        checkColor(x, y+mid, mid)

        checkColor(x+mid, y, mid)
  
        checkColor(x+mid, y+mid, mid)
    

checkColor(0, 0, T)
print(count0)
print(count1)
