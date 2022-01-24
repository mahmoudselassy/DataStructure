#pragma once
#include <vector>
class MinHeap
{
private:
	int* array{ };
	int size{ };
	int capacity{ 1000 };
	int Left(int Node);
	int Right(int Node);
	int Parents(int Node);
	void heapify_up(int child_pos);
	void heapify_down(int parent_pos);
	void Heapify();
public:
	MinHeap();
	MinHeap(const std::vector<int>& v);
	~MinHeap();
	void push(int key);
	void pop();
	int top();
	bool isempty();
private:
};

