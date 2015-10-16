#include"leetcode.h"

class Solution{
public:
	int getMost(vector<vector<int>> &board){
		
		vector<vector<int>> most(6, vector<int>(6, 0));
		most[0][0] = board[0][0];
		for (int j = 1; j < 6; j++){
			most[0][j] = most[0][j-1] + board[0][j];
		}
		for (int i = 1; i < 6; i++){
			most[i][0] = most[i-1][0] + board[i][0];
		}
		for (int i = 1; i < 6; i++){
			for (int j = 1; j < 6; j++){
				most[i][j] = max(most[i - 1][j], most[i][j - 1]) + board[i][j];
			}
		}

		return most[5][5];
	}
};
int main(){
	Solution s;
	vector<vector<int>> da = {
		{426, 306, 641, 372, 477, 409}, 
		{223, 172, 327, 586, 363, 553}, 
		{292, 645, 248, 316, 711, 295}, 
		{127, 192, 495, 208, 547, 175}, 
		{131, 448, 178, 264, 207, 676}, 
		{655, 407, 309, 358, 246, 714}
	};
	s.getMost(da);
}