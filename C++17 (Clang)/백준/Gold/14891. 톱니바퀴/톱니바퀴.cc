#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// N극 : 0, S극 : 1
int wheel[4][8];

void rot(int dir, int num, int* arr, int flag) {
    if (flag != -1 && num + 1 < 4) {
        int idx = num + 1;
        // 극이 다르면 반대방향 회전
        if (wheel[num][(arr[num]+2)%8] != wheel[idx][(arr[idx]+6)%8]) {
            rot(dir * -1, idx, arr, 1);
        }
    }
    if (flag != 1 && num - 1 >= 0) {
        int idx = num - 1;
        if (wheel[num][(arr[num]+6)%8] != wheel[idx][(arr[idx]+2)%8]) {
            rot(dir * -1, idx, arr, -1);
        }
    }

    // 회전
    if (dir > 0) {
        arr[num] = (arr[num] - 1 + 8) % 8;
    }
    else arr[num] = (arr[num] + 1) % 8;
}

int main() {
    // 톱니 4개
    int start[4] = {};
    int K;
    for (int i = 0; i < 4; ++i) {
        string line;
        cin >> line;
        
        for (int k = 0; k < 8; ++k) {
            wheel[i][k] = line[k] - '0';
        }
    }
    // K번 회전
    cin >> K;
    // 번호, 방향
    queue<pair<int, int>> q;
    for (int i = 0; i < K; ++i) {
        int num, dir;
        cin >> num >> dir;
        q.push({num-1, dir});
    }

    while (!q.empty()) {
        auto [num, dir] = q.front();
        q.pop();

        rot(dir, num, start, 0);
    }

    int score = 0;
    for (int i = 0; i < 4; ++i) {
        if (wheel[i][start[i]]) score += 1 << i;
    }

    cout << score << endl;

    return 0;
}

