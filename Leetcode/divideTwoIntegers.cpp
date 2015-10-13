#include"leetcode.h"
class Solution{
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0)
			return 0;
		bool isneg = false;
		if (dividend<0 && divisor<0){
			dividend = -dividend;
			divisor = -divisor;
		}
		else{
			if (dividend<0){
				isneg = true;
				dividend = -dividend;
			}
			if (divisor<0){
				isneg = true;
				divisor = -divisor;
			}
		}

		int res = 0;
		while (dividend >= divisor){
			dividend -= divisor;
			res++;
		}
		if (isneg)
			res = -res;
		return res;
	}
};
//int main(){
//	Solution s;
////	cout << 1 / 0;
//	for (int i = 0; i < 100; i++){
//		int a = rand(); int b = rand()%101;
//
//		cout << a << " /" << b << "="<< (a / b);
//		cout<<"--"<<s.divide(a,b)<<endl;
//	}
//	return 0;
//}