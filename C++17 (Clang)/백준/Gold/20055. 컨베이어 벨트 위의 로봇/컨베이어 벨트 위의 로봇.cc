#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> durability(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> durability[i];
    }

    vector<bool> isExist(2 * N, false);  // 로봇 존재 여부
    int result = 0;

    while (true) {
        result++;

        // 1. 벨트 + 로봇 회전
        rotate(durability.rbegin(), durability.rbegin() + 1, durability.rend());
        rotate(isExist.rbegin(), isExist.rbegin() + 1, isExist.rend());
        isExist[N - 1] = false;  // 내리는 위치의 로봇 내림

        // 2. 로봇 이동
        for (int i = N - 2; i >= 0; --i) {  // 뒤에서부터 체크해야 먼저 올라간 로봇부터 움직임
            if (isExist[i] && !isExist[i + 1] && durability[i + 1] > 0) {
                isExist[i] = false;
                isExist[i + 1] = true;
                durability[i + 1]--;
            }
        }
        isExist[N - 1] = false;  // 내리는 위치 다시 확인

        // 3. 로봇 올리기
        if (durability[0] > 0) {
            isExist[0] = true;
            durability[0]--;
        }

        // 4. 내구도 0인 칸 개수 확인
        if (count(durability.begin(), durability.end(), 0) >= K) break;
    }

    cout << result << endl;
    return 0;
}