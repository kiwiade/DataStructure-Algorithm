#pragma once
template<typename T>
struct BNode
{
	T value = 0;
	BNode* left = NULL;
	BNode* right = NULL;
};