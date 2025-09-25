#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    
    for (int num : numlist) {
        if (num % n == 0) answer.push_back(num); // n의 배수만
    }
    
    return answer;
}