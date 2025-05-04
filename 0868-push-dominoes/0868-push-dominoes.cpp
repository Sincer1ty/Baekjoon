class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<signed char> secs(dominoes.size(), 0);
        string result = dominoes;
        int left = -1, right = -1;

        for (int i = 0; i <= dominoes.size(); i++) {
            char c = (i < dominoes.size()) ? dominoes[i] : 'R';  // 끝 처리

            if (c == 'L') {
                if (left < right) {
                    int low = right + 1, high = i - 1;

                    while (low < high) {
                        result[low++] = 'R';
                        result[high--] = 'L';
                    }
                }
                else {
                    // 지금까지 . 넘어뜨리기
                    for (int j = left + 1; j < i; j++) {
                        result[j] = 'L';
                    }
                }
                left = i;
                right = -1;
            }
            else if (c == 'R') {
                if (right > left) {
                    // 앞으로의 . 넘어뜨리기
                    for (int j = right + 1; j < i; j++) {
                        result[j] = 'R';
                    }
                }
                right = i;
            }
        }

        return result;
    }
};