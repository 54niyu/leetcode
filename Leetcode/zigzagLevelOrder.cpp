#include "leetcode.h"

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
int main(){
	Solution s;
	tree  tr;
	TreeNode* root = tr.initTree("[1,2,3,4,5,6,7,8,9,10]");
	s.zigzagLevelOrder(root);

	return 0;
}