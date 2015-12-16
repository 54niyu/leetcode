#include"leetcode.h"
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class tree{
public:
	TreeNode* createNode(int num, vector<string> &treenode){
		if (num >= treenode.size() || treenode[num] == "null")
			return NULL;
		long var = atoi(treenode[num].c_str());
		TreeNode* node = new TreeNode(var);
		node->left = createNode(num * 2 + 1, treenode);
		node->right = createNode(num * 2 + 2, treenode);
		return node;
	}
	TreeNode * initTree(string info){
		info = info + ",";
		vector<string> treenode;
		char buffer[100];
		int index = 0;
		for (int i = 0; i < info.length(); i++){
			if (info[i] != ','){
				buffer[index++] = info[i];
			}
			else{
				buffer[index] = '\0';
				string s(buffer);
				treenode.push_back(s);
				index = 0;
			}
		}
		return createNode(0, treenode);
	}
};
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
int main(){

	tree Tree;
	TreeNode* tem=Tree.initTree("[1,2,5,3,4,6]");
	Solution s;
	s.flatten(tem);
	return 0;
}