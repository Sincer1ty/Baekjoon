class Solution {
public:
    int longestSubsequence(string s, int k) {
        // k보다 작거나 같은 2진수인 것들 중 문자열 길이가 가장 긴 부분 수열
		
		int max = (int)log2(k);
		int size = s.size() - 1;
		int result = 0, total = 0;

		for (int i = size; i >= 0; --i) {
			if (s[i] == '1') {
				int now = size - i;
				if (now <= max) {
					total += (1 << now);
					if (total <= k) result++;
				}
			}
			else result++;
		}

		return result;
    }
};