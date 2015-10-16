#include"leetcode.h"
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		vector<vector<int>> dp(board.size(), vector<int>(board[0].size(), 0));
		dp[0][0] = (board[0][0] == 'O' ? 1 : 0);
		for (int i = 1; i < board.size(); i++){
			dp[i][0] = (board[i][0] == 'O' ? dp[i - 1][0] + 1 : 0);
		}
		for (int j = 1; j < board.size(); j++){
			dp[0][j] = (board[0][j] == 'O' ? dp[0][j-1] + 1 : 0);
		}
		for (int i = 1; i < board.size(); i++){
			for (int j = 1; j < board[i].size(); j++){
				if (board[i][j] == 'O')
					dp[i][j] = minzero(dp[i - 1][j], dp[i][j - 1]) + 1;
				else
					dp[i][j] = 0;
			}
		}
		for (int i = 0; i < board.size(); i++){
			for (int j = 0; j < board[i].size(); j++){
				cout << dp[i][j] << " ";
			}
			cout << "\n";
		}
		return;
	}
	int minzero(int x, int y){
		if (x == 0 && y == 0)
			return 0;
		else {
			if (x != 0 && y != 0){
				return (x <y ? x : y);
			}
			else if (x == 0){
				return y;
			}
			else {
				return x;
			}
		}
	}
};
int main(){
	int side = 10;
	vector<vector<char>> board(side, vector<char>(side));
	for (int i = 0; i < side; i++){
		for (int j = 0; j < side; j++){
			int a = rand() % 2;
			if (a == 1 )
				board[i][j]='X';
			else
				board[i][j]='O';
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	Solution s;
	s.solve(board);
	return 0; 
}