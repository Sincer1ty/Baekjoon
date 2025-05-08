#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int count_glass;
	
	cin >> count_glass;

    vector<int> glasses(count_glass), dp(count_glass + 1);

    for (int i = 0; i < count_glass; i++) {
        cin >> glasses[i];
    }

    dp[0] = 0;
    dp[1] = glasses[0];
    dp[2] = glasses[0] + glasses[1];
    for (int i = 3; i <= count_glass; i++) {
        dp[i] = max(max(dp[i - 1], dp[i - 2] + glasses[i - 1]), dp[i - 3] + glasses[i - 2] + glasses[i - 1]);
    }
    
	cout << dp[count_glass];
    
	return 0;
}
