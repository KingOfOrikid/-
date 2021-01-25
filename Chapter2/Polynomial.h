#pragma once
#include "predefine.h"


//结点类型
class Node
{
public:
	float coef;//系数域
	int expn;//指数域
	Node *next;//指针域
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
	Node* head;//头结点
	int size;//多项式长度
};

