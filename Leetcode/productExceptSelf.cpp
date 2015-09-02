#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> result(nums.size(),0);
		long product = 1;
		vector<int> zeroIndex;

		for (int i = 0; i < nums.size(); i++){
			if (nums[i] == 0){
				//记录0的位置
				zeroIndex.push_back(i);
				//如果数组中有两个以上0，除自身外相乘全部为0，直接结束计算
				//如果有1个0,除本身外全部0
				if (zeroIndex.size()>=2)
					return result;
			}
			else{
				product *= nums[i];
			}
		}
		if (zeroIndex.size() == 1){
			result[zeroIndex[0]] = product;
		}
		else{
			for (int i = 0; i < nums.size(); i++){
				result[i] = product / nums[i];
			}
		}
		return result;
	}
};
//int main(){
//	Solution s;
//	vector<int> v = { 1, 2, 3, 4,5,0,7,8,9,0 };
//	vector<int> r=s.productExceptSelf(v);
//
//}