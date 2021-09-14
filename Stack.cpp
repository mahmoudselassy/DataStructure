#include "Stack.h"
#include <iostream>
Stack::Stack(int Size):Size(Size),Top(-1)
{
	arr = new int[Size];
}
void Stack::push(int item) 
{
	if (!Is_Full())
	{
		Top = Top + 1;
		arr[Top] = item;
	}
	else
		std::cout << "Over Size";
}
int Stack::peek() 
{
	if (!Is_Empty())
		return arr[Top];
	else
		return -1;
}
void Stack::pop()
{
	if (!Is_Empty()) {
		arr[Top] = NULL;
		Top = Top - 1;
	}
}
void Stack::print() {

	for (int i = 0; i < Top + 1; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
bool Stack::Is_Full() 
{
	return Top == Size - 1;
}
bool Stack::Is_Empty()
{
	return Top == -1;
}
Stack::~Stack()
{
	delete[] arr;
}