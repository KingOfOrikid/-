#pragma once
#include "Stack.h"

/*
ʹ������ջʵ�ֶ��У��������ջ��һ��ջ�����
�����в���ջ1�󣬳�����ʱ��ջ1�е�Ԫ�������Ƶ�ջ2��Ȼ���ջ
*/

template<class T>
class Queu
{
public:
	Queu();
	~Queu();

private:
	Stack<T> s1;//����е�ջ
	Stack<T> s2;//�����е�ջ

public:
	Status initStack(int n = MAX);//�������
	Status push(T e);//�����в���
	Status pop(T &e);//�����в���
	Status getTop(T &e);//ȡ���ж�Ԫ��
	void traverse();//��������
	bool isEmpty();//�ж϶����Ƿ�Ϊ��
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
Status Queu<T>::initStack(int n = MAX)//�������
{
	s1.initStack(n);
	s2.initStack(n);
	return OK;
}

template<class T>
Status Queu<T>::push(T e)//��ջ����
{
	s1.push(e);
	return	OK;
}

template<class T>
Status Queu<T>::pop(T &e)//��ջ����
{
	//�����ж�s1��s2�Ƿ��Ϊ��ջ
	if (s1.isEmpty()&&s2.isEmpty())
	{
		cout << "Ŀǰ������û��Ԫ�أ�" << endl;
		exit(OVERFLOW);
	}
	else
	{
		//���s2����Ԫ�أ�����ֱ��pop��s2��ջ��Ԫ��
		if (!s2.isEmpty())
		{
			s2.pop(e);
			return OK;
		}
		else//s2��û��Ԫ�أ���Ҫ��s1�е�Ԫ��ȫ��ѹ��s2��,��ΪҪ��s1��ջ�����Ԫ��
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
Status Queu<T>::getTop(T &e)//ȡ���ж�Ԫ��
{
	if (s1.isEmpty() && s2.isEmpty())
	{
		cout << "Ŀǰ������û��Ԫ�أ�" << endl;
		exit(OVERFLOW);
	}
	else
	{
		//���s2����Ԫ�أ�����ֱ��gets2��ջ��Ԫ��
		if (!s2.isEmpty())
		{
			s2.getTop(e);
			return OK;
		}
		else//s2��û��Ԫ�أ���Ҫ��s1�е�Ԫ��ȫ��ѹ��s2��
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
void Queu<T>::traverse()//��������
{
	if (s1.isEmpty())
	{
		cout << "Ŀǰ������û��Ԫ�أ�" << endl;
		exit(OVERFLOW);
	}
	else
	{
		s1.traverse();//����stack����ı��������Ǵ�ջ�ױ���������ֱ�ӱ���s1
	}
}

template<class T>
bool Queu<T>::isEmpty()//�ж�ջ�Ƿ�Ϊ��
{
	//s1��s2ͬʱΪ�ղ�Ϊջ��Ϊ��
	if (s1.isEmpty()&&s2.isEmpty())
	{
		return true;
	}
	return false;
}