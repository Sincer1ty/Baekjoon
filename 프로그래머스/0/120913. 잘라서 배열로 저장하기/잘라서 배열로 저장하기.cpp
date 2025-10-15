#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    
    auto end = my_str.begin()+my_str.size();
    for (auto i = my_str.begin(); i < end; i = i + n) {
        auto until = i + n;
        if (until > end) until = end;
        string new_str(i, until);
        answer.push_back(new_str);
    }
    
    return answer;
}