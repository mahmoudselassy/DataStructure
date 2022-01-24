#pragma once
#include <iostream>
struct BinaryNode {
	int data{ };
	int height{ };
	BinaryNode* left{ };
	BinaryNode* right{ };

	BinaryNode(int data) :
		data(data) {
	}

	int ch_height(BinaryNode* node) {	// child height
		if (!node)
			return -1;			// -1 for null
		return node->height;	// 0 for leaf
	}
	int update_height() {	// call in end of insert function
		return height = 1 + std::max(ch_height(left), ch_height(right));
	}
	int balance_factor() {
		return ch_height(left) - ch_height(right);
	}
};

class AVLTree
{
public:
	BinaryNode* root{ };
	BinaryNode* right_rotation(BinaryNode* Q);
	BinaryNode* left_rotation(BinaryNode* P);
	BinaryNode* balance(BinaryNode* node);
	BinaryNode* insert_node(int target, BinaryNode* node);
	void insert_value(int target);
};

