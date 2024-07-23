import sys
input = sys.stdin.readline

str1 = input().strip()
str2 = input().strip()

matrix = [[0]*(len(str1)+1) for _ in range(len(str2)+1)]

for i in range(1, len(matrix)):
    for j in range(1, len(matrix[i])):
        if str1[j-1] == str2[i-1]:
            matrix[i][j] = matrix[i-1][j-1] + 1
        else:
            matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j])

print(matrix[len(str2)][len(str1)])