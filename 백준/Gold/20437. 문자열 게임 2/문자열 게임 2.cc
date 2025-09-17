#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	int T;
    cin >> T;

	for (int i = 0; i < T; ++i) {
		string W;
		cin >> W;

		int K;
		cin >> K;

		int size = W.size();
		int answer = size, max = -1;

		unordered_map<char, vector<int>> m;
		for (int j = 0; j < size; ++j) {
			char c = W[j];
			m[c].push_back(j);

			if (m[c].size() >= K) {
				auto v = m[c];
				int len = v.size()-K+1;
				for (int i = 0; i < len; ++i) {
					int diff = v[i+K-1] - v[i];
					if (answer > diff) answer = diff;
					if (max < diff) max = diff;
				}
			}
		}

		if (max == -1) {
			cout << -1 << endl;
			continue;
		}
		
		cout << answer + 1 << " " << max + 1 << endl;
	}

    return 0;
}
