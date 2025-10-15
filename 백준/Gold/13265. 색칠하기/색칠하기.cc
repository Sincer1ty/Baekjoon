#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n;
unordered_map<int, vector<int>> adj;

bool dfs(int from, vector<int>& color) {
	for (auto node : adj[from]) {
		int c = color[node-1];
		if (c == 0){
			color[node-1] = color[from-1] * -1;
		}
		else {
			if (c == color[from-1]) {
				return false;
			}
			else {
				continue;
			}
		}
		
		dfs(node, color);
	}

	return true;
}

bool isPossible() {
	vector<int> color(n);
	
	for (int j = 1; j <= n; ++j) {
		if (color[j-1] != 0) continue;

		color[j-1] = 1;
		if (!dfs(j, color)) return false;
	}
	return true;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		int m;
		cin >> n >> m;

		adj.clear();
		for (int j = 0; j < m; ++j) {
			int x, y; // 동그라미 번호 두 개
			cin >> x >> y;

			adj[x].push_back(y);
			adj[y].push_back(x);


		}
		
		// possible or impossible
		if (isPossible()) cout << "possible" << endl;
		else cout << "impossible" << endl;
	}
	
    return 0;
}
