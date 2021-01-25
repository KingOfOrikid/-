#pragma once
#include "predefine.h"
//����ṹ�����ʹ�Ž��
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
		cout << "����ʧ��..." << endl;
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
		cout << "��ǰջΪ��,ɾ��ʧ�ܣ�" << endl;
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
		cout << "��ǰջΪ�գ�û�����ݣ�" << endl;
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
		cout << "��ǰջΪ�գ�û�����ݣ�" << endl;
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