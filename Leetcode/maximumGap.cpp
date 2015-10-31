#include"leetcode.h"
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size()<2)
			return 0;
		mysort(nums, 0, nums.size() - 1, 30);
		int max = -1;
		for (int i = 1; i<nums.size(); i++){
			if ((nums[i] - nums[i - 1])>max){
				max = nums[i] - nums[i - 1];
			}
		}
		return max;
	}
	void mysort(vector<int>& nums, int start, int end, int k){
		if (start <= end&&k >= 0){
			int i = start;
			int j = end;
			while (i < j){
				while (i < j&&digit(nums[i], k) == 0) i++;
				while (j > i&&digit(nums[j], k) == 1) j--;
				swap(nums[i], nums[j]);
			}

			//all 0 or 1
			if (digit(nums[end], k) == 0 || digit(nums[start], k) == 1){
				mysort(nums, start, end, k - 1);
			}
			else{
				mysort(nums, start, j - 1, k - 1);
				mysort(nums, j, end, k - 1);
			}
		}
	}
	int digit(const int &num, int index){
		if (((1 << index) & num) != 0)
			return 1;
		else
			return 0;
	}
};
