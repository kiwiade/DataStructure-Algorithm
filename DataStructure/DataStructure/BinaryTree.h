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

	BNode<T>* SearchParent(T value)
	{
		if (head->value == value)
		{
			return NULL;
		}
		else
		{
			BNode<T>* result = NULL;
			BNode<T>* current = NULL;
			current = head;
			result = current;
			while (current != NULL)
			{
				if (current->value > value)
				{
					result = current;
					current = current->left;
				}
				else if (current->value < value)
				{
					result = current;
					current = current->right;
				}
				else
					return result;
			}
			return NULL;
		}
	}

	BNode<T>* SearchMinNode(BNode<T>* parent)
	{
		if (parent == NULL)
			return NULL;

		if (parent->left == NULL)
			return parent;
		else
			SearchMinNode(parent->left);
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

	BNode<T>* Search(T value)
	{
		if (head->value == value)
		{
			return head;
		}
		else
		{
			BNode<T>* result = NULL;
			result = head;
			while (result != NULL)
			{
				if (result->value > value)
					result = result->left;
				else if (result->value < value)
					result = result->right;
				else
					return result;
			}
			return NULL;
		}
	}

	bool Remove(T value)
	{
		BNode<T>* removeNode = Search(value);
		BNode<T>* parentNode = SearchParent(value);
		if (removeNode == NULL)
		{
			return false;
		}
		// 루트노드일 경우. 아래의 자식 둘다있는 케이스와 동일하게 처리
		else if (parentNode == NULL)
		{
			BNode<T>* minNode = SearchMinNode(removeNode->right);
			T tempValue = minNode->value;
			Remove(minNode->value);
			removeNode->value = tempValue;
		}
		else 
		{
			// 자식이 없으면 그냥 잘라냄(있던 자리를 NULL로 만들고 삭제)
			if (removeNode->left == NULL && removeNode->right == NULL)
			{
				if (parentNode->left == removeNode)
					parentNode->left = NULL;
				else
					parentNode->right = NULL;

				delete removeNode;
				return true;
			}
			// 자식이 둘 다 있는 경우
			else if (removeNode->left != NULL && removeNode->right != NULL)
			{
				// 최소값 노드를 찾아 삭제함
				BNode<T>* minNode = SearchMinNode(removeNode->right);
				T tempValue = minNode->value;
				bool result = Remove(minNode->value);
				// 최소값 노드를 삭제된 자리로 옮김(값을 덮어씌워버림. 자식은 그대로 유지되게)
				removeNode->value = tempValue;
				return result;
			}
			// 자식이 하나만 있는 경우 남은 자식을 부모에게 연결해준 후 삭제
			else
			{
				if (parentNode->left == removeNode)
				{
					if (removeNode->left != NULL)
						parentNode->left = removeNode->left;
					else
						parentNode->left = removeNode->right;
				}
				else
				{
					if (removeNode->left != NULL)
						parentNode->right = removeNode->left;
					else
						parentNode->right = removeNode->right;
				}
				delete removeNode;
				return true;
			}
		}
	}

	void Print()
	{
		Print(head);
		cout << endl;
	}
};