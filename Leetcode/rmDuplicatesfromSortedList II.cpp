#include"leetcode.h"

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* h = new ListNode(0);
		h->next = head;
		head = h;

		ListNode* end = h;
		bool find = false;
		while (end->next != NULL&&end->next->next != NULL){
			if (end->next->val == end->next->next->val){
				if (!find){
					head = end;
					find = true;
					end = end->next;
				}
				else{
					end = end->next;
				}
			}
			else{
				if (find){
					head->next = end->next ->next;
					end = head;
					find = false;
				}
				else{
					end = end->next;
				}
			}
		}
		if (find)
			head->next = NULL;
		return h->next;
	}
};
//int main(){
//	std::vector<int> a = { 10,10,10,9,9,8,7,6,5,4,3,3,3,3,2,2,2,2,1,1,1,0 };
//	ListNode* lista = NULL;
//	for (int i = 0; i < a.size(); i++){
//		ListNode* temp = new ListNode(a[i]);
//		temp->next = lista;
//		lista = temp;
//	}
//
//	Solution s;
//	lista=s.deleteDuplicates(lista);
//	while (lista != NULL){
//		std::cout << lista->val << "  ";
//		lista = lista->next;
//	}
//	return 0;
//
}