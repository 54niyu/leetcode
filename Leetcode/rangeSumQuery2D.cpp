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
