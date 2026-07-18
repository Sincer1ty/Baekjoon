#include <string>
#include <vector>

using namespace std;

int checkAround(int start, int end, vector<vector<int>>& board) {
    int count = 0;
    
    for (int i = start-1; i <= start+1; ++i) {
        if (i < 0 || i >= board.size()) continue;
        for (int j = end-1; j <= end+1; ++j) {
            if (j < 0 || j >= board[0].size()) continue;
            if (board[i][j] == 0) {
                board[i][j] = 2;
                count++;
            }
        }
    }
    return count;
}

int solution(vector<vector<int>> board) {
    int answer = board.size() * board[0].size();
    
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[i][j] == 1) {
                answer -= checkAround(i, j, board) + 1;
            }
        }
    }
    
    return answer;
}