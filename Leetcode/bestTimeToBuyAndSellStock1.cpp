#include "leetcode.h"
class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int buy = 0, sell = 0;
		int profit = 0;
	//	buy = sell = prices.at(0);
		prices.push_back(-1);
		bool isUp = false;
		for (int i = 1; i < prices.size(); i++){
			if (prices.at(i) > prices.at(i - 1)){
				if (!isUp){
					isUp = true;
				}
			}
			else{
				if (isUp){
					int p = prices.at(i - 1) - prices.at(buy);

					if (p > profit)
						profit = p;
					isUp = false;
				}
				else{
					if (prices.at(i) < prices.at(buy)){
						buy = i;
					}
				}
			}
		}

		return profit;
	}
};

