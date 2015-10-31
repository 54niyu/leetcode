#include"leetcode.h"

//class Solution {
//public:
//	string largestNumber(vector<int>& nums) {
//		stringstream st;
//		vector<string> snums;
//		string s;
//		for (auto n : nums){
//			st << n;
//			st >> s;
//			st.clear();
//			snums.push_back(s);
//		}
//		sort(snums.begin(), snums.end(), compare);
//
//		if (snums[0] == "0")
//			return "0";
//	
//		string res = "";
//		for (auto item : snums)
//			res += item;
//
//		return res;
//	}
//	bool compare(string a, string b){
//		return (a + b) > (b + a);
//	}
//};
//int main(){
//	Solution s;
//	vector<int> temp;
//	for (int i = 999; i >=100; i--){
//		temp.push_back(i);
//	}
//	s.largestNumber(temp);
//	return 0;
//}

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		vector<vector<int>> dp(nums.size(),nums);
		int max = nums[0];
		for (int i = 1; i < nums.size(); i++){
			for (int j = 0; j + i < dp[i].size(); j++){
				dp[i][j]  =dp[i-1][j]+nums[j + i];
				if (dp[i][j] > max)
					max = dp[i][j];
			}
		}
		return max;
	}
};
int main(){
	Solution s;
	vector<int> temp = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout<<s.maxSubArray(temp);
	return 0;
}
