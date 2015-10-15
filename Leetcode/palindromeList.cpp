/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include"leetcode.h"
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//
//};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		ListNode* d1 = head;
		ListNode* d2 = head;
		vector<int> half;
		while (true){
			if (d2 != NULL)
				d2 = d2->next;
			else{
				break;
			}

			if (d2 != NULL)
				d2 = d2->next;
			else{
				//half.pop_back();
				break;
			}
			half.push_back(d1->val);
			d1 = d1->next;
		}
		d1 = d1->next;
		for (int i = half.size() - 1; i >= 0; i--){
			if (d1 != NULL){
				if (d1->val == half[i]){
					d1 = d1->next;
					continue;
				 }
				else
					return false;
			}
			else{
				return false;
			}
		}
	}
};
//int main(){
//	ListNode *a=new ListNode(1);
//	ListNode *a1=new ListNode(2);
//	ListNode *a2=new ListNode(3);
//	ListNode *a3=new ListNode(2);
//	ListNode *a4=new ListNode(1);
//	a->next = a1;
//	a1->next = a2;
//	a2->next = a3;
//	a3->next = a4;
//	Solution s;
//	s.isPalindrome(a);
//	return 0;
//}