#pragma once
#include "predefine.h"
//定义模板类
template<class T>
class Stack
{
public:
	Stack();
	~Stack();

private:
	T* data;//栈底（起始地址）
	T* top;//栈顶指针
	int stackSize;//当前容量

public:
	Status initStack(int n = MAX);//构造栈
	bool isFull();//判断栈是否为满
	bool isEmpty();//判断栈是否为空
	Status push(T e);//进栈操作
	Status pop(T &e);//出栈操作
	Status getTop(T &e);//去栈顶元素
	void traverse();//遍历栈
	void clear();//清空栈
};

template<class T>
Stack<T>::Stack()
{
}

template<class T>
Stack<T>::~Stack()
{
}


//初始化一个空栈，分配存储空间
template<class T>
Status Stack<T>::initStack(int n)
{
	//分配存储空间
	data = (T*)malloc(sizeof(T)*n);
	if (!data)
	{
		cout << "初始化栈失败..." << endl;
		return ERROR;
	}
	//栈顶指针指向栈底
	top = data;
	//容量赋值
	stackSize = n;
	return OK;
}

//判断是否为满
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
	//判断目前栈是否为满
	if (isFull())
	{
		T* newbase = (T*)realloc(data, (stackSize + INCREMENT) * sizeof(T));
		if (!newbase)
		{
			cout << "插入失败..." << endl;
			exit(OVERFLOW);
		}
		data = newbase;
		top = data + stackSize;//data新的地址加上原先的长度
	}
	//插入到top
	*top = e;
	//top往后移
	top++;
	//当前容量发生改变
	stackSize = stackSize + INCREMENT;
	return OK;
}

template<class T>
Status Stack<T>::pop(T &e)
{
	//判断是否为空
	if (isEmpty())
	{
		//cout << "当前栈内为空！" << endl;
		return(ERROR);
	}
	//栈顶元素往前移
	top--;
	//返回当前元素值
	e = *top;
	return OK;
}

template<class T>
Status Stack<T>::getTop(T &e)
{
	if (isEmpty())
	{
		cout << "当前栈内为空！" << endl;
		return(ERROR);
	}
	//注意不要移动top指针
	e = *(top-1);
	return OK;
}

//遍历操作
template<class T>
void Stack<T>::traverse()
{
	T* p = data;
	if (isEmpty())
	{
		cout << "当前栈内为空！" << endl;
		return;
	}
	cout << "栈内的元素为" << endl;
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

