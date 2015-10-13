#include"leetcode.h"
class Solution{
public:
	unsigned int reverseBits(unsigned int n) {
		for (int i = 0; i<16; i++){
			unsigned int right = (1 << i)&n;
			unsigned int left = (1 << (31 - i))&n;
			if (right!= 0&&left==0){
				n ^= ((1 << i) ^ (1 << (31 - i)));
			}
			else if (right == 0 && left != 0){
				n ^= ((1 << i) ^ (1 << (31 - i)));
			}
			else {
				continue;
			}
		}
		return n;
	}
};
//int main(){
//	Solution s;
//	s.reverseBits(4294967295);
//	return 0;
//}