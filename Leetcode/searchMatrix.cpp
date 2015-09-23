#include<vector>
#include<iostream>

using namespace std;
class PPoint{
public:
	PPoint(int x, int y){
		this->x = x; 
		this->y = y;
	};
	PPoint(PPoint& p){
		this->x = p.x;
		this->y = p.y;
	}
	bool operator==(const PPoint &p){
		return (this->x == p.x) && (this->y == p.y);
	}

	int x;
	int y;
};

class Solution {
public:
	Solution(){};
//	Solution(vector<vector<int>>& matrix):_matrix(matrix){
//	};

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		this->_matrix = matrix;
		this->_target = target;
		PPoint begin(0, 0);
		PPoint end(matrix.size()-1, matrix[0].size()-1);
		return dividSearch(begin, end);
	}

	bool outOfrange(PPoint& p){
		return (p.x < this->_matrix.size()&&p.y < this->_matrix[0].size());
	}
	int getInt(PPoint& p){
		return (this->_matrix[p.x])[p.y];
	}

	bool dividSearch(PPoint& begin,PPoint& end){
		if (this->outOfrange(begin) && this->outOfrange(end)){
			if (begin == end){
				return this->getInt(begin) == this->_target;
			}
			else {
				if (this->_target<this->getInt(begin) || this->_target>this->getInt(end))
					return false;
				else{
					int cx = (begin.x + end.x) / 2;
					int cy = (begin.y + end.y) / 2;
					//			if (this->getInt(PPoint(cx, cy)) == this->_target){
					//				return true;
					//			}
					PPoint l1e(cx, cy);
					PPoint l4b(cx + 1, cy + 1);
					PPoint l2b(begin.x, cy + 1);
					PPoint l2e(cx, end.y);
					PPoint l3b(cx + 1, begin.y);
					PPoint l3e(end.x, cy);
					return dividSearch(begin, l1e) || dividSearch(l4b, end) || dividSearch(l2b, l2e) || dividSearch(l3b, l3e);
				}
			}
		}else
			return false;
	};
private:
	vector<vector<int>> _matrix;
	int _target;
};

