#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

vector<int> solution(int n) {
    set<int> answer;
    
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            answer.insert(i);
            answer.insert(n/i);
        }
    }
    
    return vector<int>(answer.begin(), answer.end());
}