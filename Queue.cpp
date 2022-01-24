#include "Queue.h"
#include <iostream>
Queue::Queue()
{
	array = new int[size];
}

void Queue::Enqueue(int item)
{
	if (!Is_Full()) {
		array[rear] = item;
		rear = next(rear);
		added_elements++;
	}
}

int Queue::Dequeue()
{
	if (!Is_Empty()) {
		int value = array[front];
		front = next(front);
		--added_elements;
		return value;
	}
	return -1;
}

bool Queue::Is_Empty()
{
	return added_elements==0;
}

bool Queue::Is_Full()
{
	return added_elements==size;
}

int Queue::next(int pos)
{
	return (pos+1)%size;
}

void Queue::print()
{
	for (int i = 0; i < size; i++)
		std::cout << array[i] << " ";
}
