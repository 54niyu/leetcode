#include"leetcode.h"
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int count = 0;

		for (int i = 0; i<grid.size(); i++){
			for (int j = 0; j<grid.at(i).size(); j++){
				if (grid[i][j] != '0'){
					count++;
					bfs(grid, i, j);
				}
			}
		}
		return count;	
	}
	void bfs(vector<vector<char>>& grid, int x, int y){
		if (x >= 0 && x<grid.size() && y >= 0 && y<grid.at(x).size()){
			if (grid[x][y] != '0'){
				grid[x][y] = '0';
				bfs(grid, x + 1, y);
				bfs(grid, x - 1, y);
				bfs(grid, x, y - 1);
				bfs(grid, x, y + 1);
			}
		}
	}
};
//int main(){
//	Solution s;
//	vector<vector<char>> grid = { { '1', '1', '0', '0', '0' }, { '1', '1', '0', '0', '0' }, { '0', '0', '1', '0', '0' }, { '0', '0', '0', '1', '1' } };
//	s.numIslands(grid);
//
//	return 0;
//}