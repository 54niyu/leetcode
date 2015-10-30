#include"leetcode.h"
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size()<2)
			return 0;
		return mysort(nums, 0, nums.size() - 1, 30);
	}
	int mysort(vector<int>& nums, int start, int end, int k){
		if (start <= end&&k >= 0){
			int i = start;
			int j = end;
			while (i < j){
				while (i < j&&digit(nums[i], k) == 0) i++;
				while (j > i&&digit(nums[j], k) == 1) j--;
				swap(nums[i], nums[j]);
			}
			if (digit(nums[end], k) == 0)
				j++;
			mysort(nums, start, j - 1, k - 1);
			mysort(nums, j, end, k - 1);
		}
	}
	int digit(const int &num, int index){
		if (((1 << index) & num) != 0)
			return 1;
		else
			return 0;
	}
};
int main(){
	vector<int> test= { 23, 4123, 22, 123321, 21, 94, 528, 2945, 201, 10 };
	Solution s;
	s.maximumGap(test);
	cout << "here";
	return 0;
}