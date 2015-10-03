#include"leetcode.h"


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ptr1;
		ListNode* ptr2;
		ListNode* res=NULL;
		ListNode* helper=NULL;
		ptr1 = l1;
		ptr2 = l2;
		int add = 0;
		while (ptr1 != NULL&&ptr2 != NULL){
			int sum = (add + ptr1->val + ptr2->val);
			if (res == NULL){
				res = new ListNode(sum % 10);
				helper = res;
			}
			else{
				helper->next = new ListNode(sum % 10);
				helper = helper->next;
			}
		//	ptr1->val = ptr2->val = sum % 10;
			add = sum / 10;
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		//same number
		if (ptr1 == NULL&&ptr2 == NULL){
			//with carry
			if (add>0){
				ListNode* t = new ListNode(add);
				helper->next = t;

			}
		}
		else if (ptr1 != NULL){
			while (ptr1 != NULL){
				int sum = (add + ptr1->val);
				helper->next = new ListNode(sum % 10);
				add = sum / 10;
				ptr1 =ptr1->next;
				helper = helper->next;
			}
			if (add>0){
				ListNode* t = new ListNode(add);
				helper->next = t;

			}
		}
		else if (ptr2 != NULL){
			while (ptr2 != NULL){
				int sum = (add + ptr2->val);
				helper->next = new ListNode(sum % 10);
				helper = helper->next;
				add = sum / 10;
				ptr2 = ptr2->next;
			}
			if (add>0){
				ListNode* t = new ListNode(add);
				helper->next = t;

			}
		}
		return res;
	}

};
int main(){
//	vector<int> a = { 1 };
//	vector<int> b = { 9, 9, 9 };
	ListNode* a = new ListNode(1);
	ListNode* b= new ListNode(9);
	ListNode* b1 = new ListNode(9);
	ListNode* b2= new ListNode(9);
	ListNode* b3 = new ListNode(9);
	b->next = b1;
	b1->next = b2;
	b2->next = b3;
	Solution s;
	s.addTwoNumbers(a, b);

}