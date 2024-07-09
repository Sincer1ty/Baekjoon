from collections import deque

queue = deque()

import sys

T = int(sys.stdin.readline())

for i in range(T):
    c = sys.stdin.readline().split()
    if len(c) == 2:
        c[1] = int(c[1])
        queue.append(c[1])   # Enqueue
    elif c[0] == 'front':
        if len(queue):
            print(queue[0])
        else:
            print(-1)
    elif c[0] == 'back':
        if len(queue):
            print(queue[-1])
        else:
            print(-1)
    elif c[0] =='size':
        print(len(queue))
    elif c[0] == 'pop':
        if len(queue):
            print(queue[0])
            queue.popleft()  # Dequeue
        else:
            print(-1)
    else:
        print(int(len(queue) == 0))

