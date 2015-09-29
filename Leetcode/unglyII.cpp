#include"leetcode.h"
class Solution{
public:
	int nthUglyNumber(int n) {

		set<long long> ugly;
		ugly.insert(1);
		long long number =0;
		auto begin = ugly.begin();
		while (begin != ugly.end()){
			number++;
			if (number == 1547)
				break;//return *begin;
			ugly.insert((*begin) * 2);
			ugly.insert((*begin) * 3);
			ugly.insert((*begin) * 5);
			begin++;
		}
		ugly.insert(1);
/*		ugly.insert(2);
		ugly.insert(3);
		ugly.insert(4);
		ugly.insert(5);

		if (n <= 5)
			return n;
		int number = 6;
		int recent = 6;
		int index = 6;
		while (number <= n){
			if ((index % 2) == 0){
				if (ugly.find(index / 2) != ugly.end()){
					ugly.insert(index);
					number++;
					recent = index;
					index++;
				}
				else{
					index++;
				}
			}
			else if ((index % 3) == 0){
				if (ugly.find(index / 3) != ugly.end()){
					ugly.insert(index);
					number++;
					recent = index;
					index++;
				}
				else{
					index++;
				}
			}
			else if ((index % 5) == 0){
				if (ugly.find(index / 5) != ugly.end()){
					ugly.insert(index);
					number++;
					recent = index;
					index++;
				}
				else{
					index++;
				}
			}
			else{
					index++;
				}
		}

		return recent;
		*/
		return 0;
	}
};
//int main(){
//	Solution s;
//	cout<<s.nthUglyNumber(1600);
//}