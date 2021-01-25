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
	int rear;//队尾指针
	int front;//队头指针
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
		cout << "初始化失败" << endl;
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
		cout << "队已满，不能入队！" << endl;
		return ERROR;
	}
	//在队尾插入
	data[rear] = e;
	rear = (rear + 1) % size;
	return OK;
}

template<class T>
Status Queue<T>::pop(T& e)
{
	if (isEmpty())
	{
		cout << "当前队列为空！" << endl;
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
		cout << "当前队列为空！" << endl;
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