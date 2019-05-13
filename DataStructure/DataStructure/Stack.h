#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template<typename T>
class Stack
{
private:
	Node<T> *head = NULL;
	Node<T> *top = NULL;

public:
	Stack() {	}
	~Stack() {	}

	bool Push(T value)
	{
		Node<T> *newData = new Node<T>;
		newData->value = value;

		if (head == NULL)
		{
			head = newData;
			top = head;
		}
		else
		{
			newData->prev = top;
			top->next = newData;
			top = newData;
		}
		return true;
	}

	T Pop()
	{
		if (top == NULL)
		{
			cout << "������ ������ϴ�" << endl;
			return 0;
		}
		else
		{
			T data = top->value;
			top = top->prev;
			delete top->next;
			top->next = NULL;
			return data;
		}
	}

	void Print()
	{
		if (head == NULL)
		{
			cout << "������ ������ϴ�" << endl;
		}
		else
		{
			Node<T> *current = head;
			while (current->next)
			{
				cout << current->value << " ";
				current = current->next;
			}
			cout << current->value << endl;
		}
	}
};