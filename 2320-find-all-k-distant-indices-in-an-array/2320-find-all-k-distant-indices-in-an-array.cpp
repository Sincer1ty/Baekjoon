class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
		vector<int> j;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == key) {
				j.push_back(i);
			}
		}

		// 겹치는 게 있으면 안됨
		set<int> result;
		for (int keyIdx : j) {
			for (int i = keyIdx - k; i <= keyIdx + k; ++i) {
		        // 인덱스 범위여야 함
				if (i < 0) {
					i = 0;
				}
				else if (i >= nums.size()) break;
				result.insert(i);
			}			
		}

		return vector<int>(result.begin(), result.end());
    }
};