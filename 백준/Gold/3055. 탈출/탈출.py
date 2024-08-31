import sys
input = sys.stdin.readline

R, C = map(int, input().split())

map = []
water = []
stone = []
for _ in range(R):
    row = list(input().strip())
    for i, r in enumerate(row):
        if r == 'D':
            dest = (_, i)
        elif r == 'S':
            start = (_, i)
        elif r == '*':
            water.append((_, i))
        elif r == 'X':
            stone.append((_, i))
    map.append(row)

# 우, 좌, 상, 하
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

# D : 비버의 굴 (도착지)
# S : 출발지
# * : 물 (매분 상하좌우로 확장 - 비어있을 때)
# X : 돌

import queue

def flood():
    for _ in range(len(water)):
        pos = water.pop(0)
        x = pos[0]
        y = pos[1]

        for i in range(4):
            if x+dx[i] == -1 or y+dy[i] == -1 or x+dx[i] == R or y+dy[i] == C :
                continue
            if map[x+dx[i]][y+dy[i]] == '.' or map[x+dx[i]][y+dy[i]] == 'S':
                map[x+dx[i]][y+dy[i]] = '*'
                water.append([x+dx[i], y+dy[i]])
    
q = queue.Queue()
minute = 0
isDest = 0
def bfs(x,y):
    global minute, isDest

    q.put([x,y])
    
    while q.qsize():
        flood()
        
        for _ in range(q.qsize()):
            pos = q.get()
            x = pos[0]
            y = pos[1]
        
            for i in range(4): # 우, 좌, 상, 하
                if x+dx[i] == -1 or y+dy[i] == -1 or x+dx[i] == R or y+dy[i] == C :
                    continue
                if map[x+dx[i]][y+dy[i]] == '.':
                    map[x+dx[i]][y+dy[i]] = 'S'
                    q.put([x+dx[i], y+dy[i]])
                elif map[x+dx[i]][y+dy[i]] == 'D':
                    isDest = 1
                    break
            if isDest == 1:
                break
        minute += 1
        if isDest == 1:
            break

bfs(start[0], start[1])
if isDest == 0:
    print('KAKTUS')
else:
    print(minute)
