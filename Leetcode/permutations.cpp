#include "leetcode.h"
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		generate(res, nums, vector<int>(nums.size(), -1), vector<int>());
		return res;
	}
	void generate(vector<vector<int>> &res, vector<int>& nums, vector<int> A, vector<int> r){
		if (r.size() == nums.size()){
			res.push_back(r);
			return;
		}
		bool isPush = false;
		for (int i = 0; i < nums.size(); i++){
			if (A.at(i) == -1){
				if (!isPush){
					A.at(i) = i;
					r.push_back(nums.at(i));
					generate(res, nums, A, r);
				//	r.pop_back();
					A.at(i) = -1;
					isPush = true;
				}
				else{
					if (nums.at(i) != r.back()){
						A.at(i) = i;
						r.back() = nums.at(i);
						generate(res, nums, A, r);
						A.at(i) = -1;
					}
				}
			}
		}

		return;
	}
};
//int main(){
//	vector<int> data = { 1,1,2,3 };
//	Solution s;
//	s.permute(data);
//	return 0;
//}