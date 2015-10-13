#include"leetcode.h"

class Solution{
public:
	vector<string> getGray(int n){
		vector<string> res;
		string s(n, '0');
		res.push_back(s);
		reverse(res, s, n, 0);
		return res;
	}
	void reverse(vector<string> &res,string s,int n,int step){
		if (step < ((1 <<n) -1)){
			s[n - 1] = 1 - (s[n - 1] - '0') + '0';
			res.push_back(s);
			reverse2(res,s,n,step+1);
		}
	}
	void reverse2(vector<string> &res,string s, int n, int step){
		if (step < ((1 <<n)-1)){
			for (int i = n - 1; i >= 0; i--){
				if (s[i] == '1'){
					s[i-1] = 1 - (s[i - 1] - '0') + '0';
					res.push_back(s);
					break;
				}
			}
			reverse(res, s, n, step + 1);
		}
	}
};
//int main(){
//	vector<string> res;
//	Solution s;
//	res=s.getGray(5);
//	sort(res.begin(), res.end());
//	return 0;
//}