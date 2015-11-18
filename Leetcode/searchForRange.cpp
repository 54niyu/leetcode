#include"leetcode.h"
class Solution{
public:
	vector<int> searchForRange(vector<int> &nums, int target){
		int begin = 0;
		int end = nums.size() - 1;
		int middle;
		while (true){
			middle = begin + (end - begin) / 2;
			if (begin>end)
				return vector<int>(2, -1);
			if (nums[middle] == target)
				break;
			if (begin == end)
				return vector<int>(2, -1);
			if (target < nums[middle])
				end = middle - 1;
			else
				begin = middle + 1;
		}

		begin = middle;
		while (begin >= 0 && nums[begin] == target)
			begin--;
		begin++;
		end = middle;
		while (end<nums.size() && nums[end] == target)
			end++;
		end--;
		vector<int> res = { begin, end };
		return res;
	}
};
//int main(){
//	Solution s;
//	vector<int> t = { 1, 1, 2, 3, 4, 5, 6, 7, 9, 10, 12 };
//	
//	vector<int> res=s.searchForRange(t, 0);
//
//	return 0;
//}