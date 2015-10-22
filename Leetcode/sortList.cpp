/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include"leetcode.h"
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		ListNode* slow, *fast;
		if (head == NULL||head->next == NULL)
			return head;
		slow = head;
		fast = head->next;
		while (fast != NULL&&fast->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = slow->next;
		slow->next = NULL;
		return listMerge(sortList(fast), sortList(head));
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
//int main(){
//	std::vector<int> a = { 50, 3, 2, 3, 1, 21, 3, 23123, 123, 12, 234, 433, 56, 676, 575, 75, 6, 3345 };
//	ListNode* lista = NULL;
//	for (int i = 0; i < a.size(); i++){
//		ListNode* temp = new ListNode(a[i]);
//		temp->next = lista;
//		lista = temp;
//	}
//
//	Solution s;
//	lista=s.sortList(lista);
//	while (lista != NULL){
//		std::cout << lista->val << "  ";
//		lista = lista->next;
//	}
//	//mergeSort(a);
//	//insertSort(a);
//	//selectSort(a);
//	//bulleSort(a);
//	//shellSort(a);
//	//quickSort2(a);
//	return 0;
//}