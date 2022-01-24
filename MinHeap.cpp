#include "MinHeap.h"

int MinHeap::Left(int Node)
{
	int p = 2 * Node + 1;
	if (p >= size)
		return -1;
	return p;
}

int MinHeap::Right(int Node)
{
	int p = 2 * Node + 2;
	if (p >= size)
		return -1;
	return p;
}

int MinHeap::Parents(int Node)
{   
	if (Node)
		return (Node - 1) / 2;
	return -1;
}

void MinHeap::heapify_up(int child_pos)
{
	int par_pos = Parents(child_pos);
	if (child_pos == 0 || array[par_pos] < array[child_pos])
		return;
    std::swap(array[child_pos], array[par_pos]);
	heapify_up(par_pos);
}

void MinHeap::heapify_down(int parent_pos)
{
	int Left_pos  = Left (parent_pos);
	int Right_pos = Right(parent_pos);
	if (Left_pos == -1)
		return;
	if (Right_pos == -1 && array[Right_pos] <= array[Left_pos])
		Left_pos = Right_pos;
	if (array[parent_pos] > array[Left_pos]) {
		std::swap(array[parent_pos], array[Left_pos]);
		heapify_down(Left_pos);
	}
}

MinHeap::MinHeap()
{
	array = new int[capacity] {};
	size = 0;
}

MinHeap::MinHeap(const std::vector<int>& v)
{
	if ((int)v.size() <= capacity) {
		array = new int[capacity] {};
		size = v.size();

		for (int i = 0; i < (int)v.size(); ++i)
			array[i] = v[i];

	}
}

MinHeap::~MinHeap()
{
	delete[] array;
	array = nullptr;
}

void MinHeap::push(int key)
{
	if (size + 1 <= capacity) {
		array[size++] = key;
		heapify_up(size - 1);
	}
}

void MinHeap::pop()
{
	if (!isempty()) {
		array[0] = array[--size];
		heapify_down(0);
	}
}
void MinHeap::Heapify() {	// O(n)
	for (int i = size / 2 - 1; i >= 0; --i)
		heapify_down(i);
}
int MinHeap::top()
{
	if (isempty())
		return -1;
	return array[0];
}

bool MinHeap::isempty()
{
	return size == 0;
}
