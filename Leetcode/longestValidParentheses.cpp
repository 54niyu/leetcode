#include"leetcode.h"

class Solution {
public:
	int longestValidParentheses(string s) {
		match(s);
		return maxx;
	}
	char get(string& s, int flag){
		static int index = 0;
		if (index >= s.size())
			return '#';
		if (flag)
			return s.at(index++);
		else
			return s.at(index);
	}
	int match(string& s){
		int count = 0;
		bool isValid = true;
		while (get(s, 0) != '#'){
			if (get(s, 0) == '('){
				int num = _match(s);
				if (num > 0){
					count += num;
					if (count > maxx)
						maxx=count;
					else{
						count = 0;
						isValid = false;
					}
				}
			}
			else{
				get(s, 1);
			}
		}
		if (isValid = false)
			return 0;
		return count;
	}
	int _match(string& s){
		get(s, 1);
		if (get(s, 0) != '#'){
			if (get(s, 0) == '('){
				int num = match(s);
				if (num > 0)
					return num + 1;
				else
					return 0;
			}
		}
		else
			return 0;
	}
	int maxx = 0;
};
 

//p->q p;
//q->() | (p)
int main(){
//	()((()()()()()))
	Solution s;
	cout<<s.longestValidParentheses("()((()()()()()))");
	return 0;
}
