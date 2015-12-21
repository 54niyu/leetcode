#include<cstdlib>

#include<iostream>
#include<sstream>

#include<string>

#include<stack>
#include<hash_map>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<list>

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;
class tree{
public:
	TreeNode* createNode(int num, vector<string> &treenode){
		if (num >= treenode.size() || treenode[num] == "null")
			return NULL;
		long var = atoi(treenode[num].c_str());
		TreeNode* node = new TreeNode(var);
		node->left = createNode(num * 2 + 1, treenode);
		node->right = createNode(num * 2 + 2, treenode);
		return node;
	}
	TreeNode * initTree(string info){
		info = info + ",";
		vector<string> treenode;
		char buffer[100];
		int index = 0;
		for (int i = 0; i < info.length(); i++){
			if (info[i] != ','){
				buffer[index++] = info[i];
			}
			else{
				buffer[index] = '\0';
				string s(buffer);
				treenode.push_back(s);
				index = 0;
			}
		}
		return createNode(0, treenode);
	}
};