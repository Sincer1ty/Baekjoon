#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
    cin >> N;

	int max_prev[3];
	
	cin >> max_prev[0] >> max_prev[1] >> max_prev[2];
	int min_prev[3];
	copy(max_prev, max_prev+3, min_prev);
	
	int max_score[3], min_score[3];
	for (int i = 1; i < N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		max_score[0] = a + max(max_prev[0], max_prev[1]);
		max_score[1] = b + max(max(max_prev[0], max_prev[1]), max_prev[2]);
		max_score[2] = c + max(max_prev[1], max_prev[2]);

		min_score[0] = a + min(min_prev[0], min_prev[1]);
		min_score[1] = b + min(min(min_prev[0], min_prev[1]), min_prev[2]);
		min_score[2] = c + min(min_prev[1], min_prev[2]);
		
		copy(max_score, max_score+3, max_prev);
		copy(min_score, min_score+3, min_prev);
	}
	
	cout << *max_element(max_prev, max_prev+3) << " " << *min_element(min_prev, min_prev+3) << endl;

    return 0;
}
