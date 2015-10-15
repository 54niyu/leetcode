#include"leetcode.h"

class Solution{
public:
	int maxProfit(vector<int> prices){
		if (prices.size() <= 1)
			return 0;

		//prices.push_back(prices.back());
		bool up = false;
		int buy=0;
		int sell=0;
		int profit = 0;

		for (int i = 1; i < prices.size(); i++){
			if (prices[i]>prices[i - 1]){
				sell++;
			}
			else{
				if (sell > buy){
					profit += (-prices[buy] + prices[sell]);
					buy = sell;
					buy++;
					sell++;
				}
				else if(sell==buy){
					buy++;
					sell++;
				}
				else{
				}
			}
		}
		if (sell > buy){
				profit += (-prices[buy] + prices[sell]);
		}
		return profit;
	}
};
//int main(){
//	Solution s;
//	vector<int> pri = { 4, 3, 2, 5, 6, 2, 1, 9 };
//	cout<<s.maxProfit(pri);
//}