#pragma once
#include "predefine.h"


//�������
class Node
{
public:
	float coef;//ϵ����
	int expn;//ָ����
	Node *next;//ָ����
};

class Polynomial
{
public:
	Polynomial();
	~Polynomial();

public:
	Status create(float coe[], int exp[], int len_1, int len_2);
	Status mulp(Polynomial p1, Polynomial p2);
	Status plus(Polynomial &p1, Polynomial &p2);
	void print();
private:
	Node* head;//ͷ���
	int size;//����ʽ����
};

