#ifndef Stack_H
#define Stack_H
class Stack
{
public:
	int Size { };
public:
	Stack(int Size);
	void pop();
	int peek();
	void push(int item);
	void print();
	bool Is_Full();
	bool Is_Empty();
	~Stack();
private:
	int* arr { };
	int Top { };

};
#endif
