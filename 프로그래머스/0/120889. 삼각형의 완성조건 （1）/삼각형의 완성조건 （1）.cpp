#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> sides) {
    int max_ele = *max_element(sides.begin(), sides.end());
    
    if (max_ele < (accumulate(sides.begin(), sides.end(), 0) - max_ele)) return 1;
    
    return 2;
}