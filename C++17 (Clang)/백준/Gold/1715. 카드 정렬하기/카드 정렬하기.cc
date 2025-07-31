#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

int main() {
    cin >> N;
	
   	// 최소 힙
	priority_queue<int, vector<int>, greater<int>> group;
	for (int i = 0; i < N; ++i) {
		int size;
		cin >> size;
		group.push(size);
	}

	int result = 0;
	while(group.size() > 1) {
		auto x = group.top();
		group.pop();

		auto y = group.top();
		group.pop();

		x += y;
		result += x;
		group.push(x);
	}

	cout << result << endl;

    return 0;
}