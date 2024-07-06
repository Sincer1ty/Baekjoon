import sys


N = int(sys.stdin.readline())

board = [0] * N

def checkPuzzle(col, board):
    flag = True
    j = 0
    while j < col:
        if board[j] == board[col] or col - j == board[col] - board[j] or col - j == board[j] - board[col]:
            flag = False
            break
        j+=1
    return flag

def placeQueens(col, board, row, count): 
    if col == N:
        count+=1
    else:
        while row< N:
            board[col] = row
            if checkPuzzle(col, board):
                count = placeQueens(col+1, board, 0, count)
            row+=1
    return count

count= placeQueens(0, board, 0, 0)
print(count)