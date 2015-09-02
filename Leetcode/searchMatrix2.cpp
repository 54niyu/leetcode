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
//int main(){
//	vector<int> a1 = {
//		1, 4, 7, 11, 15
//	};
//	vector<int> a2 = {
//		2, 5, 8, 12, 19
//	};
//	vector<int> a3 = {
//		3, 6, 9, 16, 22
//	};
//	vector<int> a4 = {
//		10, 13, 14, 17, 24
//	};
//	vector<int> a5 = {
//		18, 21, 23, 26, 30
//	};
//	vector<vector<int>> matrix = {
//		a1, a2, a3, a4, a5
//	};
//	//	Solution solution(matrix);
//
//	Solution solution;
//	//	solution.searchMatrix(matrix, 20);
//	for (int i = 0; i < matrix.size(); i++){
//		for (int j = 0; j < matrix[i].size(); j++){
//			cout << solution.searchMatrix(matrix, matrix[i][j]);
//		}
//		cout << endl;
//	}
//	cout << solution.searchMatrix(matrix, 20);
//	return 0;
//
//}