#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> adj;

bool dfs(int node, int depth, vector<bool> visited) {
    visited[node] = true;
    if (depth >= 4) return true;
    for (auto n : adj[node]) {
        if (visited[n]) continue;
        if (dfs(n, depth+1, visited)) return true;
    }
    return false;
}

int main() {
    int N, M;
	cin >> N >> M;
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < N; ++i) {
        vector<bool> visited(N);
        if (dfs(i, 0, visited)) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}