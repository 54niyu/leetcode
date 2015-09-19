#include"leetcode.h"
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {

		vector<int> result;
		map<int, int> times;

		for (int i = 0; i < nums.size(); i++){
			map<int, int>::iterator f = times.find(nums[i]);
			if (f == times.end()){
				times[nums[i]] = 0;
			}
			else{
				times[nums[i]] ++;
			}
		}

		map<int, int>::iterator it = times.begin();
		while (it != times.end()){
			if (it->second > (nums.size() / 3)){
				result.push_back(it->first);
			}
			if (result.size() > 2)
				return result;
			it++;
		}
	}
};
//int main(){
//	Solution s;
//	vector<int> data = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 2, 3, 4, 5, 6, 7, 8 };
//	vector<int> result = s.majorityElement(data);
//	return 0;
//}