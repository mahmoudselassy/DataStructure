#include "BST.h"
#include <iostream>
#include <vector>
using namespace std;
BST::BST(int data) : data(data)
{

}

void BST::Insert(int value)
{

	if (data > value)
	{
		if (!Left)
			Left = new BST(value);
		else
			Left->Insert(value);
		
	}
	else if (data < value) 
	{
		if (!Right)
			Right = new BST(value);
		else
			Right->Insert(value);
	}
	
}

void BST::Print()
{
	if (Left)
		Left->Print();
	std::cout << data << " ";
	if (Right)
		Right->Print();
}
int BST::GetMin()
{
	BST* current = this;
	while (current && current->Left) 
		current = current->Left;
	return current->data;
}

int BST::GetMax()
{
	BST* current = this;
	while (current && current->Right)
		current = current->Right;
	return current->data;
}
bool BST::Search(int value)
{
	BST* t = this;
	while (t) {
		if (t->data == value)
			return true;
		if (t->data > value)
			t = t->Left;
		else
			t = t->Right;
	}
	return false;
}

BST* BST::build(vector<int> &v)
{
	BST* bst = new BST(v[v.size()/2]);
	for (int i = 0; i < v.size(); i++) {
		if (i == v.size() / 2)
			continue;
		bst->Insert(v[i]);
	}
	return bst;
}
