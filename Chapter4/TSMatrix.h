#pragma once
#include "predefine.h"
//������Ԫ��
struct Triple
{
	int row, col;//�к��к�
	int data;//���������
};
class TSMatrix
{
public:
	TSMatrix();
	~TSMatrix();
	TSMatrix(int m, int n, int t, Triple arr[]);

public:
	Status transpose(TSMatrix &t);//ת�þ���
	void print();
private:
	Triple data[MAX + 1];
	int mu, nu, tu;//���������ͷ���Ԫ�ĸ���
};

