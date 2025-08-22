#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) { // 소수 판별
    int limit = sqrt(n); // 제곱근까지 판별
    for (int j = 2; j <= limit; ++j) {
        if (n % j == 0) return false;
    }
    
    return true;
}

vector<int> solution(int n) {
    vector<int> answer;
    
    for (int i = 2; i <= n; ++i) { 
        if (!isPrime(i)) continue;
        
        if (n%i == 0) {
            n /= i;
            answer.push_back(i);
        }
    }
    
    return answer;
}