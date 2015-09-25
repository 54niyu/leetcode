#include"leetcode.h"

class Solution {
public:
	int calculate(string s) {
		s = s + '/';
		char buffer[20];
		int index = 0;

		vector<char> op;
		vector<int> num;
		


		for (int i = 0; i<s.length(); i++){
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){

					buffer[index] = '\0';
					int n = atoi(buffer);
					index = 0;

					if (!op.empty()){
						if (op.back() == '*' ){
							n= num.back()*n;
							op.pop_back();
							num.pop_back();
						}
						else if (op.back() == '/'){
							n= num.back()/n;
							op.pop_back();
							num.pop_back();
						}
						else{

						}
					}
					op.push_back(s[i]);
					num.push_back(n);
			}
			else if (s[i] == ' '){
				//ºöÂÔ¿Õ¸ñ
				continue;
			}
			else{
				buffer[index++] = s[i];
			}
		}
		op.pop_back();
		for (int i = 0; i < op.size(); i++){
			if (op[i] == '+')
				num[0] += num[i + 1];
			if (op[i] == '-')
				num[0] -= num[i + 1];
		}

		return num[0];
	}
	int calculate2(string s){
		s = s + '#';
		stack<char> ope;
		stack<int> num;
		char buffer[100];
		int index = 0;
		bool isnum = false;
		for (int i = 0; i < s.size(); i++){
			if (s[i] >= '0'&&s[i] <= '9'){
				isnum = true;
				buffer[index++] = s[i];
			}
			else if (s[i] == ' '){

			}
			else {
				if (isnum){
					buffer[index] = '\0';
					int n = atoi(buffer);
					index = 0;
					Push(ope, num, n);
					isnum = false;
					i--;
				}
				else{
					if (s[i] != '#')
						ope.push(s[i]);
					if (s[i] == ')'){
						ope.pop();
						int temp = num.top();
						num.pop();
						ope.pop();
			    		Push(ope, num, temp);
					}
				}
			}
		}
		return num.top();
	}
	void Push(stack<char> &ope, stack<int> &num, int val){
		if (!ope.empty()){
			switch (ope.top()){
			case '+':{ope.pop(); int temp = num.top(); num.pop(); Push(ope, num, temp + val); }; break;
			case '-':{ope.pop(); int temp = num.top(); num.pop(); Push(ope, num, temp - val); }; break;
			default:num.push(val);
			}
		}
		else{
			num.push(val);
		}
	}
};
//int main(){
//	Solution s;
//	cout<<s.calculate2("(6)");
//	return 0;
//}