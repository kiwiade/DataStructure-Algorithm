#include "pch.h"
#include <iostream>
#include "Sort.h"

int main()
{
	const int maxSize = 100;

	int* datas = MakeRandomNumber(maxSize);
	Print(datas, maxSize);
	std::cout << std::endl;

	//SelectionSort(datas, maxSize);
	//InsertionSort(datas, maxSize);
	//BubbleSort(datas, maxSize);
	//ShellSort(datas, maxSize);
	QuickSort(datas, 0, maxSize-1);
	Print(datas, maxSize);
}