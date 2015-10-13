#include"leetcode.h"

struct node{
	int val;
	node* next;

	node* less;
	node* greater;
	node(int n){ val = n; next = NULL; greater = NULL; less = NULL; }
};
class MinStack{
	multiset<int> min;
	stack<int> data;
public:
	void push(int x){
		data.push(x);
		min.insert(x);
	}

	void pop(){
		int  key = data.top();
		data.pop();
		auto loc = min.find(key);
		min.erase(loc);
	}

	int top(){
		data.top();
	}

	int getMin(){
		return *min.begin();
	}
};
//int main(){
//	MinStack s;
//	s.push(512);
//		s.push(-1024);
//	s.push(-1024); s.push(512); s.pop(); s.getMin(); s.pop(); s.getMin(); s.pop(); s.getMin();
//}