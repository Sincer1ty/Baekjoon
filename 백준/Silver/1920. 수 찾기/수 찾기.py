T = int(input())

list = input().split()

M = input()

list2 = input().split()

list.sort()

def find(arr, n):
    left, right = 0, len(arr)-1

    while left <=right:
        mid = (left+right)//2

        if arr[mid] == n:
            print(1)
            return
        elif arr[mid] < n:
            left = mid+1
        else:
            right = mid -1
    print(0)
    

for i in list2:
    find(list, i)
