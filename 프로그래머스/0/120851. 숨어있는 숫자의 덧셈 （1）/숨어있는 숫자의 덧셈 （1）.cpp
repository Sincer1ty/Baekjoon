#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    for (char c : my_string) {
        if (c >= '1' && c <= '9') answer += (c - '0'); // 모든 자연수의 합
    }
    
    return answer;
}