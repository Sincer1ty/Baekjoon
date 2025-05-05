class Solution {
public:
    bool canAssign(int k, vector<int> tasks, vector<int> workers, int pills, int strength) {
        workers = vector<int>(workers.end() - k, workers.end());

        for (int i = k - 1; i >= 0; i--) {
            // 큰 일꾼 k명
            auto it = lower_bound(workers.begin(), workers.end(), tasks[i]);
            if (it != workers.end()) {
                workers.erase(it);
            } else {
                if (pills == 0) return false;
                it = lower_bound(workers.begin(), workers.end(), tasks[i] - strength);
                if (it == workers.end()) return false;
                workers.erase(it);
                pills--;
            }
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int count = 0;

        sort(workers.begin(), workers.end());
        sort(tasks.begin(), tasks.end());
        

        int low = 0, high = min(tasks.size(), workers.size());
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                count = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return count;
    }
};