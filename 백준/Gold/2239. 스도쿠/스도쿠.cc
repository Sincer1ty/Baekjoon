#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> board(9, vector<int>(9));
vector<vector<bool>> usedRow(9, vector<bool>(10));
vector<vector<bool>> usedCol(9, vector<bool>(10));
vector<vector<bool>> usedGroup(9, vector<bool>(10));
stack<pair<int, int>> q;

void guess(int row, int col) {
	int groupIdx = (3 * (row / 3)) + (col / 3);

	for (int i = 1; i <= 9; ++i) {
		if (usedRow[row][i]) continue;
		if (usedCol[col][i]) continue;
		if (usedGroup[groupIdx][i]) continue;
		
		board[row][col] = i;
		usedRow[row][i]=true;
		usedCol[col][i]=true;
		usedGroup[groupIdx][i]=true;
		
		if(q.empty()) return;

		auto [x, y] = q.top();
		q.pop();
		guess(x, y);
		
		if(q.empty()) return;

		usedRow[row][i]=false;
		usedCol[col][i]=false;
		usedGroup[groupIdx][i]=false;
		board[row][col] = 0;
	}
	if (board[row][col] == 0) q.push({row, col});
}

void checkGroup() {
	int row = 0, col = 0;
	for (int idx = 0; idx < 9; ++idx) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				usedGroup[idx][board[row+i][col+j]]=true;
			}
		}
		col += 3;
		if (col >= 9) {
			col = 0;
			row += 3;
		}
	}
}

void checkCol() {
	for (int i = 0; i < 9; ++i) {
		for (int row = 0; row < 9; ++row) {
			usedCol[i][board[row][i]]=true;
		}
	}
}

int main() {
    for (int i = 0; i < 9; ++i) {
        string line;
        cin >> line; // 한 줄 입력 받기
        
        int col = 0;
		for (char ch : line) {
			int num = ch-'0';
			board[i][col++] = num;
			usedRow[i][num]=true;
        }

    }
	checkCol();
	checkGroup();

	for (int i = 8; i >= 0; --i) {
		for (int col = 8; col >= 0; --col) {
            if (board[i][col] == 0) {
				q.push({i, col});
			}
        }
    }
	auto [x, y] = q.top();
	q.pop();
	guess(x, y);

    for (int i = 0; i < 9; ++i) {
        for (int col = 0; col < 9; ++col) {
            cout << board[i][col];
        }
		cout << endl;
    }

    return 0;
}