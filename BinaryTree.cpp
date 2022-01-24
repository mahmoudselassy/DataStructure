#include "BinaryTree.h"
#include <iostream>
#include <stack>
#include <Queue>

BinaryTree::BinaryTree(int rootvalue):root(new Node(rootvalue))
{

}
Node* BinaryTree::Insert(int value)
{
	Node* node = new Node(value);
	return node;
}

void BinaryTree::Print(Node* current)
{
	if (!current)
		return;
	std::cout << " " << current->data << " ";
	Print(current->left);
	Print(current->right);
}
void BinaryTree::Clear(Node* current)
{
	if (!current)
		return;
	Clear(current->left);
	Clear(current->right);
	delete current;
	
}
BinaryTree::~BinaryTree()
{
	Clear(root);
}
int BinaryTree::Min(Node* current)
{
	if (current == NULL)
		return INT_MAX;
	int res = current->data;
	int l =Min(current->left);
	int r =Min(current->right);
	if (l < res)
		res = l;
	if (r < res)
		res = r;
	return res;

}

int BinaryTree::GetNodesNum(Node* current)
{
	static int num = 0;
	if (!current)
		return NULL;
	num++;
    GetNodesNum(current->left);
    GetNodesNum(current->right);
	return num;
}
int BinaryTree::GetLeafNum(Node* current)
{
	static int num = 0;
	if (!current)
		return NULL;
	if (current->left == nullptr && current->right == nullptr)
		num++;
	GetLeafNum(current->left);
	GetLeafNum(current->right);
	return num;
}
int BinaryTree::maxDepth(Node* current)
{
	if (current == NULL)
		return 0;
	else
	{
		int lDepth = maxDepth(current->left);
		int rDepth = maxDepth(current->right);
		if (lDepth > rDepth)
			return(lDepth + 1);
		else 
			return(rDepth + 1);
	}
}
bool BinaryTree::Search(Node* current, int key)
{
	if (current == NULL)
		return false;
	if (current->data == key)
		return true;
	bool res1 = Search(current->left, key);
	if (res1) 
		return true;
	bool res2 = Search(current->right, key);
	return res2;
}
bool BinaryTree::Is_Perfect()
{
	int h = maxDepth(root) - 1;
	int n = GetNodesNum(root);
	return pow(2, h + 1) - 1 == n;
}
void BinaryTree::Print_InOrder()
{
	Node* current = root;
	std::stack<Node*> stack;
	while (current || stack.empty() == false)
	{
		while (current)
		{
			stack.push(current);
			current = current->left;
		}
		current = stack.top();
		stack.pop();
		std::cout << current->data << " ";
		current = current->right;
	}
}
void BinaryTree::Traverse_Left_boundry() 
{
	Node* current = root;
	std::cout << current->data << " ";
	while (current) 
	{
		if (current->left) {
			current = current->left;
			std::cout << current->data << " ";
		}
		else if (current->right)
		{
			current = current->right;
			std::cout << current->data << " ";
		}
		else
			break;
	}
}

void BinaryTree::BFS()
{
	std::queue<Node*> q;
	q.push(root);
	while (!q.empty()) 
	{
		Node* current = q.front();
		std::cout << current->data;
		q.pop();
		if (current->left)
			q.push(current->left);
		if (current->right)
			q.push(current->right);
	}
}

