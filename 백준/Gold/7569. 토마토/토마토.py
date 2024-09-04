import sys
input = sys.stdin.readline

# M : 가로, N : 세로, H : 높이
M, N, H = map(int, input().split())

box=[]
tomato = []
import queue

q = queue.Queue()
for i in range(H):
    box=[]
    for _ in range(N):
        row = list(map(int, input().split()))
        for j, r in enumerate(row):
            if r == 1:
                q.put([i, _, j])
        box.append(row)
    tomato.append(box)

# 우, 좌, 뒤, 앞, 위, 아래
dx = [0, 0, -1, 1, 0, 0]
dy = [1, -1, 0, 0, 0, 0]
dh = [0, 0, 0, 0, 1, -1]

day = 0
def bfs():
    global day

    while q.qsize():    
        for _ in range(q.qsize()):    
            pos = q.get()
            h = pos[0]
            x = pos[1]
            y = pos[2]

            # 우, 좌, 뒤, 앞, 위, 아래
            for i in range(6):
                if tomato[h][x][y] == -1:
                    break
                if x+dx[i] == -1 or y+dy[i] == -1 or h+dh[i] == -1 or x+dx[i] == N or y+dy[i] == M or h+dh[i] == H:
                    continue
                if tomato[h+dh[i]][x+dx[i]][y+dy[i]] == 0:
                    tomato[h+dh[i]][x+dx[i]][y+dy[i]] = 1
                    q.put([h+dh[i], x+dx[i], y+dy[i]])
        day+=1

bfs()

isfail = 0
for t in tomato:
    for i in t:
        for j in i:
            if j == 0:
                isfail = 1
                break
        if isfail:
            break
    if isfail:
        break

if isfail:
    print(-1)
else:
    print(day-1)
