#pragma once
#include "predefine.h"
//����ģ����
template<class T>
class Stack
{
public:
	Stack();
	~Stack();

private:
	T* data;//ջ�ף���ʼ��ַ��
	T* top;//ջ��ָ��
	int stackSize;//��ǰ����

public:
	Status initStack(int n = MAX);//����ջ
	bool isFull();//�ж�ջ�Ƿ�Ϊ��
	bool isEmpty();//�ж�ջ�Ƿ�Ϊ��
	Status push(T e);//��ջ����
	Status pop(T &e);//��ջ����
	Status getTop(T &e);//ȥջ��Ԫ��
	void traverse();//����ջ
	void clear();//���ջ
};

template<class T>
Stack<T>::Stack()
{
}

template<class T>
Stack<T>::~Stack()
{
}


//��ʼ��һ����ջ������洢�ռ�
template<class T>
Status Stack<T>::initStack(int n)
{
	//����洢�ռ�
	data = (T*)malloc(sizeof(T)*n);
	if (!data)
	{
		cout << "��ʼ��ջʧ��..." << endl;
		return ERROR;
	}
	//ջ��ָ��ָ��ջ��
	top = data;
	//������ֵ
	stackSize = n;
	return OK;
}

//�ж��Ƿ�Ϊ��
template<class T>
bool Stack<T>::isFull()
{
	if (top - data >= stackSize - 1)
	{
		return true;
	}
	return false;
}

template<class T>
bool Stack<T>::isEmpty()
{
	if (top == data)
	{
		return true;
	}
	return false;
}

template<class T>
Status Stack<T>::push(T e)
{
	//�ж�Ŀǰջ�Ƿ�Ϊ��
	if (isFull())
	{
		T* newbase = (T*)realloc(data, (stackSize + INCREMENT) * sizeof(T));
		if (!newbase)
		{
			cout << "����ʧ��..." << endl;
			exit(OVERFLOW);
		}
		data = newbase;
		top = data + stackSize;//data�µĵ�ַ����ԭ�ȵĳ���
	}
	//���뵽top
	*top = e;
	//top������
	top++;
	//��ǰ���������ı�
	stackSize = stackSize + INCREMENT;
	return OK;
}

template<class T>
Status Stack<T>::pop(T &e)
{
	//�ж��Ƿ�Ϊ��
	if (isEmpty())
	{
		//cout << "��ǰջ��Ϊ�գ�" << endl;
		return(ERROR);
	}
	//ջ��Ԫ����ǰ��
	top--;
	//���ص�ǰԪ��ֵ
	e = *top;
	return OK;
}

template<class T>
Status Stack<T>::getTop(T &e)
{
	if (isEmpty())
	{
		cout << "��ǰջ��Ϊ�գ�" << endl;
		return(ERROR);
	}
	//ע�ⲻҪ�ƶ�topָ��
	e = *(top-1);
	return OK;
}

//��������
template<class T>
void Stack<T>::traverse()
{
	T* p = data;
	if (isEmpty())
	{
		cout << "��ǰջ��Ϊ�գ�" << endl;
		return;
	}
	cout << "ջ�ڵ�Ԫ��Ϊ" << endl;
	while (p < top)
	{
		cout << *p << " ";
		p++;
	}
	cout << endl;
}

template<class T>
void Stack<T>::clear()
{
	while (top != data)
	{
		top--;
	}
	return;
}

