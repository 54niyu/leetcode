#include"leetcode.h"
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> temp;
		if (k == 0){
			res.push_back(temp);
			return res;
		}

		_n = n;
		for (int i = 0; i<_n; i++){
			combine(res, temp, i, k);
		}
		return res;
	}
	void combine(vector<vector<int>> &res, vector<int>temp, int start, int index){
		if (index == 1 && start<_n){
			temp.push_back(start + 1);
			res.push_back(temp);
			return;
		}
		if (start<_n){
			temp.push_back(start + 1);
			for (int i = start + 1; i<_n; i++){
				combine(res, temp, i, index - 1);
			}
		}
	}
	int _n;
};