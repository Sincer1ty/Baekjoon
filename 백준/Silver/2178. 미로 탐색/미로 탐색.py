import re
import sys
input = sys.stdin.readline

N, M = list(map(int, input().split()))

miro = [[None]*(M+2)]

for n in range(N):
    row = [None]
    row.extend(list(map(int,input().strip())))
    row.append(None)
    miro.append(row)
miro.append([None]*(M+2))

import queue

q = queue.Queue()

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x,y):
    miro[x][y] = 0
    q.put([x,y])
    
    while q.qsize():
        pos = q.get()
        x = pos[0]
        y = pos[1]

        # [x-1][y], [x=1][y], [x][y-1], [x][y+1]
        for i in range(4):
            if miro[x+dx[i]][y+dy[i]] == 1:
                miro[x+dx[i]][y+dy[i]] = miro[x][y] + 1
                q.put([x+dx[i], y+dy[i]])

bfs(1,1)
print(miro[N][M]+1)