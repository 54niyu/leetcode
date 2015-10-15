#include"leetcode.h"

class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode* fast;
		ListNode* slow;
		fast = slow = head;

		while (true){
			if (fast != NULL)
				fast = fast->next;
			else
				return false;
			if (fast != NULL)
				fast = fast->next;
			else
				return false;

			slow = slow->next;

			if (slow == fast)
				return true;
		}
	}
};