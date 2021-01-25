#pragma once
#include "predefine.h"
//定义三元组
struct Triple
{
	int row, col;//行号列号
	int data;//本身的数据
};
class TSMatrix
{
public:
	TSMatrix();
	~TSMatrix();
	TSMatrix(int m, int n, int t, Triple arr[]);

public:
	Status transpose(TSMatrix &t);//转置矩阵
	void print();
private:
	Triple data[MAX + 1];
	int mu, nu, tu;//行数列数和非零元的个数
};

