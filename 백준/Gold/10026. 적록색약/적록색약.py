import sys
input = sys.stdin.readline

N = int(input())

picture=[]
pic2=[]
for _ in range(N):
    row =list(input().strip())
    picture.append(row)
    pic2.append(list(row))

import queue

q = queue.Queue()

# 우, 좌, 상, 하
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

def bfs(x, y, color, num): 

    q.put([x, y])
    picture[x][y] = num

    while q.qsize():    
        pos = q.get()
        x = pos[0]
        y = pos[1]

        for i in range(4):
            if x+dx[i] == -1 or y+dy[i] == -1 or x+dx[i] == N or y+dy[i] == N:
                continue
            if picture[x+dx[i]][y+dy[i]] == color:
                picture[x+dx[i]][y+dy[i]] = num
                q.put([x+dx[i], y+dy[i]])
    
    for x in range(N):
        for y in range(N):
            if picture[x][y] == 'R' or picture[x][y] == 'B' or picture[x][y] == 'G':
                num = bfs(x, y, picture[x][y], num+1)
                return num
    
    return num

def bfs2(x, y, color, num): 

    q.put([x, y])
    pic2[x][y] = num

    while q.qsize():    
        pos = q.get()
        x = pos[0]
        y = pos[1]

        for i in range(4):
            if x+dx[i] == -1 or y+dy[i] == -1 or x+dx[i] == N or y+dy[i] == N:
                continue
            if color == 'R' or color == 'G':
                if pic2[x+dx[i]][y+dy[i]] == 'R' or pic2[x+dx[i]][y+dy[i]] == 'G':
                    pic2[x+dx[i]][y+dy[i]] = num
                    q.put([x+dx[i], y+dy[i]])
            elif pic2[x+dx[i]][y+dy[i]] == color:
                pic2[x+dx[i]][y+dy[i]] = num
                q.put([x+dx[i], y+dy[i]])
    
    for x in range(N):
        for y in range(N):
            if pic2[x][y] == 'R' or pic2[x][y] == 'B' or pic2[x][y] == 'G':
                num = bfs2(x, y, pic2[x][y], num+1)
                return num
    
    return num

first = bfs(0, 0, picture[0][0], 1)
second = bfs2(0, 0, pic2[0][0], 1)
print(first, second)
