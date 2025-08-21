#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 4; i <= n; ++i) {
        int limit = sqrt(i); // 제곱근까지 판별
        for (int j = 2; j <= limit; ++j) {
            if (i % j == 0) {
                ++answer;
                break;
            }
        }
    }
    
    return answer;
}