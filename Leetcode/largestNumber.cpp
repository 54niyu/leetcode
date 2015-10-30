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