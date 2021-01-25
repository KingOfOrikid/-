#pragma once
#include "predefine.h"
typedef int ElemType;
//结点类型
class Node
{
public:
	ElemType data;//数据域
	Node *next;//指针域
};
class LinkList
{
public:
	LinkList();
	LinkList(int a[], int n);
	~LinkList();

public:
	Status create(int size);//用户给定长度和内容，创建增序链表
	Status get(ElemType &e,int pos);//根据位置返回链表中此位置的元素
	Status insert(ElemType e, int pos);//按位置插入元素（无序插入）
	Status insert(ElemType e);//按增序将某元素插入链表（顺序插入）
	Status del(ElemType &e, int pos);//删除链表中某位置的元素，并储存删除的元素的值
	Status find(ElemType e);//找链表中是否有某元素，如果有的话返回元素的位置
	int length(); //返回此时表长
	bool isEmpty();//检查此时链表是否为空
	void print();//输出目前链表信息

private:
	Node* head;//头结点
	int size;//链表长度
};

