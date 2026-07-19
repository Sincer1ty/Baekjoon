#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> sides) {
    // sides 합보다 작은 자연수 중 sides 와 같거나 큰 수
    int sum = accumulate(begin(sides), end(sides), 0);
    int max = *max_element(sides.begin(), sides.end());
    int answer = sum - max;
    
    // 가장 작은수 + 어떤 수 > 큰 수 && 어떤 수 < 큰 수
    int min = sum - max;
    answer += min - 1;
    
    return answer;
}