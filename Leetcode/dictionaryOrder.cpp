#include"leetcode.h"

class Solution{
public:
	int dictionaryOrder(string a, string b,int n,int m){
		if (a > b)
			return 0;
		int minSize = (a.size() < b.size() ? a.size() : b.size());
		int i = 0;
		for (; i < minSize; i++){
			if (a[i] != b[i]){
				break;
			}
		}
		int number = b[i] - a[i] + 1;
		vector<vector<int>> count(m, vector<int>(number, 1));
		for (int j = i + 1; j < m; j++){
			if (j>(a.size() - 1)){
				count[j][0] = count[j - 1][0] * 26;
			}
			else{
				count[j][0] = count[j - 1][0] * ('z' - a[j] );
			}
			for (int k = 1; k < number-1; k++){
				count[j][k] = count[j - 1][k] * 26;
			}
			if (j>(b.size() - 1)){
				count[j][number - 1] = count[j - 1][number - 1] * 26;
			}
			else{
				count[j][number - 1] = count[j - 1][number - 1] * (b[j]-'a');
			}
		}
		int sum = 0;
		for (int i = n-1; i < m; i++){
			for (int j = 0; j < number; j++){
				cout << count[i][j] << " ";
				sum += count[i][j];
			}
			cout << endl;
		}
		return (sum-1) % 1000007;
	}
};
//int main(){
//	Solution s;
//	cout<<s.dictionaryOrder("ab", "ce", 1,2);
//	return 0;
//}