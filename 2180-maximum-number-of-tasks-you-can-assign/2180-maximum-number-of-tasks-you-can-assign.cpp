class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> ws(workers.end() - k, workers.end());  // 큰 일꾼 k명
        int p = pills;

        for (int i = k - 1; i >= 0; i--) {
            auto it = ws.lower_bound(tasks[i]);
            if (it != ws.end()) {
                ws.erase(it);
            } else {
                if (p == 0) return false;
                it = ws.lower_bound(tasks[i] - strength);
                if (it == ws.end()) return false;
                ws.erase(it);
                p--;
            }
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0, high = min(tasks.size(), workers.size()), res = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }
};
