import sys
input = sys.stdin.readline

# 조합 kC6
result = []
def combination(source):
	global result
	if len(result) == 6:
		print(*result)
		return
	
	for i in range(len(source)):
		result.append(source[i])
		combination(source[i+1:])
		result.pop()

while 1:
	get = list(map(int, input().split()))
	if get[0] == 0:
		break
	combination(get[1:])
	print()
