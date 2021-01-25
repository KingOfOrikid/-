#pragma once
#include "predefine.h"
typedef int ElemType;
class SqList
{
public:
	SqList();
	SqList(int a[], int n);//���ع��캯����ʹ�������˳�������Ϊ������������������������飬����Ϊ����ĳ���
	~SqList();


	Status insert(ElemType e, int pos);//��posǰ����e
	Status insert(ElemType e);//˳�����e
	Status del(ElemType& e, int pos);//ɾ����pos��Ԫ�أ���e����
	Status find(ElemType e, int start=0);//��˳������Ƿ���ĳԪ�أ�����еĻ�����Ԫ�ص�λ�ã��������ô��ĸ�λ�ÿ�ʼ���ң�Ĭ�ϴ�ͷ��ʼ
	Status get(ElemType& e, int pos);//ȡ��pos��Ԫ��
	void print();//��ӡ��������Ԫ��
private:
	ElemType* data;//����
	int length;//���Ա�ĳ���
	int listSize;//��ǰ������
};

