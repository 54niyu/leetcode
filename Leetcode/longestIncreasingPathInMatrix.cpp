#include"leetcode.h"
class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {

		int row = matrix.size();
		if (row == 0)
			return 0;
		int col = matrix.at(0).size();
		if (col == 0)
			return 0;
		vector<vector<int>> adj(row*col);
		vector<bool> marked(row*col, false);
		vector<int> edgeTo(row*col, 0);

		int max = 0;

		for (int i = 0; i < matrix.size(); i++){
			for (int j = 0; j<matrix.at(i).size(); j++){
				if (j != col - 1){
					if (matrix[i][j]>matrix[i][j + 1]){
						adj[i*col + j + 1].push_back(i*col + j);
					}
					else if (matrix[i][j] < matrix[i][j + 1]){
						adj[i*col + j].push_back(i*col + j + 1);
					}
				}
				if (i != row - 1){
					if (matrix[i][j] > matrix[i + 1][j]){
						adj[(i + 1)*col + j].push_back(i*col + j);
					}
					else if (matrix[i][j] < matrix[i + 1][j]){
						adj[i*col + j].push_back((i + 1)*col + j);
					}
				}
			}
		}
		for (int i = 0; i<row*col; i++){
			if (!marked[i]){
				int len = dfs(adj, marked, edgeTo, i);
				if (len>max)
					max = len;
			}
		}
		return max;
	}

	int dfs(vector<vector<int>> &adj, vector<bool> &marked, vector<int> &edgeTo, int v){
		marked[v] = true;
		int max = 0;
		if (!adj.at(v).empty()){
			for (auto i : adj.at(v)){
				int len;
				if (!marked[i]){
					len = dfs(adj, marked, edgeTo, i);
				}
				else{
					len = edgeTo[i];
				}
				if (len>max)
					max = len;
			}
		}
		edgeTo[v] = max + 1;
		return max + 1;
	}
};
int main(){
	vector<vector<int>> matrix = { { 9, 9, 4 }, { 6, 6, 8 }, {2,1,1} };
	Solution s;
	s.longestIncreasingPath(matrix);
	return 0;
}