#include "leetcode.h"


class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;

		if (root == nullptr)
			return res;

		queue<TreeNode*> forward;
		queue<TreeNode*> backward;
		forward.push(root);

		bool dir = true;

		while (!forward.empty() || !backward.empty()){

			vector<int> temp;

			if (dir){
				while (!forward.empty()){
					TreeNode* ptr = forward.front();
					forward.pop();
					temp.push_back(ptr->val);

					if (ptr->left != nullptr)
						backward.push(ptr->left);
					if (ptr->right != nullptr)
						backward.push(ptr->right);
				}
			}
			else{
				while (!backward.empty()){
					TreeNode* ptr = backward.front();
					backward.pop();
					temp.push_back(ptr->val);

					if (ptr->left != nullptr)
						forward.push(ptr->left);

					if (ptr->right != nullptr)
						forward.push(ptr->right);
				}
				reverse(temp.begin(), temp.end());
			}

			res.push_back(temp);
			dir = !dir;
		}

		return res;
	}
};
//int main(){
//	Solution s;
//	tree  tr;
//	TreeNode* root = tr.initTree("[1,2,3,4,5,6,7,8,9,10]");
//	s.zigzagLevelOrder(root);
//
//	return 0;
//}