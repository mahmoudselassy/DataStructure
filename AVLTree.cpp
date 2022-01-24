#include "AVLTree.h"
#include <iostream>


BinaryNode* AVLTree::right_rotation(BinaryNode* Q)
{
	std::cout << "right_rotation " << Q->data << "\n";
	BinaryNode* P = Q->left;
	Q->left = P->right;
	P->right = Q;
	Q->update_height();
	P->update_height();
	return P;
}

BinaryNode* AVLTree::left_rotation(BinaryNode* P)
{
	std::cout << "left_rotation " << P->data << "\n";
	BinaryNode* Q = P->right;
	P->right = Q->left;
	Q->left = P;
	Q->update_height();
	P->update_height();
	return Q;
}

BinaryNode* AVLTree::balance(BinaryNode* node)
{
	if (node->balance_factor() == 2)
	{
		if (node->left->balance_factor() == -1)
			node->left = left_rotation(node->left);
		node = right_rotation(node);

	}
	else if (node->balance_factor() == -2)
	{
		if (node->left->balance_factor() == 1)
			node->right = right_rotation(node->right);
		node = left_rotation(node);

	}
	return node;
}

BinaryNode* AVLTree::insert_node(int target, BinaryNode* node)
{
	if (target < node->data)
	{
		if (node->left)
			node->left = insert_node(target, node->left);
		else
			node->left = new BinaryNode(target);
	}
	else if (target > node->data)
	{
		if (node->right)
			node->right = insert_node(target, node->right);
		else
			node->right = new BinaryNode(target);
	}
	node->update_height();
	return balance(node);
}
void AVLTree::insert_value(int target) {
	if (!root)
		root = new BinaryNode(target);
	else
		root = insert_node(target, root);
}
