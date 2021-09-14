#ifndef Node_H
#define Node_H
class Node
{
public:
	int data;
	Node* next=nullptr;
	Node(int data);
	~Node();
};

#endif