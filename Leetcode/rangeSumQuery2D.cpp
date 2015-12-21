#include "leetcode.h"
class NumMatrix {
public:
	NumMatrix(vector<vector<int>> &matrix) :_matrix(matrix){

	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		long sum = 0;
		for (int i = row1; i <= row2; i++){
			for (int j = col1; j <=col2; j++){
				sum += _matrix[i][j];
			}
		}

		return sum;
	}
	vector<vector<int>> _matrix;
};
int main(){

	vector<vector<int>> s = {
		{ 3, 0, 1, 4, 2 }, { 5, 6, 3, 2, 1 }, { 1, 2, 0, 1, 5 }, { 4, 1, 0, 1, 7 }, { 1, 0, 3, 0, 5 } };
	NumMatrix num(s);
	cout<<num.sumRegion(2,1,4,3);
}