#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template<typename T>
class DoubleLinkedList
{
private:
	Node<T> *head = NULL;
	Node<T> *current = NULL;

public:
	DoubleLinkedList() {};
	~DoubleLinkedList() {};

	bool Add(T value)
	{
		Node<T>* newData = new Node<T>;
		newData->value = value;

		if (head == NULL)
		{
			head = newData;
		}
		else
		{
			current = head;
			while (current->next)
			{
				current = current->next;
			}
			current->next = newData;
			newData->prev = current;
		}
		return true;
	}

	bool Insert(T value, int place)
	{
		Node<T>* newData = new Node<T>;
		newData->value = value;
		if (head == NULL)
		{
			head = newData;
			return true;
		}
		else
		{
			if (place == 1)
			{
				newData->next = head;
				head->prev = newData;
				head = newData;
			}
			else if (place > Count())
			{
				return false;
			}
			else
			{
				current = head;
				Node<T>* prev = head;
				for (int i = 0; i < place - 1; i++)
				{
					prev = current;
					current = current->next;
				}

				newData->prev = prev;
				newData->next = current;
				prev->next = newData;
				current->prev = newData;
			}
		}
		return true;
	}

	bool Remove(T value)
	{
		if (head == NULL)
		{
			cout << "삭제할 값이 없습니다" << endl;
			return false;
		}
		else
		{
			if (value == head->value)
			{
				head = head->next;
				delete head->prev;
				head->prev = NULL;
				return true;
			}
			else
			{
				current = head;
				Node<T>* prev = head;
				while (current->next)
				{
					if (value == current->value)
					{
						prev->next = current->next;
						current->next->prev = prev;
						delete current;
						return true;
					}
					prev = current;
					current = current->next;
				}
			}
		}
		return false;
	}

	void Print()
	{
		if (head == NULL)
		{
			cout << "리스트가 비어있습니다" << endl;
		}
		else
		{
			current = head;
			while (current->next)
			{
				cout << current->value << " ";
				current = current->next;
			}
			cout << current->value << endl;
		}
	}

	int Count()
	{
		if (head == NULL)
			return 0;

		int count = 0;
		current = head;
		while (current->next)
		{
			count++;
			current = current->next;
		}
		return count + 1;
	}
};