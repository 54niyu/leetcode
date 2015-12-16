#include"leetcode.h"
#define MAX 26
class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		for (int i = 0; i < MAX; i++)
			next[i] = nullptr;
		isWord = false;
	}
	TrieNode *next[MAX];
	bool isWord;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode* ptr = root;
		for (auto c : word){
			if (ptr->next[c - 'a'] == nullptr)
				ptr->next[c - 'a'] = new TrieNode();
			ptr = ptr->next[c - 'a'];
		}
		ptr->isWord = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		if (root == nullptr)
			return false;
		TrieNode* ptr = root;
		for (auto c : word){
			if (ptr->next[c - 'a'] == nullptr)
				return false;
			ptr = ptr->next[c - 'a'];
		}
		if (ptr->isWord)
			return true;

		return false;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		if (root == nullptr)
			return false;
		TrieNode* ptr = root;
		for (auto c : prefix){
			if (ptr->next[c - 'a'] == nullptr)
				return false;
			ptr = ptr->next[c - 'a'];
		}
		for (int i = 0; i < 26; i++)
			if (ptr->next[i] != nullptr)
				return true;
	}

private:
	TrieNode* root;
};

//int main(){
//	Trie root;
//	root.insert("a");
//	root.insert("aaaa");
//	root.insert("helloword");
//	cout << root.search("aaaa");
//	cout << root.search("helloword");
//	cout << root.startsWith("hell");
//	cout << root.search("asdfsa");
//	cout << root.startsWith("aeee");
//	return 0;
//}