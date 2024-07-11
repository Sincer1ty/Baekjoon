N = input()

new = N
count = 0
if int(new)<10:
    N+=N
    new = N

flag = False

def rSum(arr):
    arr = str(sum(arr))
    return arr[-1]

def create():
    global new, n, count
    n = int(new)
    
    new = str(n%10)+str((n%10 + n//10)%10)

    count +=1

while True:
    if flag and new == N:
        break
    flag = True

    create()

print(count)
