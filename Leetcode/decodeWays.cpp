#include"leetcode.h"
class Solution {
public:
	int numDecodings(string s) {
		if (s.size() == 0)
			return 0;
		if (s[0] == '0')
			return 0;
		int zero = 1;
		int one = 1;
		int two;

		for (int i = 1; i<s.size(); i++){
			two = 0;
			//[0,3-9]0非法情况
			if (s[i] == '0' && (s[i - 1] == '0' || s[i - 1]>'2'))
				return 0;
			//[0-9][1-9] 一位
			if (s[i] != '0'){
				two += one;
			}
			//[1-2][0-6] 二位
			if ((s[i - 1] == '2'&&s[i] <= '6') || (s[i - 1] == '1')){
				two += zero;
			}
			zero = one;
			one = two;
		}

		return one;
	}
};
//int main(){
//	Solution s;
//	cout<<s.numDecodings("101");
//	return 0;
//}