
#include<map>

using namespace std;
 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		map<RandomListNode*, RandomListNode*> save;

		RandomListNode* n = head;
		while (head != NULL){
			RandomListNode* NEW = new RandomListNode(head->label);
			save[head] = NEW;
			head = head->next;
		}
		for (auto item : save){
			if (item.first->next != NULL){
				item.second->next = save[item.first->next];
			}
			else
				item.second->next = NULL;
			if (item.first->random != NULL)
				item.second->random = save[item.first->random];
			else
				item.second->random = NULL;
		}
		return save[n];
	}
};
int main(){

}