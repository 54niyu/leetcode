#include"leetcode.h"

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return build(inorder, postorder, 0, postorder.size() - 1);
	}
	TreeNode* build(vector<int>& inorder, vector<int>& postorder,int start,int end){
		if (start > end)
			return nullptr;
		static int pos = postorder.size()-1;
		int root = postorder.at(pos);
		TreeNode* r = new TreeNode(root);

		int mid = 0;
		for (int i = start; i <= end; i++){
			if (inorder.at(i) == postorder.at(pos)){
				mid = i;
			}
		}

		pos--;

		r->right = build(inorder, postorder, mid + 1, end);
		r->left = build(inorder, postorder, start, mid - 1);

		return r;

	}
};
//int main(){
//	vector<int> in = { 2, 1 };
//	vector<int> po = { 2, 1 };
//	Solution s;
//	TreeNode* root = s.buildTree(in, po);
//	return 0;
//}