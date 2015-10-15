#include"leetcode.h"

class Stack {

public:

	// Push element x onto stack.
	void push(int x) {
		_major.push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		if (!_major.empty()){
			int size = _major.size();
			while (size > 1){
				_minor.push(_major.front());
				_major.pop();
				size--;
			}
				_major.pop();
				swap(_major, _minor);	
		}

	}

	// Get the top element.
	int top() {
		return _major.back();
	}

	// Return whether the stack is empty.
	bool empty() {
		return _major.empty();
	}

	queue<int> _major;
	queue<int> _minor;
};
//int main(){
//	Stack s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	cout<<s.top();
//	s.pop();
//	cout << s.top();
//	return 0;
//}