#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<string> grid(n);
    pair<int,int> S = {-1,-1};
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j)
            if (grid[i][j] == 'S') S = {i, j};
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // visited[x][y][dir]
    vector<vector<array<bool,4>>> visited(
        n, vector<array<bool,4>>(m, {false,false,false,false})
    );

    queue<tuple<int,int,int,int>> q; // x, y, prev_dir, dist

    // Put first moves (from S -> neighbor) as distance 1
    for (int k = 0; k < 4; ++k) {
        int nx = S.first + dx[k], ny = S.second + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (grid[nx][ny] == '#') continue;
        if (grid[nx][ny] == 'E') { cout << 1 << '\n'; return 0; }
        visited[nx][ny][k] = true;
        q.push({nx, ny, k, 1});
    }

    while (!q.empty()) {
        auto [x, y, dir, dist] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == '#') continue;

            // 오른쪽 회전 금지: cross == -1 이면 오른쪽 회전
            int cross = dx[dir] * dy[k] - dy[dir] * dx[k];
            if (cross == -1) continue;

            if (grid[nx][ny] == 'E') { cout << dist + 1 << '\n'; return 0; }

            if (!visited[nx][ny][k]) {
                visited[nx][ny][k] = true;
                q.push({nx, ny, k, dist + 1});
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}
