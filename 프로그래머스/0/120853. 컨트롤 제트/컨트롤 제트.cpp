#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0, prev;
    int size = s.size();
    bool isNegative = false;
    
    for (int i = 0; i < size; ++i) {
        char c = s[i];
        
        if (c == ' ') {
            if (isNegative) {
                prev *= -1;
				isNegative = false;
			}
            answer += prev;
            continue;
        }
        else if (c == 'Z') {
            prev *= -1;
            continue;
        }
        
        if (c == '-') {
            isNegative = true;
            prev = 0;
            continue;
        }
        
        if (i == 0 || s[i-1] == ' ') { // 이전이 공백이면
            prev = (c - '0');
        }
        else {
            prev *= 10;
            prev += (c - '0');
        }
    }
    
    if (isNegative) {
        prev *= -1;
    }
    
    return answer + prev;
}