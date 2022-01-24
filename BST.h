#ifndef BST_H
#define BST_H
#include "Node.h"
#include <vector>
class BST
{
public:
    int data{ };
	Node* root{ };
	BST(int data);
   /*~BST();*/
    void Insert(int value);
    void Print();
    bool IS_BST();
    bool Search(int value);
    BST* build(std::vector<int> &v);
    int GetMin();
    int GetMax();
    BST* Left { };
    BST* Right{ };
};
#endif
