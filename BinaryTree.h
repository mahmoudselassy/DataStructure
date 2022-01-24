#include "Node.h"
#ifndef Binary_Tree_H
#define Binary_Tree_H
class BinaryTree
{
private:
	void  Clear(Node* current);
public:
	Node* root { };
	BinaryTree(int rootvalue);
	~BinaryTree();
	Node* Insert(int value);
	void  Print(Node* current);
	int Min(Node* current);
	int GetNodesNum(Node* current);
	int GetLeafNum(Node* current);
	bool Search(Node* current, int key);
	int maxDepth(Node* current);
	bool Is_Perfect();
	void Print_InOrder();
	void Traverse_Left_boundry();
	void BFS();
};
#endif
