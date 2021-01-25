#pragma once
#include "predefine.h"
typedef int ElemType;
//�������
class Node
{
public:
	ElemType data;//������
	Node *next;//ָ����
};
class LinkList
{
public:
	LinkList();
	LinkList(int a[], int n);
	~LinkList();

public:
	Status create(int size);//�û��������Ⱥ����ݣ�������������
	Status get(ElemType &e,int pos);//����λ�÷��������д�λ�õ�Ԫ��
	Status insert(ElemType e, int pos);//��λ�ò���Ԫ�أ�������룩
	Status insert(ElemType e);//������ĳԪ�ز�������˳����룩
	Status del(ElemType &e, int pos);//ɾ��������ĳλ�õ�Ԫ�أ�������ɾ����Ԫ�ص�ֵ
	Status find(ElemType e);//���������Ƿ���ĳԪ�أ�����еĻ�����Ԫ�ص�λ��
	int length(); //���ش�ʱ��
	bool isEmpty();//����ʱ�����Ƿ�Ϊ��
	void print();//���Ŀǰ������Ϣ

private:
	Node* head;//ͷ���
	int size;//������
};

