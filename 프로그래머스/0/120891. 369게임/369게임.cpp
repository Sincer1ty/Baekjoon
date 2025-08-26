#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    string str = to_string(order);
    
    for (char c : str) {
        if (c == '3' || c == '6' || c == '9') ++answer;
    }
    
    return answer;
}