#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    for (char& c : my_string) {
        if (c >= 'a') c = c - 'a' + 'A';
        else c = c - 'A' + 'a';
    }
    
    return my_string;
}