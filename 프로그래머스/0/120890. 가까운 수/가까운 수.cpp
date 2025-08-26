#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    sort(array.begin(), array.end()); // 정렬
    
    int left = 0, right = array.size();
    while (right - left >= 2) {
        int mid = left + ((right - left) / 2);
        int val = array[mid];
    
        if (val < n) left = mid;
        else if(val == n) return n;
        else right = mid;
    }
    
    int left_val = array[left], right_val = array[right];
    
    return (n - left_val > right_val - n) ? right_val : left_val;
}