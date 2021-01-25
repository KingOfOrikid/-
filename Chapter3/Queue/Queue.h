#pragma once
#include "predefine.h"

template<class T>
class Queue
{
public:
	Queue();
	~Queue();

public:
	Status initQueue(int n = MAX);
	Status getLen();
	bool isEmpty();
	bool isFull();
	Status push(T e);
	Status pop(T& e);
	void traverse();

private:
	T* data;
	int rear;//��βָ��
	int front;//��ͷָ��
	int size;
};

template<class T>
Queue<T>::Queue()
{

}
template<class T>
Queue<T>::~Queue()
{
	free(data);
}




template<class T>
Status Queue<T>::initQueue(int n = MAX)
{
	data = (T*)malloc(n * sizeof(T));
	if (!data)
	{
		cout << "��ʼ��ʧ��" << endl;
		return ERROR;
	}
	front = 0;
	rear = 0;
	size = n;
	return OK;
}

template<class T>
Status Queue<T>::getLen()
{
	return (rear-front+size)%size;
}

template<class T>
bool Queue<T>::isEmpty()
{
	if (rear == front)
	{
		return true;
	}
	return false;
}

template<class T>
bool Queue<T>::isFull()
{
	if ((rear + 1) % size == front)
	{
		return true;
	}
	return false;
}

template<class T>
Status Queue<T>::push(T e)
{
	if (isFull())
	{
		cout << "��������������ӣ�" << endl;
		return ERROR;
	}
	//�ڶ�β����
	data[rear] = e;
	rear = (rear + 1) % size;
	return OK;
}

template<class T>
Status Queue<T>::pop(T& e)
{
	if (isEmpty())
	{
		cout << "��ǰ����Ϊ�գ�" << endl;
		return ERROR;
	}
	e = data[front];
	front = (front + 1) % size;
	return OK;
}

template<class T>
void Queue<T>::traverse()
{
	if (isEmpty())
	{
		cout << "��ǰ����Ϊ�գ�" << endl;
		return;
	}
	else
	{
		int p = front;
		while(p!=rear)
		{
			cout << data[p] << " ";
			p = (p + 1) % size;
		}
	}
	return;
}