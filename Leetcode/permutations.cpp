#include "leetcode.h"
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		generate(res, nums, vector<int>(nums.size(), -1), vector<int>(),0, nums.size());
		return res;
	}
	void generate(vector<vector<int>> &res, vector<int>& nums, vector<int> A,vector<int> r, int index, int size){
		if (index == size){
			res.push_back(r);
			return;
		}

		for (int i = 0; i < size; i++){
			if (A.at(i) == -1){
				A.at(i) = i;
				r.push_back(nums.at(i));
				generate(res, nums, A, r,index + 1, size);
				A.at(i) = -1;
			}
		}

		return;
	}
};
int main(){
	vector<int> data = { 1, 2, 3, 4, 5, 6, 7 };
	Solution s;
	s.permute(data);
	return 0;
}