arr = input().split()

source = []
N = int(arr[0])
for i in range(N):
    source.append(i)

result = []
idx = int(arr[1])
num = 0
for i in range(N):

    num+=idx - 1
    num %= len(source)

    result.append(source.pop(num)+1)


print("<", end="")
for r in range(len(result)-1):
    print(result[r], end=", ")
print(result[-1], end="")
print(">")