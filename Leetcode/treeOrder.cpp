#include<cstdlib>
#include<stack>
#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include "leetcode.h"

using namespace std;



//先序和中序代码相似，只是输出值得时机不同，先序是一访问就输出，中序时等待出栈时候输出
//非递归先序遍历
void preOrder(TreeNode *root){
	cout << "----preOrder search-----\n";
	//存储已访问过结点，以保存其右结点的信息
	stack<TreeNode*> s;
	TreeNode* ref;
	//第一次ref指向root，以后每一次指向栈顶的右节点
	bool begin = true;
	do	{
		if (begin){
			ref = root;
		}
		else{
			ref = s.top()->right;
			s.pop();
		}
		begin = false;
		//从上向左遍历至叶节点,结束循环
		//获取栈顶元素，ref指向 其右结点，当前结点已被使用，弹出
		while (ref != NULL){
			cout << ref->val; //<< endl;
			s.push(ref);
			ref = ref->left;
		}
	} while (!s.empty());

}
void preOrder2(TreeNode* root){
	cout << "------------preOrder2--------------" << endl;
	stack<TreeNode*> s;
	TreeNode* ref = root;
	s.push(root);
	while (!s.empty()){
		ref = s.top();
		s.pop();
		if (ref != NULL){
			cout << ref->val;// << endl;
			if(ref->right!=NULL) s.push(ref->right);
			if(ref->left!=NULL) s.push(ref->left);
		}
	}
}
//非递归中序遍历
void inOrder(TreeNode *root){
	cout << "-----inOrder search-----\n";
	//存储已访问过结点，以保存其右结点的信息
	stack<TreeNode*> s;
	TreeNode* ref=root;
	//第一次ref指向root，以后每一次指向栈顶的右节点
	bool begin = true;
	do	{
		if (begin){
			ref = root;
		}
		else{
		//	cout << ref->val << endl;
			ref = s.top()->right;
			cout << s.top()->val;// << endl;
			s.pop();
		}
		begin = false;
		//从上向左遍历至叶节点,结束循环
		//获取栈顶元素，ref指向 其右结点，当前结点已被使用，弹出
		while (ref != NULL){
//			cout << ref->val << endl;
			s.push(ref);
			ref = ref->left;
		}
	} while (!s.empty());

}
void inorder(TreeNode* root){

	stack<TreeNode*> st;
	while (!st.empty() || root != nullptr){
		if (root != nullptr){
			st.push(root);
			root = root->left;
		}
		else{
			if (!st.empty()){
				root = st.top();
				cout << root->val << " ";
				st.pop();
				root = root->right;
			}
		}
	}

}
//后序遍历
void postOrder(TreeNode* root){
	cout << "-----postOrder search-----\n";
	stack<TreeNode*> s;
	//stack f用以存储第几次访问该结点，从左节点返回访问为1，从右结点返回为2
	//当2的时候，可以弹出该节点，并输出该节点值
	stack<int> f;
	TreeNode* ref = root;
	bool begin = true;
	do	{
		if (begin){
			ref = root;
		}
		else{
			//从左节点返回，ref指向右结点
			if (f.top() == 1){
				ref = s.top()->right;
				f.top()++;
			}
	//		cout << s.top()->val << endl;
			else if (f.top() == 2){
				//从右节点返回，弹出当前栈顶，并输出
				cout << s.top()->val;// << endl;
				s.pop();
				f.pop();
			}
		}
		//从上向左遍历至叶节点,结束循环
		//获取栈顶元素，ref指向 其右结点，当前结点已被使用，弹出
		while (ref != NULL){
			//			cout << ref->val << endl;
			s.push(ref);
			f.push(1);
			ref = ref->left;
		}
		begin = false;
	} while (!s.empty());
};

//int main(){
//	tree tr;
//	TreeNode* tree = tr.initTree("[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,322,323,324,325,326,327,328,329,330,331,332,333,334,335,336,337,338,339,340,341,342,343,344,345,346,347,348,349,350,351,352,353,354,355,356,357,358,359,360,361,362,363,364,365,366,367,368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,398,399,400,401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,420,421,422,423,424,425,426,427,428,429,430,431,432,433,434,435,436,437,438,439,440,441,442,443,444,445,446,447,448,449,450,451,452,453,454,455,456,457,458,459,460,461,462,463,464,465,466,467,468,469,470,471,472,473,474,475,476,477,478,479,480,481,482,483,484,485,486,487,488,489,490,491,492,493,494,495,496,497,498,499,500");
//	clock_t start, finish;
//	double totaltime;
//	start = clock();
//	preOrder(tree);
//	finish = clock();
//	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
//	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;
//	start = clock();
//	preOrder2(tree);
//	finish = clock();
//	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;;
//	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;
//	start = clock();
//	inOrder(tree);
//	finish = clock();
//	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
//	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;
//	start = clock();
//	postOrder(tree);
//	finish = clock();
//	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
//	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;
//	return 0;
//}