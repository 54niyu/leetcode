#include"leetcode.h"
typedef pair<int, int> Point;
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		
		for(int i=0; i < board.size(); i++){
			if (board[i][0] == 'O')
				bfs(board, i, 0);
			if (board[i][board[i].size() - 1] == 'O')
				bfs(board, i, board[i].size() - 1);
		}
		for (int i = 0; i < board[0].size(); i++){
			if (board[0][i] == 'O')
				bfs(board, 0, i);
			if (board[board.size()-1][i] == 'O')
				bfs(board, board.size()-1, i);
		}

		for (int i = 0; i < board.size(); i++){
			for (int j = 0; j < board[i].size(); j++){
				if (board[i][j] == 'C')
					board[i][j] = 'O';
				else
					board[i][j] = 'X';
			}
		}
	}
	void bfs(vector<vector<char>> &board,int i,int j){
		queue<Point> Q;
		Q.push(Point(i, j));

		while (!Q.empty()){
			Point temp = Q.front();

			if (board[temp.first][temp.second] == 'C'){
				Q.pop();
				continue;
			}

			board[temp.first][temp.second] = 'C';
			Q.pop();
			if (temp.first>0&&board[temp.first - 1][temp.second] == 'O'){
				Q.push(Point(temp.first - 1, temp.second  ));
			}
			if (temp.first<board.size()-1&&board[temp.first + 1][temp.second  ] == 'O'){
				Q.push(Point(temp.first + 1, temp.second  ));
			}
			if (temp.second<board[0].size()-1&&board[temp.first  ][temp.second + 1] == 'O'){
				Q.push(Point(temp.first  , temp.second + 1));
			}
			if (temp.second>0&&board[temp.first ][temp.second - 1] == 'O'){
				Q.push(Point(temp.first  , temp.second - 1));
			}
		}
	}

};
int main(){
	int side = 14;
	vector<vector<char>> board(side, vector<char>(side,'O'));
	//for (int i = 0; i < side; i++){
	//	for (int j = 0; j < side; j++){
	//		int a = rand() % 2;
	//		if (a == 1)
	//			board[i][j] = 'X';
	//		else
	//			board[i][j] = 'O';
	//		cout << board[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	Solution s;
	s.solve(board);
	cout << "---after modifiled\n";
	for (int i = 0; i < side; i++){
		for (int j = 0; j < side; j++){
//			int a = rand() % 2;
//			if (a == 1)
//				board[i][j] = 'X';
//			else
//				board[i][j] = 'O';
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	return 0; 
}
