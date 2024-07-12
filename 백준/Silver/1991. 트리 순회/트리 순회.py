N = int(input())

tree = [[None]]*N
for n in range(N):
    tree[n] = input().split()

def pre(tree, root):
    if root == '.':
        return
    
    for n in range(N):
        if tree[n][0] == root:
            key = n
            break
        
    print(root, end='')
    pre(tree, tree[key][1])
    pre(tree, tree[key][2])

def mid(tree, root):
    if root == '.':
        return
    
    for n in range(N):
        if tree[n][0] == root:
            key = n
            break

    mid(tree, tree[key][1])
    print(root, end='')
    mid(tree, tree[key][2])

def post(tree, root):
    if root == '.':
        return
    
    for n in range(N):
        if tree[n][0] == root:
            key = n
            break

    post(tree, tree[key][1])
    post(tree, tree[key][2])
    print(root, end='')

pre(tree, 'A')
print()
mid(tree, 'A')
print()
post(tree, 'A')
print()
