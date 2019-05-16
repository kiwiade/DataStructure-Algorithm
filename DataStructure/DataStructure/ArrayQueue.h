#pragma once
#include <iostream>
using namespace std;

template<typename T>
class ArrayQueue
{
private:
	int front = -1;
	int rear = -1;
	int size = 10;
	T* queueArray = new T[size];

public:
	ArrayQueue() {	}
	~ArrayQueue() {	}

	bool Enqueue(T value)
	{

		if (IsFull())
			SizeUp();

		if (IsEnd())
			front = -1;

		front++;
		queueArray[front] = value;
		return true;
	}

	T Dequeue()
	{
		if (IsEmpty())
		{
			cout << "큐가 비었습니다" << endl;
			return 0;
		}
		else
		{
			rear++;
			T data = queueArray[rear];
			return data;
		}
	}

	void Print()
	{
		if (IsEmpty() && !IsFull())
		{
			cout << "큐가 비었습니다" << endl;
		}
		else
		{
			// 값이 빠지지않고 그대로 들어간 경우 0~front까지 출력
			if (rear == -1)
			{
				for (int i = 0; i <= front; i++)
				{
					cout << queueArray[i] << " ";
				}
			}
			// 값이 중간에 빠져서 rear가 -1이 아닌경우
			else
			{
				// front가 앞에 있는 경우 rear ~ front까지 출력
				if (front > rear)
				{
					for (int i = rear + 1; i <= front; i++)
					{
						cout << queueArray[i] << " ";
					}
				}
				// front가 max치를 넘어 0으로 돌아와서 rear보다 앞으로 갔을때는 rear~size까지 출력하고 0~front까지 출력
				else
				{
					for (int i = rear + 1; i < size; i++)
					{
						cout << queueArray[i] << " ";
					}
					for (int i = 0; i <= front; i++)
					{
						cout << queueArray[i] << " ";
					}
				}
			}
			cout << endl;
		}
	}

	bool IsEmpty()
	{
		return front == rear;
	}

	bool IsFull()
	{
		if (front == -1 && rear == -1)
			return false;
		else
			return (front + 1) % size == rear + 1;
	}

	bool IsEnd()
	{
		return (front + 1) == size;
	}

	void SizeUp()
	{
		size += 10;
		T* tempQueueArray = new T[size];

		// 처음부터 끝까지 값이 빠지지않고 그대로 들어간 경우
		if (rear == -1)
		{
			for (int i = 0; i < size - 10; i++)
			{
				tempQueueArray[i] = queueArray[i];
			}
		}
		// 값이 중간에 빠지고 front가 다시 0으로 돌아와 추가적으로 데이터가 쌓인경우
		else
		{
			int count = 0;
			for (int i = rear + 1; i < size - 10; i++)
			{
				tempQueueArray[count] = queueArray[i];
				count++;
			}
			for (int i = 0; i <= front; i++)
			{
				tempQueueArray[count] = queueArray[i];
				count++;
			}
		}

		// 다 옮겼으므로 rear, front 수정
		rear = -1;
		front = size - 11;

		delete[] queueArray;
		queueArray = tempQueueArray;
	}
};