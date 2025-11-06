#include <iostream>
#include <set>

using namespace std;

int main() {
	int p1, p2, p3, i;
	cin >> p1 >> p2 >> p3 >> i;

    set<long long> H({p1, p2, p3});

    int idx = 1;
    for (auto h : H) {
        if (idx >= i) {
            cout << h << endl;
            return 0;
        }
        H.insert({h * p1, h * p2, h * p3});

        idx++;
    }

    return 0;
}
