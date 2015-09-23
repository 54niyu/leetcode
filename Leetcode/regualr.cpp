#include"leetcode.h"

class Solution{

public:
	bool match(char *str,char *pattern){
		if ((*str) == '\0'&&(*pattern) == '\0'){
			return true;
		}
		else if (*str == '\0' &&*pattern == '*'){
			return match(str - 1, pattern + 1);
		}
		else if ((*str) == (*pattern) ||( *pattern) == '.'){
			return match(str+1, pattern+1);
		}
		else if ((*pattern) == '*'){
			if (match(str + 1, pattern - 1) == false){
				match(str, pattern + 1);
			}
		}
		else{
			if (*(pattern + 1) == '*'){
				return match(str, pattern + 2);
			}
			else
				return false;
		}
	}
};
int main(){
	char str[] = "acd";
	char pattern[] = "acd*d*d*";
	Solution s;
	cout<<s.match(str,pattern);
	return 0;
}

//  c*b    ccccccb