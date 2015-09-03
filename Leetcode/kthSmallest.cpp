/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include<stack>
#include<cstdlib>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		return inOrder(root, k);
	}
	int inOrder(TreeNode *root, int k){

		//存储已访问过结点，以保存其右结点的信息
		stack<TreeNode*> s;
		TreeNode* ref = root;
		int i = 0;
		//第一次ref指向root，以后每一次指向栈顶的右节点
		bool begin = true;
		do	{
			if (begin){
				ref = root;
			}
			else{

				ref = s.top()->right;
				//		cout << s.top()->val<<endl;
				i++;
				if (i == k)
					return s.top()->val;
				s.pop();
			}
			begin = false;
			//从上向左遍历至叶节点,结束循环
			//获取栈顶元素，ref指向 其右结点，当前结点已被使用，弹出
			while (ref != NULL){
				//			cout << ref->val << endl;
				s.push(ref);
				ref = ref->left;
			}
		} while (!s.empty());

	}
};