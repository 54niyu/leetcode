#include"leetcode.h"
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)
			return NULL;
		vector<TreeNode*> wayofp;
		vector<TreeNode*> wayofq;
		ways(wayofp, root, p);
		ways(wayofq, root, q);
		int len = (wayofq.size()<wayofp.size()) ? wayofq.size() : wayofp.size();
		for (int i = len - 1; i >= 0; i--){
			if (wayofq[i] == wayofp[i])
				return wayofq[i];
		}

	}
	void ways(vector<TreeNode*> &way, TreeNode* root, TreeNode* p){

		TreeNode* ptr = root;
		while (ptr != NULL){
			way.push_back(ptr);
			if (ptr->val == p->val)
				break;
			else if (ptr->val<p->val){
				ptr = ptr->right;
			}
			else{
				ptr = ptr->left;
			}
		}
	}
};
//int main(){
//
//	TreeNode* root = new TreeNode(2);
//	TreeNode* left = new TreeNode(1);
//	root->left = left;
//	Solution s;
//	TreeNode *result = s.lowestCommonAncestor(root, root, left);
//	cout << result->val;
//	return 0;
//}