#include<cstdlib>
#include<stack>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
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
			cout << ref->val << endl;
			s.push(ref);
			ref = ref->left;
		}
	} while (!s.empty());

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
			cout << s.top()->val<<endl;
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
				cout << s.top()->val << endl;
				s.pop();
				f.pop();
			}
		}
		begin = false;
		//从上向左遍历至叶节点,结束循环
		//获取栈顶元素，ref指向 其右结点，当前结点已被使用，弹出
		while (ref != NULL){
			//			cout << ref->val << endl;
			s.push(ref);
			f.push(1);
			ref = ref->left;
		}
	} while (!s.empty());

}

//int main(){
//	tree tr;
//	TreeNode* tree = tr.initTree("42,10,11,60,77,null,50,98,88,99,100");
//	TreeNode* tree2 = tr.initTree("1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19");
//
//	preOrder(tree);
//	inOrder(tree);
//	postOrder(tree);
//	preOrder(tree2);
//	inOrder(tree2);
//	postOrder(tree2);
//
//
//	return 0;
//}