#include"leetcode.h"
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
			return NULL;
		queue<ListNode*> Q;
		for (auto item : lists){
			Q.push(item);
		}

		ListNode* temp = Q.front();
		Q.pop();
		while (!Q.empty()){
			Q.push(listMerge(temp, Q.front()));
			Q.pop();
			temp = Q.front();
			Q.pop();
		}
		return temp;
	}
	ListNode* listMerge(ListNode* a, ListNode* b){
		//List merger

		ListNode* head = new ListNode(0);
		ListNode* h = head;
		while ((a != NULL) && (b != NULL)){
			ListNode* temp = NULL;
			if (a->val < b->val){
				temp = a;
				a = a->next;
				temp->next = NULL;
				head->next = temp;
				head = head->next;
			}
			else{
				temp = b;
				b = b->next;
				temp->next = NULL;
				head->next = temp;
				head = head->next;
			}
		}
		if (a == NULL){
			head->next = b;
		}
		else{
			head->next = a;
		}

		return h->next;
	}
};