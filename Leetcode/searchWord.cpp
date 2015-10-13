#include"leetcode.h"

class Solution {
public:
	bool next(vector<vector<char>>& board, vector<vector<int>>& is, int i, int j, int index, string &word){
		if (index == word.size())
			return true;
		if (i >= 0 && i<board.size() && j >= 0 && j<board[0].size()){

			if (board[i][j] == word[index] && is[i][j] != 1){
				is[i][j] = 1;
				cout << index << "---" << board[i][j] << "  ";
				if (next(board, is, i - 1, j, index + 1, word) | next(board, is, i + 1, j, index + 1, word) | next(board, is, i, j - 1, index + 1, word) | next(board, is, i, j + 1, index + 1, word)){
					return true;

				}
				else{
					is[i][j] = 0;
					return false;
				}
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}

	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() <= 0)
			return false;
		vector<vector<int>> is(board.size(), vector<int>(board[0].size()));

		int index;

		for (int i = 0; i<board.size(); i++){
			for (int j = 0; j<board[0].size(); j++){
				if (board[i][j] == word[0]){
					index = 0;
					if (next(board, is, i, j, index, word) == true){
						return true;
					}
				}
			}
		}
		return false;
	}

};
//int main(){
//	vector<string> a = { "acccbaabba", "bbaacabcac", "cbcaababba", "accccacccb", "abaaaabbac", "bababbcbab", "aaacaabbcb", "ccbaababcb", "cacacaccba", "abbbccbbaa", "ababbacaac", "ccbbaacaab", "bbacaabcca", "acbbcacbaa" };
//	vector<vector<char> > res;
//	for (int i = 0; i < a.size(); i++){
//		vector<char> temp;
//		for (int j = 0; j < a[i].size(); j++){
//			temp.push_back(a[i][j]);
//		}
//		res.push_back(temp);
//	}
//	Solution s;
//	s.exist(res, "aaacabbbbaccbb");
//	return 0;
//}