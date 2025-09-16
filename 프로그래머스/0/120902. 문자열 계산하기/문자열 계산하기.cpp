#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0, num = 0;
    bool isNeg = false;
    
    for (char c : my_string) {
        if (c >= '0' && c <= '9') {
            num *= 10;
            num += c-'0'; // 숫자 변환
        }
        else if (c == '-') isNeg = true;
        else if (c == '+') isNeg = false;
        else {
            if (isNeg) num *= -1;
            answer += num;
            num = 0;
        }
    }
    
    if (isNeg) num *= -1;
    
    return answer+num;
}