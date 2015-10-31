#include"leetcode.h"
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size()<2)
			return 0;
		//		int where = -1;
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
			//i move to end but not determinate end is 0 or 1

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
//int main(){
//	vector<int> test= { 7,6,5,4,3,2,1,0 };
//	for (int i = 0; i < 20; i++){
//		test.push_back(rand() % 12321);
//	}
//	Solution s;
//	s.maximumGap(test);
//	cout << "here";
//	return 0;
//}