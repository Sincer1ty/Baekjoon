class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
		
		int max_and = nums[0], result = 1;
		int cur_and = nums[0];
		int max_result = 0;
		int i = 1;
		while (i < n) {
			cur_and &= nums[i];
			
			if (cur_and > max_and) { 
				max_and = cur_and;
				result = 1;
				max_result = result;
			}
			else if (max_and < nums[i]) {
				cur_and = nums[i];
				continue;
			}
			else if (cur_and == max_and) {
				++result;
			}
			else {
				max_result = max(result, max_result);
				if (i + 1 < n) {
					cur_and = nums[i + 1];
				} else {
					break;
				}
				result = 0;
			}
			++i;
		}

		return max(result, max_result);
    }
};