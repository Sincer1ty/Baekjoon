#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    
    for (char c : my_string) {
        if (c >= '0' && c <='9') answer.push_back(c - '0');
    }
    
    sort(answer.begin(), answer.end()); // 숫자 오름차순 정렬
    
    return answer;
}