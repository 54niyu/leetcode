#include"leetcode.h"

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		vector<int> temp;

		path(root, sum, res, temp);

		return res;
	}
	void path(TreeNode* root, int sum, vector<vector<int>> &res, vector<int> temp){
		if (root == NULL)
			return;
		//     if(sum-root->val<0)
		//          return;
		//leaf node
		if (root->left == NULL&&root->right == NULL){
			if (sum - root->val == 0){
				temp.push_back(root->val);
				res.push_back(temp);
			}
			else
				return;
		}
		temp.push_back(root->val);
		path(root->left, sum - root->val, res, temp);
		path(root->right, sum - root->val, res, temp);

	}
};