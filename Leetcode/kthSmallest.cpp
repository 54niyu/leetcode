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

		//�洢�ѷ��ʹ���㣬�Ա������ҽ�����Ϣ
		stack<TreeNode*> s;
		TreeNode* ref = root;
		int i = 0;
		//��һ��refָ��root���Ժ�ÿһ��ָ��ջ�����ҽڵ�
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
			//�������������Ҷ�ڵ�,����ѭ��
			//��ȡջ��Ԫ�أ�refָ�� ���ҽ�㣬��ǰ����ѱ�ʹ�ã�����
			while (ref != NULL){
				//			cout << ref->val << endl;
				s.push(ref);
				ref = ref->left;
			}
		} while (!s.empty());

	}
};