#include"leetcode.h"
enum State{
	Start,
	Neg,
	Integer,
	Float,
	Science,
	Science2,
	Error,
};
class Solution {
public:
	bool isNumber(string s) {
		_s = s;
		_index = 0;
		State status = Start;

		while (_index < s.size()){
			char c = next();
			switch (status){
			case Start:{
				if (c == '-')
					status = Neg;
				else if (c == 'e')
					status = Error;
				else if(isdigit(c)){
					status = Integer;
				}
				else if(c=='.'){
					status = Float;
				}
				else{
					status = Error;
				}
			}; break;
			case Neg:{
								if (c == 'e')
									status = Error;
								else if (isdigit(c)){
									status = Integer;
								}
								else if (c == '.'){
									status = Float;
								}
								else{
									status = Error;
								}
			}; break;
			case Integer:{
				if (isdigit(c)){
					status = Integer;
				}
				else if (c == '.'){
					status = Float;
				}
				else if (c == 'e'){
					status = Science;
				}
				else{
					status = Error;
				}
			}; break;
			case Float:{
				if (isdigit(c)){
					status = Float;
				}
				else if (c == 'e'){
					status = Science;
				}
				else{
					status = Error;
				}
			}; break;
			case Science:{
				if (c == '-'||isdigit(c)){
					status = Science2;
				}
				else {
					status = Error;
				}
			}; break;
			case Science2:{
				if (isdigit(c)){
					status = Science2;
				}
				else{
					status = Error;
				}
			}; break;
			case Error:return false;
			}
		}
		if (status == Integer || status == Float || status == Science2)
			return true;
	}
	char next(){
		return _s[_index++];
	}
	void back(){
		_index--;
	}

	string _s;
	int _index;
};
int main(){
	Solution s;
	cout<<s.isNumber("-.12e10");
	cout << s.isNumber("-10");
	cout << s.isNumber("-.12");
	cout << s.isNumber("-10.21");
	cout << s.isNumber("-e10");
	cout << s.isNumber("-.12e10.2");
}