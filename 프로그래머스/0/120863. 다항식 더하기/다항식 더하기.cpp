#include <string>
#include <vector>

using namespace std;

string solution(string polynomial) {
    string answer ="";
    
    int num = 0;
    vector<int> nums(2);
    for (char c : polynomial) {
        if (c>='0'&&c<='9') {
            num *= 10;
            num += c-'0';
        }
        else if (c == 'x') {
            if (num == 0) num=1;
            nums[1] += num;
            num = 0;
        }
        else if (c == '+') {
            nums[0] += num;
            num=0;
        }
    }
    nums[0] += num;
    
    if (nums[1]) {
        if (nums[1] !=1) answer += to_string(nums[1]);
        answer += 'x';
    }
    if (nums[0]) {
        if (answer != "") answer += " + ";
        answer += to_string(nums[0]);
    }
    
    return answer;
}