class Solution {
public:
	vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
		vector<vector<string>> str_list;

		for (int i = 0; i < words.size(); i++) {
			vector<string> str = {words[i]};
			int temp = i;
			for (int j = i; j < words.size(); j++) {
				if (groups[temp] != groups[j])	{
					temp = j;
					str.push_back(words[j]);
				}
			}
			str_list.push_back(str);
		}

		auto longest = *max_element(str_list.begin(), str_list.end(),
			[](const auto& a, const auto& b) {
				return a.size() < b.size();
			});
		return longest;	
	}
};