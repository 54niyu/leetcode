#include"leetcode.h"
class Solution {
public:
	vector<vector<int>> subsetsII(vector<int>& nums) {
		vector<vector<int>> result;
		set<vector<int>> key;
		int num = nums.size();
		int max = (1<< num) - 1;
		for (int i = 0; i <= max; i++){
			vector<int> temp;
			for (int j = 0; j<num; j++){
				if (((1 << j)&i) != 0){
					temp.push_back(nums[j]);
				}
			}
			key.insert(temp);
		}

		auto begin = key.begin();
		while (begin != key.end()){
			result.push_back(*begin);
			begin++;
		}
		return result;
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		int num = nums.size();
		int max = (1 << num) - 1;
		for (int i = 0; i <= max; i++){
			vector<int> temp;
			for (int j = 0; j < num; j++){
				if (((1 << j)&i) != 0){
					temp.push_back(nums[j]);
				}
			}
			result.push_back(temp);
		}
		// result.push_back(vector<int> a);
		return result;
	}

};
//int main(){
//	Solution s;
//	vector<int> a = { 0, 1, 2, 3 };
//	s.subsets(a);
//	return 0;
//}