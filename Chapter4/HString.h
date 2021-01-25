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
	Status assign(const char* p);//串赋值
	Status concat(HString& s1, HString& s2);//s1和s2连接起来给新的串
	Status print();
	int size();
	Status del(int pos,int len);
	Status insert(int pos, HString& t);//在pos插入字符串t
	Status index(HString& t, int pos);
	Status substring(HString& sub, int pos, int len);//求子串，用sub返回
	int index_kmp(HString& t);
	bool empty();
	Status replace(HString& oldStr, HString& newStr);
	void ComMAXSubstring(HString& s, HString& t);//求两个串共同的最大子串
	

public:
	void getNext(HString& t, int next[]);//求next数组

};

