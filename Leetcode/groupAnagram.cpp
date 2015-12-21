#include "leetcode.h"
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		if (strs.empty()) return res;

		map<string, vector<string>> group;

		for (auto anagram : strs){
			string key(anagram);
			sort(key.begin(), key.end());
			
			group[key].push_back(anagram);
		}
		for (auto &item : group){
			sort(item.second.begin(), item.second.end());
			res.push_back(item.second);
		}
		return res;
	}
};