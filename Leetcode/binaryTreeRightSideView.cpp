#include "leetcode.h"
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;

		if (root == nullptr) return res;

		queue<TreeNode*> que;
		que.push(root);
		que.push(nullptr);
		while (que.size() > 1){
			int tail = 0;
			while (!que.empty()){

				TreeNode* temp = que.front();
				que.pop();

				if (temp == nullptr){
					que.push(nullptr);
					break;
				}
				else{
					tail = temp->val;
					if (temp->left != nullptr) que.push(temp->left);
					if (temp->right != nullptr) que.push(temp->right);
				}
			}
			res.push_back(tail);
		}
		return res;
	}
};
//int main(){
//	TreeNode * root = nullptr;
//	tree r;
//	root=r.initTree("[1,2,3,4,5,]");
//	Solution s;
//	s.rightSideView(root);
//}