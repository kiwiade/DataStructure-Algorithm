#pragma once
#include <iostream>
using namespace std;

template<typename T>
class ArrayStack
{
private:
	int top = -1;
	int size = 10;
	T* stackArray = new T[size];

public:
	ArrayStack() {	}
	~ArrayStack() {	}

	bool Push(T value)
	{
		top++;
		if (IsFull())
			SizeUp();
		stackArray[top] = value;
		return true;
	}

	T Pop()
	{
		if (IsEmpty())
		{
			cout << "스택이 비었습니다" << endl;
			return 0;
		}
		else
		{
			T data = stackArray[top];
			top--;
			return data;
		}
	}

	void Print()
	{
		if (IsEmpty())
		{
			cout << "스택이 비었습니다" << endl;
		}
		else
		{
			for (int i = 0; i <= top; i++)
			{
				cout << stackArray[i] << " ";
			}
			cout << endl;
		}
	}

	bool IsEmpty()
	{
		return top == -1;
	}

	bool IsFull()
	{
		return top >= size;
	}

	void SizeUp()
	{
		size += 10;
		T* tempStackArray = new T[size];
		for (int i = 0; i < top; i++)
		{
			tempStackArray[i] = stackArray[i];
		}
		delete[] stackArray;
		stackArray = tempStackArray;
	}
};