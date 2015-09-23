#include"leetcode.h"
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int majority1, cnt1, majority2, cnt2;
		majority1 = majority2 = cnt1 = cnt2 = 0;

		for (auto item : nums){
			if (cnt1 == 0){
				majority1 = item;
				cnt1++;
			}
			else if (item == majority1){
				cnt1++;
			}
			else if (cnt2 == 0){
				majority2 = item;
				cnt2++;
			}
			else if (item == majority2){
				cnt2++;
			}
			else{
				cnt1--;
				cnt2--;
			}
		}

		cnt1 = cnt2 = 0;
		for (auto item : nums){
			if (item == majority1){
				cnt1++;
			}
			else if (item == majority2){
				cnt2++;
			}
		}

		vector<int> result;
		if(cnt1>nums.size()/3) result.push_back(majority1);
		if(cnt2>nums.size()/3) result.push_back(majority2);
		return result;
	}
};
//int main(){
//	Solution s;
//	vector<int> data = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 2, 3, 4, 5, 6, 7, 8 };
//	vector<int> result = s.majorityElement(data);
//	return 0;
//}