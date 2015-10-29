#include"leetcode.h"
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		return divide(head);
	}
	TreeNode* divide(ListNode* head){
		if (head = NULL)
			return NULL;
		if (head->next = NULL)
			return new TreeNode(head->val);
		//find the middle node;
		ListNode* slow, *fast;
		slow = head;
		fast = head->next;
		while (fast != NULL&&fast->next != NULL){
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow->next;
		slow->next = NULL;
		TreeNode* root = new TreeNode(fast->val);
		fast = fast->next;
		root->left = divide(head);
		root->right = divide(fast);
		return root;

	}
};
int main(){
	Solution s
}