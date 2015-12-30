#include "leetcode.h"
class Solution {
public:
	string getPermutation(int n, int k) {
		k--;
		string res;
		vector<int> myset;
		for (int i = 1; i <= n; i++){
			myset.push_back(i);
		}

		vector<int> pos;
		int i = 1;
		while (i <= n){
			if (k == 0){
				pos.push_back(0);
			}
			else{
				pos.push_back(k%i);
				k /= i;
			}
			i++;
		}
		cout << "here" << endl;
		for (int i = pos.size() - 1; i >= 0; i--){
			//  cout<<p<<" ";
			res = res + (char)(myset.at(pos.at(i)) + '0');
			myset.erase(myset.begin() + pos.at(i), myset.begin() + pos.at(i) + 1);
		}
		return res;
	}
};
//int main(){
//	Solution s;
//	cout<<s.getPermutation(4, 4);
//	return 0;
//}