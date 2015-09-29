#include"leetcode.h"

	class Solution {
	public:
		string numberToWords(int num) {
			if (num == 0)
				return "Zero";
			vector<int> num2char;
			string zero2nine[] = { "", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine" };
			string ten2ninety[] = { "", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety" };
			string ten2ninteen[] = { " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen" };
			//convert num to char[]
			while (num){
				num2char.push_back((num % 10));
				num /= 10;
			}
			string word;
			bool notZero = false;
			for (int i = num2char.size() - 1; i >= 0; i--){
				if (num2char[i] != 0) notZero = true;
				switch (i % 3){
				case 2:{
					word += zero2nine[num2char[i]]; 
					if (num2char[i] != 0) word += " Hundred";
				}; break;
				case 1:{
					if (num2char[i]>1){ 
						word += ten2ninety[num2char[i]]; 
					} else if (num2char[i] == 1){ 
						word += ten2ninteen[num2char[i - 1]];
						i--;
					} else{
						/* word += zero2nine[num2char[i - 1] ]; i--;*/ }
				}; break;
				case 0:{
					word += zero2nine[num2char[i]]; 
				}; break;
				}
				if ((i == 9) && notZero){
					word += " Billion";
					notZero = false;
				}
				else if ((i == 6) && notZero){
					word += " Million";
					notZero = false;
				}
				else if ((i == 3) && notZero){
					word += " Thousand";
					notZero = false;
				}
			}
			if (word[0] == ' ')
				word = word.substr(1);
			return word;
		}
	};
//int main(){
//	Solution s;
//	cout << pow(2, 32) - 1;
//	s.numberToWords(123);
//}