list = input().split() # int 변환 필요

def modular_exponentiation(a, b, m):
    result = 1  # 결과 초기화
    a = a % m  # a를 m으로 나눈 나머지를 계산
    
    while b > 0:
        if (b % 2) == 1:  # b가 홀수이면
            result = (result * a) % m
        b = b >> 1  # b를 2로 나눔
        a = (a * a) % m  # a를 제곱하고 m으로 나눈 나머지를 a에 저장
    
    return result


print(f"{modular_exponentiation(int(list[0]), int(list[1]), int(list[2]))}")
