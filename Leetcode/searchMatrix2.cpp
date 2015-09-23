#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int rows= matrix.size();
		int cols = matrix[0].size();
		int i = 0;
		int j = cols-1;
		while (j>=0&&i<rows){
			int comp = matrix[i][j];
			if (comp == target){
				return true;
			}
			else if (comp >target){
				j--;
			}
			else{
				i++;
			}
		}
		return false;
	}
};
