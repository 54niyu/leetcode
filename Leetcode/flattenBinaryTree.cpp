#include"leetcode.h"

class Solution {
public:
	void flatten(TreeNode* root) {
		postTrave(root);
	}
	TreeNode* postTrave(TreeNode* root){
		if (root == NULL)
			return NULL;
		cout << root->val << endl;
		TreeNode* left = postTrave(root->left);
		TreeNode* right = postTrave(root->right);

		if (left !=NULL&&right != NULL){
			TreeNode* ptr = left;
			while (ptr->right != NULL){
				ptr = ptr->right;
			}
			ptr->right = right;
			root->right = root->left;
			root->left = NULL;
		}
		else if (right == NULL){
			root->right = root->left;
			root->left = NULL;
		}
		else{
			//do nothing
		}

		return root;
	}
};
//int main(){
//
//	tree Tree;
//	TreeNode* tem=Tree.initTree("[1,2,5,3,4,6]");
//	Solution s;
//	s.flatten(tem);
//	return 0;
//}