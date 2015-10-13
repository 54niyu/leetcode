#include"leetcode.h"

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> dadiacate;
		if (root != NULL)
			return  res;
		
		nextLevel(res, dadiacate);

	}
	void nextLevel(vector<vector<int>> &res, queue<TreeNode*> &dadiacate){
		if (!dadiacate.empty()){
		queue<TreeNode*> newq;
		vector<int> newr;
		while (!dadiacate.empty()){
			newr.push_back(dadiacate.front()->val);
			if (dadiacate.front()->left != NULL)
				newq.push(dadiacate.front()->left);
			if (dadiacate.front()->right != NULL)
				newq.push(dadiacate.front()->right);
			dadiacate.pop();
		}
		nextLevel(res, newq);
		}
	}
};
//int main(){
//
//}