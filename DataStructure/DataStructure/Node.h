#pragma once
template<typename T>
struct Node
{
	T value = 0;
	Node* prev = NULL;
	Node* next = NULL;
};