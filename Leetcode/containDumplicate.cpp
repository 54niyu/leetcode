#include"leetcode.h"

class Solution{
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		for (int i = 0; i < nums.size(); i++){
			for (int j = 1; j <= k && (i + j) < nums.size(); j++){
				if (abs(nums[i + j] - nums[i]) < t)
					return true;
			}
		}
		return false;
	}
};
