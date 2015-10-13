#include"leetcode.h"
class Solution{
public:
	int SearchArea(vector<int> A, int n){
		int max = 0;

		//正向
		for (int i = 0; i<n; i++){
			int count = 0;
			for (int j = i; j<n; j++){
				if (A[j] >= A[i]){
					count++;
				}
				else{
					break;
				}
			}
			//反向
			for (int j = i - 1; j >= 0; j--){
				if (A[j] >= A[i]){
					count++;
				}
				else{
					break;
				}
			}
			int area = count*A[i];
			if (max<area){
				max = area;
			}
		}
		return max;
	}
};
//int main(){
//	vector<int> ss = { 5386, 5384, 11054, 6345, 5816, 11757 };
//	Solution s;
//	cout<<s.SearchArea(ss, 6);
//	return 0;
//}