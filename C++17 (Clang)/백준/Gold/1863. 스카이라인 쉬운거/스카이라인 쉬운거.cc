#include <iostream>
#include <queue>
#include <set>

using namespace std;

priority_queue<int> heights;
set<int> buildings;

void insert(int x) {
    if (buildings.insert(x).second) {  // 중복 아니면
        heights.push(x);
    }
}

void erase(int x) {
	buildings.erase(heights.top());
	heights.pop();
}

int main() {
	int n;
    cin >> n;
	
	int result = 0;
    for (int i = 0; i < n; i++) {
		int x, y;
        cin >> x >> y;
		// 제일 큰 것보다 작으면 
		while (!heights.empty() && y < heights.top())
		{
			// 그것보다 큰 애들은 다 아웃
			erase(y);
			result += 1;
		}
		if (y == 0) continue;
		insert(y);
    }
 
	// 최소 건물 개수
    cout << result + buildings.size() << endl;
	
    return 0;
}
