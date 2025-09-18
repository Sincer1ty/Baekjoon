#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    
    for (string s: s1) {
        for (string ele : s2) {
            if (s == ele) {
                ++answer;
                break;
            }
        }
    }
    
    return answer;
}