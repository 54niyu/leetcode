#include "leetcode.h"
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		vector<int> temp;
		search(res, temp, 0, n);
		return res;
	}
	bool search(vector<vector<string>> &res, vector<int> pos, int row, int n){
		if (row >= n){
			stringstream s;
			vector<string> temp;
			for (auto item : pos){
				for (int i = 0; i < n; i++){
					if (i == item){
						s << 'Q';
					}
					else{
						s << '.';
					}
				}
				string ou;
				s >> ou;
				temp.push_back(ou);			
				s.clear();
			}
			res.push_back(temp);

			return true;
		}

		for (int i = 0; i < n; i++){
			bool isOk = true;

			for (int j = 0; j < pos.size(); j++){
				if (isSame(j, pos.at(j), row, i)){
					isOk = false;
					break;
				}
			}
			if (isOk){
				pos.push_back(i);
				search(res, pos, row + 1, n);
				pos.pop_back();
			}
		}
		return false;
	}
	bool isSame(int x1, int y1, int x2, int y2){
		return (y1 == y2) || (x1 - y1 == x2 - y2) || (x1 + y1 == x2 + y2);
	}
};
//int main(){
//	Solution s;
//	s.solveNQueens(8);
//	return 0;
//}