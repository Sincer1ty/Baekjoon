#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    // size / n 행 n열 : 나머지 있으면 +1 행
    int row = num_list.size() / n;
    if (num_list.size() % n) row += 1;
    
    vector<vector<int>> answer(row, vector<int>(n));
    
    // n 개씩 나누기
    for (int i = 0; i < num_list.size(); ++i) {
        answer[i/n][i%n] = num_list[i];
    }
    
    return answer;
}