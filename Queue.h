#pragma once
class Queue
{
private:
	int size { };
	int front{ 0 };
	int rear{ 0 };
	int added_elements { };
	int* array{ };
public:
	Queue();
	void Enqueue(int item);
	int  Dequeue();
	bool Is_Empty();
	bool Is_Full();
	int  next(int pos);
	void print();
};

