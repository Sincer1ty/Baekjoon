#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array) {
    auto it = max_element(array.begin(), array.end());
    int idx = it-array.begin();
    
    return vector<int>({*it, idx}); 
}