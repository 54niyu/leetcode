#include"leetcode.h"
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (k == 0)
			return head;
		if (head == NULL)
			return NULL;
		int length = 0;
		ListNode* reverse = new ListNode(0);
		//reserve list
		while (head != NULL){
			ListNode *temp = head;
			head = head->next;
			temp->next = reverse->next;
			reverse->next = temp;
			length++;
		}

		k %= length;
		head = reverse->next;
		ListNode* last = reverse->next;
		reverse->next = NULL;

		if (k == 0)
			last = reverse;
		//reserve last k node to the head;
		for (int i = 0; i<k; i++){
			ListNode *temp = head;
			head = head->next;
			temp->next = reverse->next;
			reverse->next = temp;
		}
		//reverse the rest to last;
		while (head != NULL){
			ListNode *temp = head;
			head = head->next;
			temp->next = last->next;
			last->next = temp;
		}

		return reverse->next;
	}
};;
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
//	lista=s.rotateRight(new ListNode(3), 3);
//	while (lista != NULL){
//		std::cout << lista->val << "  ";
//		lista = lista->next;
//	}
//	return 0;
//}