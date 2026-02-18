class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // size : n
		// max diff 
		// 없으면 -1
		// i < j, nums[i] < nums[j]
		// 음 sort 하면? -> 인덱스 더 뒤에 있는 것만 봐야 해서
		int max = -1;

		for (int i = 0; i < nums.size(); i++) {
			for (int j = i+1; j < nums.size(); j++) {
				int cmp = nums[j] - nums[i];
				if (cmp != 0 && max < cmp) max = cmp;
			}
		}

		return max;
    }
};