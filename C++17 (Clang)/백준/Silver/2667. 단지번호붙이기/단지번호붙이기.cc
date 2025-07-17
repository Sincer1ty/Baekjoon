#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

int bfs(int x, int y, vector<vector<int>>& homes) {
	queue<pair<int, int>> q;

	q.push({x, y});
	homes[x][y] = -1;
	
	int count = 1;

	// 하, 상, 우, 좌
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int new_x = x + dx[i], new_y = y + dy[i];
			if (new_x < 0 || new_y < 0 || new_x >= N || new_y >=N) continue;

			if (homes[new_x][new_y] == 1) {
				q.push({new_x, new_y});
				homes[new_x][new_y] = -1;
				++count;
			}

		}
	}

	return count;
}

int main() {
    cin >> N;
	
	vector<vector<int>> homes(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		string line;
		cin >> line;
		for (int j = 0; j < N; ++j) {
			homes[i][j] = line[j] - '0';
		}
	}

	vector<int> block;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (homes[i][j] == 1) {
				block.push_back(bfs(i, j, homes));
			}
		}
	}

	// 단지별 집 수 오름차순
	sort(block.begin(), block.end());
    cout << block.size() << endl;
	for (int i = 0; i < block.size(); ++i) {
		cout << block[i] << endl;
	}
	
    return 0;
}