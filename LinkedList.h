#ifndef Linked_List_H
#define Linked_List_H
#include "Node.h"
class LinkedList
{
private:
	Node* head{};
	Node* tail{};
	int length = 0;
public:
	LinkedList(const LinkedList&)=delete;
	LinkedList();
	~LinkedList();
	void PrintLL();
	void Left_Rotate(int k);
	void Remove_Duplicates();
	void SwapPairs();
	void SwapHeadAndTail();
	void Reverse();
	void Insert_End(int value);
	void Insert_Sorted(int value);
	Node* get_nth(int index);
	int Search(int value);
	int Improved_Search(int value);
	void Insert_Front(int value);
	void Delete_Front();
	Node* get_nth_back(int index);
	void delete_nth(int index);

};

#endif