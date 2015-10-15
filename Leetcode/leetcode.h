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