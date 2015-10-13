#include"leetcode.h"

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int val;
		while (!stack1.empty()){
			stack2.push(stack1.top());
			stack1.pop();
		}
		if (!stack2.empty()){
			val = stack2.top();
			stack2.pop();
		}
		while (!stack2.empty()){
			stack1.push(stack2.top());
			stack2.pop();
		}
		return val;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
//int main(){
//	Solution s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.pop();
//	return 0;
//}