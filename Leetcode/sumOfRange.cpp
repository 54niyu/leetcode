#include"leetcode.h"
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;

		char buff[100] = "";
		int start = 0, end = 0, state = 0;

		for (int i = 0; i<nums.size(); i++){
			cout << i << endl;
			if (state == 0){
				start = i;
				state = 1;
			}
			else if (state == 1){
				if (nums.at(i) != nums.at(i - 1) + 1){
					i--;
					state = 0;
					sprintf_s(buff, "%d->%d", start, i);
					string temp(buff);
					cout << temp << endl;
					res.push_back(temp);
				}
			}
			else{

			}
		}
		return res;
	}
};

//int main(){
//	vector<int> res = { 0, 1, 2, 4, 5, 7 };
//	Solution s;
//	s.summaryRanges(res);
//	return 0;
//}