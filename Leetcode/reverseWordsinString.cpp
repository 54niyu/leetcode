#include"leetcode.h"

class Solution {
public:
	void reverseWords(string &s) {
		if (s.size() == 0)
			return;
		stringstream ss(s);
		string res;
		string temp;
		queue<int> resss;

		while (ss >> temp){
			res = temp + " " + res;
			temp = "";
		}
		if (res.size()!=0&&res.back() == ' ')
			res.pop_back();
		s = res;

	}
};