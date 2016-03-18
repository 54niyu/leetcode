#include"leetcode.h" 
#include<functional>

class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		map<string, vector<string>> adj;
		for (auto t : tickets){
			adj[t.first].push_back(t.second);
		}

		for (map<string, vector<string>>::iterator s = adj.begin(); s != adj.end(); s++){
			sort(s->second.begin(), s->second.end(), greater<string>());
		}

		vector<string> res;
		string begin = "JFK";
		search(adj, begin, res);
		reverse(res.begin(), res.end());
		return res;
	}
	void search(map<string, vector<string>> &adj, string begin, vector<string> &res){
		while (!adj[begin].empty()){
			string next = adj[begin].back();
			adj[begin].pop_back();
			search(adj, next, res);
		}
		res.push_back(begin);
	}
};
//int main(){
//	Solution s;
//	vector<pair<string, string>> sss = { {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO" }};
//
//	s.findItinerary(sss);
//	return 0;
//}