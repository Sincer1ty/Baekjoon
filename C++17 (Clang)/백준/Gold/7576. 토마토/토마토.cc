#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int M, N;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main() {
    // 입력 받기
    cin >> M >> N;
    vector<vector<int>> tomato(N, vector<int>(M));
    queue<pair<int, int>> q;

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> tomato[n][m];
			if (tomato[n][m] == 1) {
				q.push({n, m});
			}
		}
	}

    int day = 0;

    // BFS 시작
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front();
            q.pop();

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                // 범위 검사
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

                if (tomato[nx][ny] == 0) {
                    tomato[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        day++;
    }

    // 익지 않은 토마토가 남아있는지 검사
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (tomato[n][m] == 0) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

    // 최소 일수 출력
    cout << day - 1 << endl;

    return 0;
}