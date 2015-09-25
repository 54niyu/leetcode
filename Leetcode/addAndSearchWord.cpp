#include"leetcode.h"
#define MAX 26

class Tree{
public:
	Tree(){
		for (int i = 0; i < MAX; i++){
			next[i] = NULL;
		}
		num = 0;
	}
	Tree* next[MAX];
	int num;
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
				ptr->next[item - 'a'] = new Tree();
				ptr->next[item - 'a']->num = ptr->num + 1;
				ptr = ptr->next[item - 'a'];
			}
			else{
				ptr = ptr->next[item - 'a'];
			}
		}
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
				break;
			}
			else{
				ptr = ptr->next[word[i] - 'a'];
			}
		}
		if (i == word.size())
			return true;
		else
			return false;
	}

	Tree *root = NULL;
};

int main(){

	 WordDictionary wordDictionary;
	 wordDictionary.addWord("word");
	 wordDictionary.addWord("world");
	 wordDictionary.addWord("next");
	 wordDictionary.addWord("directionary");
	cout<< wordDictionary.search("dir..tionary");
	cout << wordDictionary.search("w.ld");

}
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");