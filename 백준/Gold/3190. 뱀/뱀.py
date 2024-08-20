import sys
input = sys.stdin.readline

# 보드의 크기
N = int(input())

# 사과의 개수
K = int(input())

apple = []
for _ in range(K):
    apple.append(list(map(int, input().split())))

# 뱀의 방향 변환 정보
L = int(input())

direc = []
for _ in range(L):
    X, C = input().split()
    direc.append([int(X), C])

row = col = 0
turn = 1
sec = 0
snake = [[0,0]]
while row != N and col != N and row != -1 and col != -1:
    if direc and sec == direc[0][0]:
        if direc[0][1] == 'D':
            turn +=1
        else :
            turn -= 1
        direc.pop(0)
    
    if turn%4 == 1:
        # 오른쪽으로 증가
        col+=1
    elif turn%4 == 2:
        # 방향이 아래면
        row+=1
    elif turn%4 == 3:
        # 방향이 왼쪽이면
        col-=1
    else:
        # 방향이 위쪽이면
        row-=1
        
    sec+=1
        
	# 뱀의 몸과 부딪히면
    if [row, col] in snake:
        break
    
    snake.append([row, col])
        
	# 사과가 있으면
    K = 0
    for i, a in enumerate(apple):
        if a == [row+1, col+1]:
            apple.pop(i)
            K = 1
            break
        
    if not K:
        snake.pop(0)

print(sec)
