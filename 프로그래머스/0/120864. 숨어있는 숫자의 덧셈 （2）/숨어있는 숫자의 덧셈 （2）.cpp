#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int sum = 0;
    int current = 0;
    bool isNumber = false;

    for (char c : my_string) {
        if (isdigit(c)) {
            isNumber = true;
            current = current * 10 + (c - '0');
        } else {
            if (isNumber) {
                sum += current;
                current = 0;
                isNumber = false;
            }
        }
    }
    // 문자열이 숫자로 끝났을 경우 마지막 숫자 처리
    if (isNumber) sum += current;

    return sum;
}