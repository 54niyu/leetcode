#include"leetcode.h"
class Solution {
public:
	int sumNumbers(TreeNode* root) {
		int sum=0;
		depth(root, sum, root->val);
		return sum;
	}
	void depth(TreeNode* root,int &sum,int s){
		if (root == nullptr)
			sum += s;
		else{
			if (root->left != nullptr)	depth(root->left, sum, s * 10 + root->val);	
			else
			{
				sum += s;
			}
			if (root->right!=nullptr)	depth(root->right, sum, s * 10 + root->val);
			else{
				sum += s;
			}
		}
	}
};

int main(){
	tree r;
	TreeNode* root = r.initTree("[1,2,3,4,5,6,7]");
	Solution s;
	s.sumNumbers(root);

	return 0;
}