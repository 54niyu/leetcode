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
				//��¼0��λ��
				zeroIndex.push_back(i);
				//�������������������0�������������ȫ��Ϊ0��ֱ�ӽ�������
				//�����1��0,��������ȫ��0
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