class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string result = dominoes;
        int left = -1, right = -1;

        for (int i = 0; i <= n; i++) {
            char c = (i < n) ? dominoes[i] : 'R';  // 끝 처리

            if (c == 'R') {
                if (right > left) {
                    // 이전 R 이후 .들 전부 R로
                    for (int j = right + 1; j < i; j++) {
                        result[j] = 'R';
                    }
                }
                right = i;
            } else if (c == 'L') {
                if (right > left) {
                    // R ... L 사이 처리
                    int low = right + 1, high = i - 1;
                    while (low < high) {
                        result[low++] = 'R';
                        result[high--] = 'L';
                    }
                } else {
                    // 이전 L 이후 .들 전부 L로
                    for (int j = left + 1; j < i; j++) {
                        result[j] = 'L';
                    }
                }
                left = i;
                right = -1;
            }
        }

        return result;
    }
};
