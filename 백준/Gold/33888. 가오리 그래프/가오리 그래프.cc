#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> edges;

// 노드 역할 인덱스
const int HEAD = 0;
const int LEFT_WING = 1;
const int CENTER = 2;
const int RIGHT_WING = 3;
const int LOW_WING = 4;
const int TAIL = 5;

int cores[6];

vector<bool> isVisited;
queue<int> q;

bool isTail(int node) {
    return edges[node].size() == 1;
}

bool isCenter(int node) {
    return edges[node].size() == 4;
}

bool isCore(int node) {
    return edges[node].size() != 2;
}

void findTail() {
    for (int i = 1; i <= N + 3; i++) {
        if (isTail(i)) {
            cores[TAIL] = i;
            return;
        }
    }
}

void findLowWing() {
    q.push(cores[TAIL]);
    isVisited[cores[TAIL]] = true;

    while (!q.empty()) {
        int current = q.front(); q.pop();
        for (int next : edges[current]) {
            if (isVisited[next]) continue;
            if (isCore(next)) {
                cores[LOW_WING] = next;
                return;
            }
            q.push(next);
            isVisited[next] = true;
        }
    }
}

void findMidWings() {
    cores[LEFT_WING] = INT_MAX;
    cores[RIGHT_WING] = 0;

    q.push(cores[LOW_WING]);
    isVisited[cores[LOW_WING]] = true;

    while (!q.empty()) {
        int current = q.front(); q.pop();

        for (int next : edges[current]) {
            if (isVisited[next]) continue;
            isVisited[next] = true;

            if (isCenter(next)) {
                cores[CENTER] = next;
                continue;
            }

            if (isCore(next)) {
                cores[LEFT_WING] = min(cores[LEFT_WING], next);
                cores[RIGHT_WING] = max(cores[RIGHT_WING], next);
                continue;
            }

            q.push(next);
        }
    }
}

void findHead() {
    q.push(cores[CENTER]);
    isVisited[cores[CENTER]] = true;

    while (!q.empty()) {
        int current = q.front(); q.pop();

        for (int next : edges[current]) {
            if (isVisited[next]) continue;

            if (isCore(next)) {
                cores[HEAD] = next;
                continue;
            }

            q.push(next);
            isVisited[next] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    edges.resize(N + 4); // 노드 1~N+3
    for (int i = 0; i < N + 3; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    fill(cores, cores+6, 0);
    isVisited.assign(N + 4, false);

    findTail();
    findLowWing();
    findMidWings();
    findHead();

    for (int i = 0; i < 6; i++) {
        cout << cores[i] << " ";
    }
    cout << "\n";

    return 0;
}
