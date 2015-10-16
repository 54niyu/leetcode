#include"leetcode.h"
enum State{
	Start,
	Start2,
	Integer,
	Float,
	Float2,
	Science,
	Science2,
	Science3,
	Blankend,
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
					   if (c == ' ')
						   status = Start;
					   else if (c == '+' || c == '-'){
						   status = Start2;
					   }
					   else if (isdigit(c) || c == '.'){
						   status = Start2;
						   back();
					   }
					   else{
						   status = Error;
					   }
			}; break;
			case Start2:{
					    if (c == 'e')
						    status = Error;
					    else if (isdigit(c)){
						    status = Integer;
					    }
					    else if (c == '.'){
						    status = Float2;
					    }
					    else{
						    status = Error;
					    }
			}; break;
			case Integer:{
					     if (isdigit(c)){
						     status = Integer;
					     }
					     else if (c == ' '){
						     status = Blankend;
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
			case Float2:{
					    if (isdigit(c)){
						    status = Float;
					    }
					    else
						    status = Error;
			}; break;
			case Float:{
					   if (isdigit(c)){
						   status = Float;
					   }
					   else if (c == 'e'){
						   status = Science;
					   }
					   else if (c == ' '){
						   status = Blankend;
					   }
					   else{
						   status = Error;
					   }
			}; break;
			case Science:{
					     if (c == '-' || c == '+'){
						     status = Science2;
					     }
					     else if (isdigit(c)){
						     status = Science3;
					     }
					     else {
						     status = Error;
					     }
			}; break;
			case Science2:{
					      if (isdigit(c)){
						      status = Science3;
					      }
					      else{
						      status = Error;
					      }
			}; break;
			case Science3:{
					      if (c == ' '){
						      status = Blankend;
					      }
					      else if (isdigit(c)){
						      status = Science3;
					      }
					      else
						      status = Error;
			}; break;
			case Blankend:{
					      if (c == ' ')
						      status = Blankend;
					      else
						      status = Error;
			}; break;
			case Error:return false;
			}
		}
		if (status == Integer || status == Float || status == Science3 || status == Blankend)
			return true;
		else
			return false;
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
//int main(){
//	Solution s;
//	cout<<s.isNumber("+3e+12");
//	return 0;
//}