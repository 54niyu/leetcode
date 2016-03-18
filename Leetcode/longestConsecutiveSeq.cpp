#include"leetcode.h"
#include<unordered_map>

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, pair<int,int>> mark;
		for (auto i : nums)
			mark.insert({ i, { i, 1 } });
		int max = 1;
		for (auto i : nums){
			if (mark.find(i + 1) != mark.end()){
				int r1 = find(mark, i);
				int r2 = find(mark, i + 1);
				if (r1 != r2){
					mark[r1].first = r2;
					mark[r2].second += mark[r1].second;
					if (mark[r2].second > max)
						max = mark[r2].second;
				}
			}
		}
		return max;
	}
	int find(unordered_map<int,pair<int,int>> &m, int i){
		while (i != m[i].first)
			i = m[i].first;
		return i;
	}
};
//int main(){
//	Solution s;
//	vector<int> res = { 5, 4, 6, 3, 2, 7, 1, -1, 8 };
//	s.longestConsecutive(res);
//	return 0;
//}