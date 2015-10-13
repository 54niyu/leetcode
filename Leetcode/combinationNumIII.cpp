#include"leetcode.h"

class Solution{
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> res;
		vector<int> is(10, 0);
		for (int i = 1; i <= 9; i++){
			is[i] = 1;
			helper(res, is, i + 1, i, k - 1, n);
			is[i] = 0;
		}
		return res;
	}
	void helper(vector<vector<int>> &res, vector<int> &is, int start, int least, int k, int n){
		if (k == 0 && least == n){
			if (least == n){
				vector<int> temp;
				for (int i = 1; i < 10; i++){
					if (is[i] == 1)
						temp.push_back(i);
				}
				res.push_back(temp);
			}
		}
		if (k>0){
			for (int i = start; i <= 9; i++){
				is[i] = 1;
				helper(res, is, i + 1, least + i, k - 1, n);
				is[i] = 0;
			}
		}
	}
};
//int main(){
//	
//	Solution s;
//	s.combinationSum3(3,9);
//}