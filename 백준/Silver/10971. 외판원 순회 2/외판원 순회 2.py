T = int(input())

list = [[None]*T]*T
for i in range(T):
    list[i] = input().split()

# 중첩된 리스트 컴프리헨션을 사용한 변환
list = [[int(item) for item in row] for row in list]

route = []
def out(p):
    result = 0
    flag = True
    for k in range(T-1):
        if list[p[k]][p[k+1]] == 0:
            flag=False
            break
        result += list[p[k]][p[k+1]]
    if flag:
        if list[p[k+1]][p[0]] != 0:
            result += list[p[k+1]][p[0]]
            route.append(result)
    
def permute(nums, n=0):
    if n==T:
        out(nums)
        return
    for i in range(T):
        if i in nums:
            continue
        nums[n] = i
        permute(nums, n+1)
        nums[n] = None

arr = [None]*T
permute(arr)
print(min(route))

