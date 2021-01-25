#pragma once
#include "predefine.h"
//定义结构体类型存放结点
class StackNode
{
public:
	int data;
	StackNode *next;
};

template<class T>
class StackList
{
public:
	StackList();
	~StackList();

private:
	int length;
	StackNode *top;

public:
	Status initStack();
	bool isEmpty();
	Status push(T e);
	Status pop(T &e);
	Status getTop(T &e);
	void traverse();
	Status getLength();
};

template<class T>
StackList<T>::StackList()
{
}

template<class T>
StackList<T>::~StackList()
{
	StackNode *p;
	while (top)
	{
		p = top;
		top = top->next;
		delete p;
	}
}

template<class T>
Status StackList<T>::initStack()
{
	top = new StackNode;
	if (!top)
	{
		cout << "构造失败..." << endl;
		return ERROR;
	}
	top->next = NULL;
	length = 0;
	return OK;
}

template<class T>
bool StackList<T>::isEmpty()
{
	if (top->next==NULL)
	{
		return true;
	}
	return false;
}

template<class T>
Status StackList<T>::push(T e)
{
	StackNode *s = new StackNode;
	s->data = e;
	s->next = top->next;
	top->next = s;
	length++;
	return OK;
}

template<class T>
Status StackList<T>::pop(T &e)
{
	if (isEmpty())
	{
		cout << "当前栈为空,删除失败！" << endl;
		return ERROR;
	}
	StackNode *s = top->next;
	e = s->data;
	top->next = s->next;
	delete s;
	length--;
	return OK;
}

template<class T>
Status StackList<T>::getTop(T &e)
{
	if (isEmpty())
	{
		cout << "当前栈为空，没有数据！" << endl;
		return ERROR;
	}
	e = top->next->data;
	return OK;
}

template<class T>
void StackList<T>::traverse()
{
	if (isEmpty())
	{
		cout << "当前栈为空，没有数据！" << endl;
		return;
	}
	StackNode *p = top->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return;
}

template<class T>
Status StackList<T>::getLength()
{
	return length;
}