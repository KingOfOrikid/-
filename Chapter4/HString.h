#pragma once
#include "predefine.h"
class HString
{
public:
	HString();
	HString(const char* p);
	~HString();

private:
	char *ch;
	int length;

public:
	Status assign(const char* p);//����ֵ
	Status concat(HString& s1, HString& s2);//s1��s2�����������µĴ�
	Status print();
	int size();
	Status del(int pos,int len);
	Status insert(int pos, HString& t);//��pos�����ַ���t
	Status index(HString& t, int pos);
	Status substring(HString& sub, int pos, int len);//���Ӵ�����sub����
	int index_kmp(HString& t);
	bool empty();
	Status replace(HString& oldStr, HString& newStr);
	void ComMAXSubstring(HString& s, HString& t);//����������ͬ������Ӵ�
	

public:
	void getNext(HString& t, int next[]);//��next����

};

