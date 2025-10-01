#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int size2 = str2.size();
    int size = str1.size() - size2;
    for (int j = 0; j <= size; ++j) {
        int i = 0;
        while (i < size2 && str1[j+i] == str2[i]) ++i;
        if (i == size2) return 1;
    }
    
    return 2;
}