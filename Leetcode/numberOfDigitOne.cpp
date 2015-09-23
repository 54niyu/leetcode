#include<iostream>

using namespace std;

class Solution{
public:
	int countDigit(int n){
		int count = 0;
		while (n){
			int remainder = n % 10;
			if (remainder == 1)
				count++;
			n /= 10;
		}
		return count;
	}

	int countDigitOne(int n){

		int count = 0;
		for (int i = 1; i <= n; i++){
			count += countDigit(i);
		}

		return count;
	}
};
