#pragma once
#include "BNode.h"
#include <iostream>
using namespace std;

template<typename T>
class BinaryTree
{
private:
	BNode<T> *head = NULL;

	bool AddNode(BNode<T>* parentNode, BNode<T>* newNode)
	{
		if (parentNode->value > newNode->value)
		{
			if (parentNode->left == NULL)
			{
				parentNode->left = newNode;
				return true;
			}
			else
			{
				AddNode(parentNode->left, newNode);
			}
		}
		else
		{
			if (parentNode->right == NULL)
			{
				parentNode->right = newNode;
				return true;
			}
			else
			{
				AddNode(parentNode->right, newNode);
			}
		}
		return false;
	}

	void Print(BNode<T>* node)
	{
		if (node == NULL)
			return;

		if (node->left)
			Print(node->left);

		cout << node->value << " ";

		if (node->right)
			Print(node->right);
	}

public:
	BinaryTree() {	}
	~BinaryTree() {	}

	bool Add(T value)
	{
		BNode<T>* newData = new BNode<T>;
		newData->value = value;

		if (head == NULL)
		{
			head = newData;
			return true;
		}
		else
		{
			return AddNode(head, newData);
		}
	}

	void Print()
	{
		Print(head);
	}
};