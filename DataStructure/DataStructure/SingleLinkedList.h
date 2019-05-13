#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template<typename T>
class SingleLinkedList
{
private:
	Node<T> *head = NULL;
	Node<T> *current = NULL;

public:
	SingleLinkedList()	{	}
	~SingleLinkedList()	{	}

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
			Node<T> *prev = NULL;
			current = head;
			while (current)
			{
				if (current->value == value)
				{
					if (head == current)
						head = head->next;
					else
						prev->next = current->next;

					delete current;
					return true;
				}
				prev = current;
				current = current->next;
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