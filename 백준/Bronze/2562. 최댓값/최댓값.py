n = [None] * 9

idx = 0

for i in range(0, 9):
    n[i] = int(input())

    if i == 0:
        max = n[i]    
    else:
        if n[i] > max:
            max = n[i]
            idx = i

print(max)
print(idx+1) 