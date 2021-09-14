#include <iostream>

class Vector {
private:
	int* arr = nullptr;
	int size = 0;
	int Capacity =0;
public:
	Vector(int size):size(size) {
		if (size == 0)
			size = 1;
		Capacity = size + 10;
		arr = new int[Capacity];
	}
	int get(int i) {
		return arr[i];
	}
	void set(int i, int value) {
		arr[i] = value;
	}
	void print() {
		for (int i = 0; i < size; i++)
			std::cout << arr[i] << std::endl;
	}
	int find(int value) {
		for (int i = 0; i < size; i++)
			if (arr[i] == value)
				return i;
		return -1;
	}
	void Push_Back(int value) {
		if (Capacity == size)
			Expand_Capacity();
		size = size + 1;
		arr[size-1] = value;
	}
	void Expand_Capacity() {
		Capacity *= 2;
		int* temp = new int[Capacity];
		for (int i = 0; i < size; i++)
			temp[i]= arr[i];
		std::swap(arr, temp);
		delete[] temp;
	}
	int Get_Front() {
		return arr[0];
	}
	int Get_Back() {
		return arr[size - 1];
	}
	void insert(int index, int value) {
		if (Capacity == size)
			Expand_Capacity();
		size = size + 1;
		for (int i = size - 1; i >= index; i--)
			arr[i] = arr[i-1];
		arr[index] = value;
	}
	void Right_Rotation(){
		int Back = Get_Back();
		for (int i = size - 2; i >= 0; i--)
			arr[i + 1] = arr[i];
		arr[0] = Back;
	}void Right_Rotation_With_Steps(int Step) {
		int* Back = new int[Step] { };
		for (int i = size - Step,j=0; i < size && j<Step; i++,j++)
			Back[j] = arr[i];
		for (int i = size - 1; i >= Step; i--)
			arr[i] = arr[i-Step];
		for (int i = 0; i < Step; i++)
		    arr[i] = Back[i];
		delete[] Back;
	}
	void Left_Rotation() {
		int Front = Get_Front();
		for (int i = 0; i < size-1; i++)
			arr[i] = arr[i+1];
		arr[size-1] = Front;
	}
	int pop(int index)
	{
		int dvalue = arr[index];
		for (int i = index; i < size - 1; i++)
			arr[i] = arr[i + 1];
		size = size - 1;
		return dvalue;
	}
	int Transposition_Search(int Value)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == Value)
			{
				int temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
				return i;
			}
		}
	}
	~Vector() {
		delete[] arr;
		arr = nullptr;
	}
};
