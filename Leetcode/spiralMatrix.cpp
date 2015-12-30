#include "leetcode.h"
enum Dir{
	Up,
	Down,
	Left,
	Right
};
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;

		int top = 1, bottom = matrix.size() - 1, left = 0, right = matrix.at(0).size() - 1;

		int size = matrix.size()*matrix.at(0).size();

		int i = 0, j = 0;
		Dir dir = Right;

		while (size > 0){

			switch (dir){
			case Right:{
				if (j < right){
					res.push_back(matrix[i][j]);
					j++;
				}
				else{
					// j--;
					res.push_back(matrix[i][j]);
					i++;
					dir = Down;
					right--;
				}
			}; break;
			case Down:{
				if (i < bottom){
					res.push_back(matrix[i][j]);
					i++;
				}
				else{
					res.push_back(matrix[i][j]);
					j--;
					dir = Left;
					bottom--;
				}
			}; break;
			case Left:{
				if (j > left){
					res.push_back(matrix[i][j]);
					j--;
				}
				else{
					res.push_back(matrix[i][j]);
					i--;
					dir = Up;
					left++;
				}
			}; break;
			case Up:{
				if (i > top){
					res.push_back(matrix[i][j]);
					i--;
				}
				else{
					res.push_back(matrix[i][j]);
					j++;
					dir = Right;
					top++;
				}
			}; break;
			}
			size--;
		}
		return res;
	}
};
//int main(){
//
//	vector<vector<int>> r = { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 }, { 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 }, { 31, 32, 33, 34, 35, 36, 37, 38, 39, 40 }, { 41, 42, 43, 44, 45, 46, 47, 48, 49, 50 }, { 51, 52, 53, 54, 55, 56, 57, 58, 59, 60 }, { 61, 62, 63, 64, 65, 66, 67, 68, 69, 70 }, { 71, 72, 73, 74, 75, 76, 77, 78, 79, 80 }, { 81, 82, 83, 84, 85, 86, 87, 88, 89, 90 }, { 91, 92, 93, 94, 95, 96, 97, 98, 99, 100 } };
//	Solution s;
//	s.spiralOrder(r);
//	return 0;
//}