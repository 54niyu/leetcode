#include"leetcode.h"

enum Dir{
	Up,
	Down,
	Left,
	Right,
};
class Solution{
public:
	vector<vector<int>> crush(int n){
		int side=n*2+1;

		vector<vector<int>> data(side, vector<int>(side, 0));
		int max = side*side;
		int left, right, top, bottom;
		Dir dir=Left;

		//上下左右边界，撞到边界修改方向
		left = 0; top = 1; right = side-1; bottom = side-1;
		//初始方向向左
		dir = Left;

		int i, j;
		//从右上角元素开始
		i = 0; j = side-1;

		while (max >= 1){

			switch (dir){
			case Left:{
					  if (j == left) {
						  data[i][j] = max--;
						  dir = Down;
						  i++;
						  left++;
					  }
					  else{
						  data[i][j] = max--;
						  j--;
					  }
			}; break;
			case Right:{
					   if (j == right){
						   data[i][j] = max--;
						   dir = Up;
						   i--;
						   right--;
					   }
					   else{
						   data[i][j] = max--;
						   j++;
					   }
			}; break;
			case Up:{
					if (i == top){
						top++;
						data[i][j] = max--;
						dir = Left;
						j--;

					}
					else{
						data[i][j] = max--;
						i--;
					}
			}; break;
			case Down:{
					  if (i == bottom){
						  bottom--;
						  data[i][j] = max--;
						  dir = Right;
						  j++;
					  }
					  else{
						  data[i][j] = max--;
						  i++;
					  }

			}; break;

			}
		}
		
		return data;
	}
};
//int main(){
//	Solution s;
//	auto sd=s.crush(0);
//	for (int i = 0; i < sd.size(); i++){
//		for (int j = 0; j < sd[0].size(); j++){
//			printf("%5d ", sd[i][j]);
//		}
//		cout << endl;
//	}
//	return 0;
//}
