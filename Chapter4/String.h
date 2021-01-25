#pragma once
#include "predefine.h"
const int MAX_STRLEN = 256;
class String
{
public:
	String();
	String(const char* ch);
	~String();

public:
	Status concat(String& t);//两个串进行连接
	Status size();//求串长
	void print();//输出字符串
	Status clear();//清空串
	Status strcopy(String& t);//t拷贝给当前对象
	Status empty();//判空操作
	int strcmpy(String& t);//两个串进行比较
	Status substring(String& t, int pos,int len);//求子串操作，从pos起取长度为len的子串
	int index(String& t, int pos);//简单模式匹配
	Status replace(String oldStr, String newStr);//替换
	Status insert(String& t, int pos);//在指定的位置插入t
	Status del(int pos, int len);//在pos删除长度len的子串
private:
	char str[MAX_STRLEN+1];//定长顺序存储，字符数组要\0表示字符串的结尾
	int length;
};

