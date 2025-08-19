#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

void dijkstra(int start, vector<vector<pair<int,int>>>& graph, vector<int>& ans) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

    q.push({0, start});
    ans[start] = 0;

    while (!q.empty()) {
        auto [dist, node] = q.top();
        q.pop();
        
        if (dist > ans[node]) continue;

        for (auto [v, w] : graph[node]) {
            if (ans[v] > ans[node]+w) {
                ans[v] = ans[node] + w;
                q.push({ans[v], v});
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    
    // 시작 정점
    int start;
    cin >> start;

    // 인접 그래프
    vector<vector<pair<int,int>>> graph(V);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u-1].push_back({v-1, w});
    }

    // 정답 배열
    vector<int> ans(V, INF);
    // ans[start-1] = 0;

    dijkstra(start-1, graph, ans);
    
    for (int i = 0; i < V; ++i) {
        if (ans[i] == INF) {
            // 존재하지 않으면 INF
            cout << "INF" << endl;
            continue;
        }

        cout << ans[i] << endl;    
    }

    return 0;
}
