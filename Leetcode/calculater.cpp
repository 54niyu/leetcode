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
};
//int main(){
//	Solution s;
//	s.calculate(" 3+5 / 2 ");
//	return 0;
//}