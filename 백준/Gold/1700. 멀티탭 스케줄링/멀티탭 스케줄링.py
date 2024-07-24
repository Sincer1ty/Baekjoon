import sys
input = sys.stdin.readline
N, K = map(int, input().split())

order = list(map(int, input().split()))

on = [0]*N
count = 0

left = [0]*N
def check(n):
    left[n]
    pass

def max(arr):
    maxIdx = 0
    for i in range(1, len(arr)):
        if arr[maxIdx] < arr[i]:
            maxIdx = i
    
    return maxIdx

#on에 0이 있으면
for _ in range(len(order)):
    flag = 0
    
    for i in range(len(on)):
        if on[i] == 0:
            on[i] = order[0]
            flag = 1
            break
        #꽂혀 있으면
        elif on[i] == order[0]:
            flag = 1
            break
    
    if flag == 0:
        flag2 = 0
        idx = [0] * len(on)
        for i in range(len(on)):
            for j in range(len(order)):
                if on[i] == order[j]:
                    idx[i] = j
                    break
            
            if not on[i] in order:
                flag2 = 1
                on[i] = order[0]
                count += 1
                break
        # 다 뒤에 나오면
        if flag2==0:
            on[max(idx)] = order[0]
            count += 1

    order.pop(0)
        

print(count)
