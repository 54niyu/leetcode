#include"leetcode.h"
#include<unordered_set>
#include<vector>

using namespace std;

class Solution{
public:
	vector<int> findMinHeightTrees(int Vertex, vector<std::pair<int, int>> &Edges){
		vector<int>result;
		if (Vertex == 0)return result;
		if (Vertex == 1)return vector<int>(1, 0);

		vector<unordered_set<int>> adj(Vertex, unordered_set<int>());
		for (auto e : Edges){
			adj.at(e.first).insert(e.second);
			adj.at(e.second).insert(e.first);
		}

		vector<int> leves;
		for (int i = 0; i < Vertex; i++){
			if (adj.at(i).size() == 1){
				leves.push_back(i);
				cout << i << endl;
			}
		}

		vector<int> newleves;
		while (Vertex > 2){
			Vertex -= leves.size();
			for (int i = 0; i < leves.size(); i++){
				int v = leves.at(i);
				int w = *adj.at(v).begin();

				adj.at(v).erase(adj.at(v).begin());
				adj.at(w).erase(adj.at(w).find(v));
				if (adj.at(w).size() == 1)
					newleves.push_back(w);
			}
			leves = newleves;
			newleves.clear();
		}
		return leves;
	}
};