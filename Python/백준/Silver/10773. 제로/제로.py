import sys
input = sys.stdin.readline

K = int(input())

money = []
for _ in range(K):
	num = int(input())

	if num == 0:
		money.pop()
	else:
		money.append(num)

print(sum(money))