#include"leetcode.h"
class Solution{
	public:
		string multiply(string num1, string num2) {

			reverse(num1.begin(), num1.end());
			reverse(num2.begin(), num2.end());

			vector<short> res(num1.size() + num2.size(), 0);


			for (int i = 0; i<num2.size(); i++){
				if (num2[i] != '0'){
					short mo = 0;
					for (int j = 0; j<num1.size(); j++){
						short mul = (num1[j] - '0')*(num2[i] - '0') + res[i + j] + mo;
						if (res[i+j] != 0){
							res[i + j] = mul % 10;
							mo = mul / 10;
						}
						else{
							mo = 0;
						}

					}
					if (mo>0){
						res[i + num1.size()] = mo;
					}
				}

			}
			string result;
			int i = res.size() - 1;
			for (; i >= 0; i--){
				if (res[i] != 0){
					break;
				}
			}
			if (i<0)
				return "0";
			else{
				for (; i >= 0; i--){
					result += res[i] + '0';
				}
			}
			return result;
		}
};
//int main(){
//	Solution s;
//	cout<<s.multiply("0", "10");
//	return 0;
//}