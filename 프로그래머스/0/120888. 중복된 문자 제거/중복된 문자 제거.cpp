#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(string my_string) {
    string answer = "";
    unordered_set<char> str_set;
    
    for (char c : my_string) {        
        if (str_set.insert(c).second) answer += c;
    }
    
    return answer;
}