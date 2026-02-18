class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        using T = pair<int, pair<int, int>>; // (시간, (x, y))
        priority_queue<T, vector<T>, greater<>> pq;
        pq.push({0, {0, 0}});

        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!pq.empty()) {
            auto [time, pos] = pq.top(); pq.pop();
            int x = pos.first, y = pos.second;

            if (x == n - 1 && y == m - 1) return time;
            if (time > dist[x][y]) continue;

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                int waitTime = max(moveTime[nx][ny], time);
                int newTime = waitTime + 1;

                if (newTime < dist[nx][ny]) {
                    dist[nx][ny] = newTime;
                    pq.push({newTime, {nx, ny}});
                }
            }
        }

        return -1; // 도달할 수 없는 경우
    }
};