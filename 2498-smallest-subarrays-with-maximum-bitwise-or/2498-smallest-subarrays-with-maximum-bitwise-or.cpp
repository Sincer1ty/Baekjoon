class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
		// 각 비트가 마지막으로 등장한 인덱스
        vector<int> last_seen(32, -1);

        for (int i = n - 1; i >= 0; --i) {
            // 현재 값의 비트들을 기록
            for (int bit = 0; bit < 32; ++bit) {
                if (nums[i] & (1 << bit)) {
                    last_seen[bit] = i;
                }
            }

            // 현재 위치에서 도달해야 할 가장 먼 인덱스를 계산
            int max_idx = i;
            for (int bit = 0; bit < 32; ++bit) {
                if (last_seen[bit] != -1) {
                    max_idx = max(max_idx, last_seen[bit]);
                }
            }

            result[i] = max_idx - i + 1;
        }

        return result;
    }
};