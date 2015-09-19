#include"leetcode.h"

#define ISOK(n) (n<side)

class Solution{
public:
	int min(int x, int y, int z){
		return x < y ? (x < z ? x : z) : (y < z ? y : z);
	}
	int maximalSquare(vector<vector<char>>& matrix) {
		int row = matrix.size();
		if (row < 0) return 0;
		int col = matrix[0].size();

		vector<vector<int>> m(row, vector<int> (col));
		int max = 0;

		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
	
				m[i][j] = matrix[i][j] - '0';

				if (i != 0 && j != 0 && m[i][j]>0){
					m[i][j] = min(m[i - 1][j], m[i][j - 1], m[i - 1][j - 1])+1;
				}

				if (m[i][j]>max)
					max = m[i][j];
			}
		}

		return max;
	}
};

//int main(){
//	
//	vector<char> s1 = { '1', '0', '1', '0', '0', };
//	vector<char> s2 = { '1', '0', '1', '1', '1', };
//	vector<char> s3 = { '1', '0', '1', '1', '1', };
//	vector<char> s4 = { '1', '1', '1', '1', '1', };
//	vector<char> s5 = { '1', '0', '1', '0', '0', };
//	vector<vector<char>> s = {s1,s2,s3,s4,s5};
//	
//
//	Solution ss;
//	cout<<ss.maximalSquare(s);
//
//	return 0;
//}