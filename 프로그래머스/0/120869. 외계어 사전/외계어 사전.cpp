#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    for (string s : dic) {
        // size 안 맞으면 넘기기
        if (s.size() != spell.size()) continue;
        
        int check = 0;
        for (char c : s) {
            auto it = find(spell.begin(), spell.end(), string(1, c));
            int index = it - spell.begin();
            if (it != spell.end()) {
                if ((check & (1 << index)) != 0) break;
                
                check |= 1<<index;
            }
            else break;
        }
        
        if (check == (1 << spell.size()) - 1)
            return 1;
    }
    
    return 2;
}