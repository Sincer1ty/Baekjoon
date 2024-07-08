T = int(input())

list=[]
for i in range(T):
    list.append(int(input()))

def mergeSort(list):
    if len(list) <=1:
        return list
    
    m=len(list)//2
    left = list[:m]
    right = list[m:]

    return merge(mergeSort(left), mergeSort(right))

def merge(left, right):
    sList=[]
    left_index = 0
    right_index = 0

    while left_index < len(left) and right_index < len(right):
        if left[left_index] < right[right_index]:
            sList.append(left[left_index])
            left_index += 1
        else:
            sList.append(right[right_index])
            right_index += 1

    sList.extend(left[left_index:])
    sList.extend(right[right_index:])

    return sList

result = mergeSort(list)
for x in result:
    print(x)
