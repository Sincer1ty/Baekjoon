#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

vector<pii> houses;
vector<pii> chickens;

int N, M;
int answer = INT_MAX;

int getChickenDist(const vector<pii>& selectedChickens) {
    int total = 0;
    for (auto house : houses) {
        int minDist = INT_MAX;
        for (auto chicken : selectedChickens) {
            int dist = abs(house.first - chicken.first) + abs(house.second - chicken.second);
            minDist = min(minDist, dist);
        }
        total += minDist;
    }
    return total;
}

void dfs(int idx, vector<pii>& current) {
    if (current.size() == M) {
        answer = min(answer, getChickenDist(current));
        return;
    }

    for (int i = idx; i < chickens.size(); i++) {
        current.push_back(chickens[i]);
        dfs(i + 1, current);
        current.pop_back();
    }
}

int main() {
    
    // 입력 받기
    // 가장 수익을 많이 낼 수 있는 치킨집 M개
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;

            if (x == 1) houses.push_back({i, j});
            else if (x == 2) chickens.push_back({i, j});
        }
    }

    vector<pii> current;
    dfs(0, current);
    cout << answer << '\n';

    return 0;
}