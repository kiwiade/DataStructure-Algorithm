#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template<typename T>
class Queue
{
private:
	Node<T> *head = NULL;
	Node<T> *tail = NULL;

public:
	Queue() {	}
	~Queue() {	}

	bool Push(T value)
	{
		Node<T> *newData = new Node<T>;
		newData->value = value;

		if (head == NULL)
		{
			head = newData;
			tail = head;
		}
		else
		{
			newData->prev = tail;
			tail->next = newData;
			tail = newData;
		}
		return true;
	}

	T Pop()
	{
		if (tail == NULL)
		{
			cout << "큐가 비었습니다" << endl;
			return 0;
		}
		else
		{
			T data = head->value;
			head = head->next;
			delete head->prev;
			head->prev = NULL;
			return data;
		}
	}

	void Print()
	{
		if (head == NULL)
		{
			cout << "큐가 비었습니다" << endl;
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