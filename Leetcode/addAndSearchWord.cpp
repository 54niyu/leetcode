#include"leetcode.h"
#define MAX 26

class Tree{
public:
	Tree(){
		for (int i = 0; i < MAX; i++){
			next[i] = NULL;
		}
		isEnd =false;
	}
	Tree* next[MAX];
	bool isEnd;
};

class WordDictionary {
public:

	// Adds a word into the data structure.
	void addWord(string word) {
		if (root == NULL)
			root = new Tree();
		
		Tree* ptr = root;
		for (char item : word){
	//		cout << item;
			if (ptr->next[item - 'a']==NULL){
		//		ptr->isEnd = false;
				ptr->next[item - 'a'] = new Tree();
				ptr = ptr->next[item - 'a'];
			}
			else{
				ptr = ptr->next[item - 'a'];
			}
		}
		ptr->isEnd = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return search(word, root);
	}
	bool search(string word, Tree* root){
		if (root == NULL)
			return false;
		Tree* ptr = root;

		int i = 0;
		for (; i < word.size(); i++){
			//			cout << word[i];
			if (word[i] == '.'){
				bool res=false;
				for (int j = 0; j < MAX; j++){
					res |= search(word.substr(i + 1),ptr->next[j]);

				}
				if (res)
					return true;
				else
					return false;
			}

			if (ptr->next[word[i] - 'a'] == NULL){
				return false;
			}
			else{
				ptr = ptr->next[word[i] - 'a'];
			}
		}
		if (ptr->isEnd)
			return true;
		else
			return false;
	}

	Tree *root = NULL;
};

//int main(){
//
//	 WordDictionary wordDictionary;
//
//	 wordDictionary.addWord("a");
//	 wordDictionary.addWord("aa");
//	 wordDictionary.addWord("abc");
//	 wordDictionary.addWord("wor");
//	 wordDictionary.addWord("worl");
//	 wordDictionary.addWord("next");
//	 wordDictionary.addWord("directionary");
//	 wordDictionary.addWord("world");
//	// wordDictionary.addWord("a");
//	cout<< wordDictionary.search("aa");
//	cout << wordDictionary.search("w.r");
//	cout << wordDictionary.search("dir..tonary");
//
//}
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");