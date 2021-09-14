#include "LinkedList.h"
#include "Node.h"
#include <iostream>
LinkedList::LinkedList() {};
void LinkedList::PrintLL() {
	Node* tempnode = head;
	while(tempnode!=nullptr)
	{
		std::cout<< tempnode->data << " ";
		tempnode = tempnode->next;
	}
}
void LinkedList::Insert_End(int value) {
	Node* node = new Node(value);
	if (head == nullptr)
		head = tail = node;
	else {
		tail->next = node;
		tail = node;
	}
	length++;
}
void LinkedList::Insert_Front(int value) {
	Node* node = new Node(value);
	if (head == nullptr)
		head = tail = node;
	else {
		node->next = head;
		head = node;
	}
	length++;
}
void LinkedList::Delete_Front() {
	if (head->next == nullptr) {

		delete head;
	}
	else {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	length--;
}
Node* LinkedList::get_nth(int index) {
	int i = 0;
	for (Node* cur = head; cur; cur = cur->next)
	{
		i++;
		if (i == index)
			return cur;
	}
	return nullptr;
}
void LinkedList::delete_nth(int index) {
	if (index == 1) {
		Delete_Front();
	
	
	}
	int i = 0;
	Node* prev = new Node(0);
	for (Node* cur = head; cur;prev=cur, cur = cur->next)
	{
		i++;
		if (i == index) {
			prev->next = cur->next;
			break;
		}
	}
}
Node* LinkedList::get_nth_back(int index) {
		int i = 0;
		for (Node* cur = head; cur; cur = cur->next)
		{
			i++;
			if (i == (length-index+1))
				return cur;
		}
		return nullptr;
	}
int LinkedList::Search(int value) {
	int i = 0;
	for (Node* cur = head; cur; cur = cur->next)
	{
		if (cur->data == value)
		{
			return i+1;
		}
		i++;
	}
	return -1;

}
void LinkedList::SwapPairs() {
	Node* first = head;
	Node* second = head->next;
	for (int i = 0; i < (length / 2); i++) {
		int temp = first->data;
		first->data = second->data;
		second->data = temp;
		if (second->next) {
			first = second->next;
			second = first->next;
		}
	}
}
/*void LinkedList::Reverse() {
	tail = head;
	Node* Previous = head;
	head = head->next;
	while (head) {
		Node* Temp = head->next;
		head->next = Previous;
		Previous = head;
		head = Temp;
	}
	head=Previous;
	tail->next = nullptr;
}*/
void LinkedList::Insert_Sorted(int value) {
	if (value >= tail->data)
		Insert_End(value);
	else if (value <= head->data)
		Insert_Front(value);
	else {
		for (Node* cur = head, *prev = nullptr; cur; prev = cur, cur = cur->next) {
			if (value <= cur->data) {
				Node* temp = new Node(value);
				++length;
				temp->next = prev->next;
				prev->next = temp;
				break;
			}
		}

	}
}
void LinkedList::SwapHeadAndTail() {
	Node* PrevTail = head;
	Node* NextHead = head->next;
	while (PrevTail->next->next) {
		PrevTail = PrevTail->next;
	}
	head->next = nullptr;
	tail->next = NextHead;
	PrevTail->next = head;
	head = tail;
	tail = head;

}
void LinkedList::Left_Rotate(int k) {
	Node* Temp = head;
	for (int i = 0; i < k-1; i++) {
		Temp = Temp->next;
	}
	Node* Temp2=Temp->next;
	Temp->next = nullptr;
	tail->next = head;
	tail = Temp;
	head = Temp2;

}
void LinkedList::Remove_Duplicates() {
	for (Node* cur = head; cur; cur = cur->next) {
		for (Node* Next = cur->next; Next; Next = Next->next) {
			if (cur->data == Next->data) {
				for (int i = 0; i < length; i++) {
					int temp = 0;
					if (get_nth(i + 1)->data == Next->data) {
						temp++;
						if (temp == 1) {
							continue;
						}
						else
						{
							delete_nth(i + 1);
						}
					
					
					}
				}


			}


		}
	}
}
/*int LinkedList::Improved_Search(int value) {
	int i = 0;
	for (Node* cur = head,*prev=nullptr; cur;prev=cur, cur = cur->next)
	{
		if (cur->data == value)
		{
			std::swap(prev->data, cur->data);
			return i+1;
		}
		i++;
	}
	return -1;

}*/
LinkedList::~LinkedList() {
	Node* temp = head;
	Node* Nexttemp = temp->next;
	for (int i = 0; i < length; i++) {
		delete temp;
		temp = Nexttemp;
		Nexttemp = temp->next;
	}
	/*
	while (head) {
		Node* current = head->next;
		delete head;
		head = current;
	}
	*/
}