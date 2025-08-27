#include <iostream>

using namespace std;

long long getXOR(long long n) {
	switch(n % 4) {
		case 0 : return n;
		case 1 : return 1;
		case 2 : return n + 1;
		case 3 : return 0;
	}
}

int main() {
    long long A, B;
    cin >> A >> B;

	B = getXOR(B);
	A = getXOR(A-1);

	long long result = 0;
	int n = 0;
	while (A || B) {
		if ((A & 1) != (B & 1)) result |= (1LL << n);

		A >>= 1;
		B >>= 1;
		++n;
	}

	cout << result << endl;

    return 0;
}
