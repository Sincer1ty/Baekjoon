#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    unordered_map<string, int> m;
    
    m["zero"] = 0;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    
    string cur = "";
    for (char c : numbers) {
        cur += c;
        
        auto it = m.find(cur);
        if (it == m.end()) continue; // 못 찾음
        
        answer *= 10;
        answer += it->second;
        cur = "";
    }
    
    return answer;
}