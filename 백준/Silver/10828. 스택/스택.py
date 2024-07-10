import sys

T = int(sys.stdin.readline())

store = []
for i in range(T):
    c = sys.stdin.readline().split()
    if len(c) == 2:
        c[1] = int(c[1])
        store.append(c[1])
    elif c[0] == 'top':
        if len(store):
            print(store[-1])
        else:
            print(-1)
    elif c[0] =='size':
        print(len(store))
    elif c[0] == 'pop':
        if len(store):
            print(store[-1])
            store.pop()
        else:
            print(-1)
    else:
        print(int(len(store) == 0))