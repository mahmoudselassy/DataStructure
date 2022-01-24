#include <iostream>
using namespace std;
class trie {
private:
	static const int MAX_CHAR = 26;
	trie* child[MAX_CHAR];
	bool isLeaf{ };

public:
	trie() {
		// set an array to 0s. Here pointers to null
		memset(child, 0, sizeof(child));
	}

	void insert(string str, int idx = 0) {
		if (idx == (int)str.size())
			isLeaf = 1;
		else {
			int cur = str[idx] - 'a';
			if (child[cur] == 0)
				child[cur] = new trie();
			child[cur]->insert(str, idx + 1);
		}
	}
	void inserti(string str) {
		trie* cur = this;
		for (int i = 0; i < str.size(); i++)
		{
			int child = str[i] - 'a';
			if (!cur->child[i])
				cur->child[i] = new trie();
			cur = cur->child[i];
		}
		cur->isLeaf = true;
	}
	bool word_existi(string str) {
		trie* cur = this;
		for (int i = 0; i < str.size(); i++)
		{
			int child = str[i] - 'a';
			if (!cur->child[i])
				return false;
			cur = cur->child[i];
		}
		return cur->isLeaf;
	}
	bool word_exist(string str, int idx = 0) {
		if (idx == (int)str.size())
			return isLeaf;	// there is a string marked here

		int cur = str[idx] - 'a';
		if (!child[cur])
			return false;	// such path don't exist

		return child[cur]->word_exist(str, idx + 1);
	}

	bool prefix_exist(string str, int idx = 0) {
		if (idx == (int)str.size())
			return true;	// all subword covered

		int cur = str[idx] - 'a';
		if (!child[cur])
			return false;	// such path don't exist

		return child[cur]->prefix_exist(str, idx + 1);
	}
};