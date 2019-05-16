#include "pch.h"
#include <iostream>
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"

int main()
{
	// 단일 연결리스트
	std::cout << "Single Linked List\n";
	SingleLinkedList<int> newSingleList;
	newSingleList.Print();

	if (newSingleList.Add(10))
		newSingleList.Print();
	if (newSingleList.Add(20))
		newSingleList.Print();

	if (newSingleList.Remove(20))
		newSingleList.Print();


	// 이중 연결리스트
	cout << endl;
	cout << "Double Linked List\n";
	DoubleLinkedList<int> newDoubleList;
	newDoubleList.Print();

	if (newDoubleList.Add(7))
		newDoubleList.Print();
	newDoubleList.Add(8);
	newDoubleList.Add(4);
	newDoubleList.Print();

	if (newDoubleList.Insert(20, 2));
	newDoubleList.Print();

	if (newDoubleList.Remove(8))
		newDoubleList.Print();


	// 스택
	cout << endl;
	cout << "Stack\n";
	Stack<int> newStack;
	newStack.Print();

	newStack.Push(10);
	newStack.Push(22);
	newStack.Push(32);
	newStack.Print();

	cout << "Pop : " << newStack.Pop() << endl;
	newStack.Print();


	// 큐
	cout << endl;
	cout << "Queue\n";
	Queue<int> newQueue;
	newQueue.Print();

	newQueue.Push(11);
	newQueue.Push(22);
	newQueue.Push(33);
	newQueue.Print();

	cout << "Pop : " << newQueue.Pop() << endl;
	newQueue.Print();


	// 배열로 구현한 스택
	cout << endl;
	cout << "Stack Implemented Using Array\n";
	ArrayStack<int> newArrayStack;
	newArrayStack.Print();

	newArrayStack.Push(55);
	newArrayStack.Push(44);
	newArrayStack.Push(22);
	newArrayStack.Push(1254);
	newArrayStack.Push(77);
	newArrayStack.Print();

	cout << "Pop : " << newArrayStack.Pop() << endl;
	newArrayStack.Print();


	// 배열로 구현한 큐
	cout << endl;
	cout << "Queue Implemented Using Array\n";
	ArrayQueue<int> newArrayQueue;
	newArrayQueue.Print();

	for (int i = 1; i <= 20; i++)
	{
		newArrayQueue.Enqueue(i);
	}
	newArrayQueue.Print();

	cout << "Pop : " << newArrayQueue.Dequeue() << endl;
	newArrayQueue.Print();
	cout << "Pop : " << newArrayQueue.Dequeue() << endl;
	newArrayQueue.Print();

	newArrayQueue.Enqueue(21);
	newArrayQueue.Enqueue(22);
	newArrayQueue.Print();
	newArrayQueue.Enqueue(23);
	newArrayQueue.Enqueue(24);
	newArrayQueue.Print();
	newArrayQueue.Dequeue();
	newArrayQueue.Print();
}