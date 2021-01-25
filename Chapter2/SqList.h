#pragma once
#include "predefine.h"
typedef int ElemType;
class SqList
{
public:
	SqList();
	SqList(int a[], int n);//重载构造函数，使构造出的顺序表内容为输入数组进行增序排序后的数组，长度为数组的长度
	~SqList();


	Status insert(ElemType e, int pos);//在pos前插入e
	Status insert(ElemType e);//顺序插入e
	Status del(ElemType& e, int pos);//删除第pos的元素，用e返回
	Status find(ElemType e, int start=0);//找顺序表中是否有某元素，如果有的话返回元素的位置，可以设置从哪个位置开始查找，默认从头开始
	Status get(ElemType& e, int pos);//取第pos个元素
	void print();//打印输出里面的元素
private:
	ElemType* data;//数组
	int length;//线性表的长度
	int listSize;//当前的容量
};

