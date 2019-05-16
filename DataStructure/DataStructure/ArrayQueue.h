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
			cout << "ť�� ������ϴ�" << endl;
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
			cout << "ť�� ������ϴ�" << endl;
		}
		else
		{
			// ���� �������ʰ� �״�� �� ��� 0~front���� ���
			if (rear == -1)
			{
				for (int i = 0; i <= front; i++)
				{
					cout << queueArray[i] << " ";
				}
			}
			// ���� �߰��� ������ rear�� -1�� �ƴѰ��
			else
			{
				// front�� �տ� �ִ� ��� rear ~ front���� ���
				if (front > rear)
				{
					for (int i = rear + 1; i <= front; i++)
					{
						cout << queueArray[i] << " ";
					}
				}
				// front�� maxġ�� �Ѿ� 0���� ���ƿͼ� rear���� ������ �������� rear~size���� ����ϰ� 0~front���� ���
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

		// ó������ ������ ���� �������ʰ� �״�� �� ���
		if (rear == -1)
		{
			for (int i = 0; i < size - 10; i++)
			{
				tempQueueArray[i] = queueArray[i];
			}
		}
		// ���� �߰��� ������ front�� �ٽ� 0���� ���ƿ� �߰������� �����Ͱ� ���ΰ��
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

		// �� �Ű����Ƿ� rear, front ����
		rear = -1;
		front = size - 11;

		delete[] queueArray;
		queueArray = tempQueueArray;
	}
};