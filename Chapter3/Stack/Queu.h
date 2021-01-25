#pragma once
#include "Stack.h"

/*
使用两个栈实现队列，组合两个栈，一个栈负责进
把序列插入栈1后，出队列时把栈1中的元素依次移到栈2中然后出栈
*/

template<class T>
class Queu
{
public:
	Queu();
	~Queu();

private:
	Stack<T> s1;//入队列的栈
	Stack<T> s2;//出队列的栈

public:
	Status initStack(int n = MAX);//构造队列
	Status push(T e);//进队列操作
	Status pop(T &e);//出队列操作
	Status getTop(T &e);//取队列顶元素
	void traverse();//遍历队列
	bool isEmpty();//判断队列是否为空
};

template<class T>
Queu<T>::Queu()
{
}

template<class T>
Queu<T>::~Queu()
{
}

template<class T>
Status Queu<T>::initStack(int n = MAX)//构造队列
{
	s1.initStack(n);
	s2.initStack(n);
	return OK;
}

template<class T>
Status Queu<T>::push(T e)//进栈操作
{
	s1.push(e);
	return	OK;
}

template<class T>
Status Queu<T>::pop(T &e)//出栈操作
{
	//首先判断s1和s2是否皆为空栈
	if (s1.isEmpty()&&s2.isEmpty())
	{
		cout << "目前队列内没有元素！" << endl;
		exit(OVERFLOW);
	}
	else
	{
		//如果s2中有元素，可以直接pop出s2的栈顶元素
		if (!s2.isEmpty())
		{
			s2.pop(e);
			return OK;
		}
		else//s2中没有元素，需要把s1中的元素全部压入s2中,因为要从s1的栈底输出元素
		{
			T tmp;
			while (!s1.isEmpty())
			{
				s1.pop(tmp);
				s2.push(tmp);
			}
			s2.pop(e);
			return OK;
		}
	}
}

template<class T>
Status Queu<T>::getTop(T &e)//取队列顶元素
{
	if (s1.isEmpty() && s2.isEmpty())
	{
		cout << "目前队列内没有元素！" << endl;
		exit(OVERFLOW);
	}
	else
	{
		//如果s2中有元素，可以直接gets2的栈顶元素
		if (!s2.isEmpty())
		{
			s2.getTop(e);
			return OK;
		}
		else//s2中没有元素，需要把s1中的元素全部压入s2中
		{
			T tmp;
			while (!s1.isEmpty())
			{
				s1.pop(tmp);
				s2.push(tmp);
			}
			s2.getTop(e);
			return OK;
		}
	}
}

template<class T>
void Queu<T>::traverse()//遍历队列
{
	if (s1.isEmpty())
	{
		cout << "目前队列内没有元素！" << endl;
		exit(OVERFLOW);
	}
	else
	{
		s1.traverse();//由于stack定义的遍历方法是从栈底遍历，所以直接遍历s1
	}
}

template<class T>
bool Queu<T>::isEmpty()//判断栈是否为空
{
	//s1和s2同时为空才为栈皆为空
	if (s1.isEmpty()&&s2.isEmpty())
	{
		return true;
	}
	return false;
}