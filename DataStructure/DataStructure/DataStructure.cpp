#include "pch.h"
#include <iostream>
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"

int main()
{
	// 단일 연결리스트
    std::cout << "Single Linked List\n"; 
	SingleLinkedList<int> newSingleList;
	newSingleList.Print();

	if(newSingleList.Add(10))
		newSingleList.Print();
	if(newSingleList.Add(20))
		newSingleList.Print();

	if(newSingleList.Remove(20))
		newSingleList.Print();

	cout << endl;

	// 이중 연결리스트
	std::cout << "Double Linked List\n";
	DoubleLinkedList<int> newDoubleList;
	newDoubleList.Print();

	if (newDoubleList.Add(7))
		newDoubleList.Print();
	newDoubleList.Add(8);
	newDoubleList.Add(4);
	newDoubleList.Print();
	newDoubleList.Insert(20,2);
	newDoubleList.Print();

	if (newDoubleList.Remove(8))
		newDoubleList.Print();
}