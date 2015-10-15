#include"leetcode.h"

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> angle;
		if (numRows == 0)
			return angle;
		angle.push_back(vector<int>(1, 1));
		if (numRows == 1)
			return angle;
		angle.push_back(vector<int>(2, 1));
		if (numRows == 2)
			return angle;

		for (int i = 3; i <= numRows; i++){
			vector<int> temp(angle.back().size() + 1, 1);
			for (int j = 1; j < temp.size() - 1; j++){
				temp[j] = angle.back()[j - 1] + angle.back()[j];
			}
			angle.push_back(temp);
		}
		return angle;
	}
};