#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
	cin >> N;

	vector<int> dp(N + 1);
	for (int i = 1; i <= N; ++i) {
		int time, pay;
		cin >> time >> pay;
		
		dp[i] = max(dp[i - 1], dp[i]);
		int end = i + time - 1;
		if (end <= N) dp[end] = max(pay + dp[i - 1], dp[end]);
	}

	cout << dp[N] << endl;

    return 0;
}