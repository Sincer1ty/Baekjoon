import sys
input = sys.stdin.readline
T = int(input())

for _ in range(T):
    N = int(input()) # 지원자 수
    score = []
    for _ in range(N):
        score.append(list(map(int, input().split()))) # 서류, 면접

    score.sort()

    max = score[0][1]

    count = 1
    for fir, sec in score:
        if sec < max:
            # 합격
            max = sec
            count +=1
            
    print(count)