#include"leetcode.h"
class Solution {
public:
	int singleNumber(vector<int>& nums) {

		vector<int> bit(32, 0);
		int temp = 0;
		for (int i = 0; i<nums.size(); i++){
			temp = nums[i];
			for (int i = 0; i<32; i++){
				if (((1 << i)&temp) != 0){
					bit[i] = (bit[i] + 1) % 3;
				}
			}
		}
		temp = 0;
		for (int i = 0; i<32; i++){
			if (bit[i] == 1){
				temp += (1 << i);
			}
		}
		return temp;
	}
};
//int main(){
//	vector<int> s = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 5, 5, 5, 6, 6, 6 };
//	Solution ss;
//	cout<<ss.singleNumber(s);
//	return 0;
//}