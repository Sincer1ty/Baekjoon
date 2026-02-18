class Solution {
    public:
        int numTilings(int n) {
            vector<int> dp;
            
            dp.push_back(1);
            dp.push_back(2);
            dp.push_back(5);
    
            for (int i = 3; i < n; i++){
                dp.push_back(((2 * dp[i - 1]) % 1000000007 + dp[i - 3]) % 1000000007);
            }
    
            return dp[n - 1] % 1000000007;
        }
    };