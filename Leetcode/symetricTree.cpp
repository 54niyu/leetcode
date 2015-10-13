#include"leetcode.h"
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		stack<TreeNode*> left;
		stack<TreeNode*> right;
		left.push(root);
		right.push(root);
		TreeNode* lptr;//=root->left;
		TreeNode* rptr;//=root->right;

		while (true){
			if (!left.empty() && !right.empty()){
				lptr = left.top();
				rptr = right.top();
				left.pop();
				right.pop();
			}
			else{
				break;
			}
			if ((lptr!=NULL)&&(rptr!=NULL)){
				if (lptr->val == rptr->val){
					if (lptr->right != NULL) left.push(lptr->right);
					if (lptr->left != NULL) left.push(lptr->left);
					if (rptr->left != NULL) right.push(rptr->left);
					if (rptr->right != NULL) right.push(rptr->right);
				}
				else{
					return false;
				}
			}
			else if ((lptr==NULL)&&(rptr!=NULL)){
				return false;
			}
			else if ((lptr!=NULL)&&(rptr==NULL)){
				return false;
			}
			else{

			}
		}
		return true;
	}
};
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
//int main(){
//	tree t;
//	TreeNode * tree=t.initTree("1,2,2,3,4,4,4");
//	Solution s;
//	cout<<s.isSymmetric(tree);
//}