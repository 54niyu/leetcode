#include"leetcode.h"

class Solution {
public:
	int numSquares(int n) {
		int max = sqrt(n);
		vector<int> candidate(n+1, n);
		candidate[0] = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 0; j <= max; j++){
				if ((i - j*j >= 0) && candidate[i]>(candidate[i - j*j] + 1)){
					candidate[i] = candidate[i - j*j] + 1;
				}
			}
		}
		return candidate[n];
	}
};
//int main(){
//	Solution s;
//	s.numSquares(12);
//	return 0;
//}