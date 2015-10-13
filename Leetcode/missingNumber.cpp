#include"leetcode.h"

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int extra=0;
		for (int i = 0; i<=nums.size(); i++){
			extra ^= (i == nums.size() ? i : i^nums[i]);
		}
		return extra;
	}
};
//int main(){
//	Solution s;
//	vector<int> a = { 1,2,5,4,3,6};
//	s.missingNumber(a);
//}