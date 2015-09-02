#include<iostream>
#include<vector>
#include<string>

using namespace std;

enum Type{
	//²Ù×÷·û
	Op,
	//Êý×Ö
	Nu,
	//Ñ¡Ôñ
	Ch,
};

enum Ope{
	Plus,
	Minus,
	Mul,
};

class Input{
public:
	Input(){};
	Input(string input);

	void Input::divide(Input *&a1, Input *&a2, int pos);

	int _opeNumber;
	vector<char> _ope;
	vector<int> _dig;
};

inline Input::Input(string input){
	int opeNumber = 0;
	int Digital=0;
	for (int i = 0; i < input.length(); i++){
		if (input[i] <= '9'&&input[i] >= '0'){
			Digital = Digital * 10 + input[i] - '0';
		}
		else{
			opeNumber++;
			this->_ope.push_back(input[i]);
			this->_dig.push_back(Digital);
			Digital = 0;
		}
	}
	this->_opeNumber = opeNumber;
	this->_dig.push_back(Digital);
}
inline void Input::divide(Input *&a1, Input *&a2, int pos){
	a1 = new Input();
	a2 = new Input();
	a1->_opeNumber = pos;
	a2->_opeNumber = this->_opeNumber - pos-1;
	for (int i = 0; i < pos; i++){
		a1->_ope.push_back(this -> _ope[i]);
	}
	for (int i = pos + 1; i < this->_opeNumber; i++){
		a2->_ope.push_back(this->_ope[i]);
	}

	for (int i = 0; i < pos+1; i++){
		a1->_dig.push_back(this -> _dig[i]);
	}
	for (int i = pos + 1; i < this->_opeNumber+1; i++){

		a2->_dig.push_back(this->_dig[i]);
	}
}

class Node{
public:
	Node(){};
	Node(const Input &input);
	static Node* createTree(Input *input);

	Type _nodeType;
	int _val;
	char _ope;
	int _childNumber;
	vector<Node*> _child;
};

inline Node* Node::createTree(Input *input){
	Node *nd = new Node();
	if (input->_opeNumber == 0){
		nd->_childNumber = 0;
		nd->_nodeType = Nu;
		nd->_val = input->_dig[0];
	}
	else if (input->_opeNumber == 1){
		nd->_nodeType = Op;
//		nd->_val = input->_ope[0];
		nd->_ope = input->_ope[0];
		nd->_childNumber = 2;
		Input *a1=NULL, *a2=NULL;
		input->divide(a1, a2, 0);
//		input->divide(a1, a2, 0);
		nd->_child.push_back(Node::createTree(a1));
		nd->_child.push_back(Node::createTree(a2));
	//	nd->_child[0] = Node::createTree(a1);
	//	nd->_child[1] = Node::createTree(a2);
	}
	else{
		nd->_nodeType = Ch;
		nd->_childNumber = input->_opeNumber;
		for (int i = 0; i < input->_opeNumber;i++){
			Node *ch = new Node();
			Input *a1=NULL, *a2=NULL;
			char o = input->_ope[i];

			input->divide(a1, a2, i);
//			input->divide(a1, a2, i);

			ch->_nodeType = Op;

			ch->_ope = o;

			ch->_childNumber = 2;
//			ch->_child[0] = Node::createTree(a1);
			ch->_child.push_back(Node::createTree(a1));
			ch->_child.push_back(Node::createTree(a2));
//			ch->_child[1] = Node::createTree(a2);
//			nd->_child[i] = ch;
			nd->_child.push_back(ch);
		}
	}
	return nd;
}


class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		Input in(input);
		Node *nd=Node::createTree(&in);
		vector<int> result = trave(nd);
		return result;

	}
	vector<int> trave(const Node* nd){
		vector<int> result;
		if (nd->_nodeType == Ch){
			for (int i = 0; i < nd->_childNumber; i++){
				vector<int> temp = trave(nd->_child[i]);
				vector<int>::iterator it = temp.begin();
				while (it != temp.end()){
					result.push_back(*it);
					it++;
				}
			}
		}
		else if (nd->_nodeType == Op){
			vector<int> a1 = trave(nd->_child[0]);
			vector<int> a2 = trave(nd->_child[1]);
			
			vector<int>::iterator it = a1.begin();
			while (it != a1.end()){
				vector<int>::iterator it2 = a2.begin();
				while (it2 != a2.end()){
					switch (nd->_ope){
					case '-':result.push_back((*it) - (*it2)); break;
					case '+':result.push_back((*it) + (*it2)); break;
					case '*':result.push_back((*it) * (*it2)); break;
					}
					it2++;
				}
				it++;
			}
		}
		else{
			result.push_back(nd->_val);
		}
		return result;
	}
};
//int main(){
//	Solution s;
//	vector<int> result = s.diffWaysToCompute("2*3-4*5-1+6");
//	vector<int>::iterator it = result.begin();
//	while (it != result.end()){
//		cout << *it << endl;
//		it++;
//	}
////	Input in("2*3-4*5");
////	Node *nd = Node::createTree(&in);
//
//}