import sys
input = sys.stdin.readline

N = int(input())

can = 1
five = N // 5
left = N - 5 * five
while left % 3 != 0:
    if five == 0:
        can = 0
        break
    five -= 1
    left = N - 5 * five

if not can:
    print(-1)
else:
    three = left // 3

    print(five+three)
