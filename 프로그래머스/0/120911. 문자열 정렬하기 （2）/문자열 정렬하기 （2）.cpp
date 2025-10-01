#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    for (char& c : my_string) {
        if (isupper(c)) c = c - 'A' + 'a';
    }
    
    sort(my_string.begin(), my_string.end());
    
    return my_string;
}