#include<iostream>
#include<string>
#include<stack>
#include<hash_map>
#include<vector>
#include<queue>

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
using namespace std;