#pragma once
#include <iostream>
#include <ctime>

int* MakeRandomNumber(int size)
{
	srand((unsigned int)time(0));
	int* datas = new int[size];
	for (int i = 0; i < size; i++)
	{
		datas[i] = rand() % 1000;
	}
	return datas;
}
void Print(int* datas, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << datas[i] << " ";
	}
	std::cout << std::endl;
}

void SelectionSort(int* datas, int size)
{
	int min;
	int temp;
	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (datas[j] < datas[min])
			{
				min = j;
			}
		}

		temp = datas[min];
		datas[min] = datas[i];
		datas[i] = temp;
	}
}

void InsertionSort(int* datas, int size)
{
	int current;
	int last = 0;
	for (int i = 0; i < size; i++)
	{
		current = datas[i];
		for (int j = i; j >= 0; j--)
		{
			if (datas[j - 1] > current && j > 0)
			{
				datas[j] = datas[j - 1];
			}
			else
			{
				last = j;
				break;
			}
		}
		datas[last] = current;
	}
}

void BubbleSort(int* datas, int size)
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size - i; j++)
		{
			if (datas[j - 1] > datas[j])
			{
				temp = datas[j];
				datas[j] = datas[j - 1];
				datas[j - 1] = temp;
			}
		}
	}
}

// ShellSort를 위한 부분삽입정렬
void PartInsertionSort(int* datas, int gap, int start, int end)
{
	int current = 0;
	int last = 0;
	for (int i = start + gap; i < end; i += gap)
	{
		current = datas[i];
		for (int j = i; j >= 0; j -= gap)
		{
			if (datas[j - gap] > current && j > gap)
			{
				datas[j] = datas[j - gap];
			}
			else
			{
				last = j;
				break;
			}
		}
		datas[last] = current;
	}
}

void ShellSort(int* datas, int size)
{
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		if (gap % 2 == 0)
			gap++;

		for (int i = 0; i < gap; i++)
			PartInsertionSort(datas, gap, i, size);
	}
}

void QuickSort(int* datas, int start, int end)
{
	if (end <= start)
		return;

	int pivot = datas[start];
	int left = start + 1;
	int right = end;
	int temp;

	while (left <= right)
	{
		while (datas[left] <= pivot && left < end)
			left++;

		while (datas[right] >= pivot && right > start)
			right--;

		if (left < right)
		{
			temp = datas[left];
			datas[left] = datas[right];
			datas[right] = temp;
		}
		else if (left == right)
		{
			break;
		}
	}

	temp = datas[right];
	datas[right] = datas[start];
	datas[start] = temp;

	QuickSort(datas, start, right - 1);
	QuickSort(datas, right + 1, end);
}