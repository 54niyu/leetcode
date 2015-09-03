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
//���������������ƣ�ֻ�����ֵ��ʱ����ͬ��������һ���ʾ����������ʱ�ȴ���ջʱ�����
//�ǵݹ��������
void preOrder(TreeNode *root){
	cout << "----preOrder search-----\n";
	//�洢�ѷ��ʹ���㣬�Ա������ҽ�����Ϣ
	stack<TreeNode*> s;
	TreeNode* ref;
	//��һ��refָ��root���Ժ�ÿһ��ָ��ջ�����ҽڵ�
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
		//�������������Ҷ�ڵ�,����ѭ��
		//��ȡջ��Ԫ�أ�refָ�� ���ҽ�㣬��ǰ����ѱ�ʹ�ã�����
		while (ref != NULL){
			cout << ref->val << endl;
			s.push(ref);
			ref = ref->left;
		}
	} while (!s.empty());

}
//�ǵݹ��������
void inOrder(TreeNode *root){
	cout << "-----inOrder search-----\n";
	//�洢�ѷ��ʹ���㣬�Ա������ҽ�����Ϣ
	stack<TreeNode*> s;
	TreeNode* ref=root;
	//��һ��refָ��root���Ժ�ÿһ��ָ��ջ�����ҽڵ�
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
		//�������������Ҷ�ڵ�,����ѭ��
		//��ȡջ��Ԫ�أ�refָ�� ���ҽ�㣬��ǰ����ѱ�ʹ�ã�����
		while (ref != NULL){
//			cout << ref->val << endl;
			s.push(ref);
			ref = ref->left;
		}
	} while (!s.empty());

}
//�������
void postOrder(TreeNode* root){
	cout << "-----postOrder search-----\n";
	stack<TreeNode*> s;
	//stack f���Դ洢�ڼ��η��ʸý�㣬����ڵ㷵�ط���Ϊ1�����ҽ�㷵��Ϊ2
	//��2��ʱ�򣬿��Ե����ýڵ㣬������ýڵ�ֵ
	stack<int> f;
	TreeNode* ref = root;

	bool begin = true;
	do	{
		if (begin){
			ref = root;
		}
		else{
			//����ڵ㷵�أ�refָ���ҽ��
			if (f.top() == 1){
				ref = s.top()->right;
				f.top()++;
			}
	//		cout << s.top()->val << endl;
			else if (f.top() == 2){
				//���ҽڵ㷵�أ�������ǰջ���������
				cout << s.top()->val << endl;
				s.pop();
				f.pop();
			}
		}
		begin = false;
		//�������������Ҷ�ڵ�,����ѭ��
		//��ȡջ��Ԫ�أ�refָ�� ���ҽ�㣬��ǰ����ѱ�ʹ�ã�����
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