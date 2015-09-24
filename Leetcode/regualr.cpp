#include"leetcode.h"

class Solution{

public:
	bool match(char *str, char *pattern){
		if (*str == '\0'&&*pattern == '\0'){
			return true;
		}
		else if (*str == *pattern ){
			return match(str + 1, pattern + 1);
		}
		else if (*pattern == '.'){
			if (*(pattern + 1) != '*'){
				if (*str != '\0'){
					match(str + 1, pattern + 1);
				}
				else{
					return false;
				}
			}
			else{
				stack<int> s;
				
			}
		}
		else if (*pattern == '*'){
			matchDot(str - 1, pattern - 1);
		}
	}
	bool matchDot(char *str, char *pattern){

	}

};
//int main(){
//	char str[] = "abcccccd";
//	char pattern[] = "ab.*c";
//	Solution s;
//	cout<<s.match(str,pattern);
//	return 0;
//}
//
////  c*b    ccccccb