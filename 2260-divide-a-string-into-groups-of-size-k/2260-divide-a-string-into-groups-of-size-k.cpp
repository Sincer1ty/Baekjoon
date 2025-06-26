class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
		int idx = 0;
		vector<string> result;
		while(idx < s.size()) {
			string sample = s.substr(idx, k);
			if (sample.size() != k) {
				sample += string(k - sample.size(), fill);
			}
			result.push_back(sample);
			idx += k;
		}

		return result;
    }
};