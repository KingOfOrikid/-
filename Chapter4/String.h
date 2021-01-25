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
	Status concat(String& t);//��������������
	Status size();//�󴮳�
	void print();//����ַ���
	Status clear();//��մ�
	Status strcopy(String& t);//t��������ǰ����
	Status empty();//�пղ���
	int strcmpy(String& t);//���������бȽ�
	Status substring(String& t, int pos,int len);//���Ӵ���������pos��ȡ����Ϊlen���Ӵ�
	int index(String& t, int pos);//��ģʽƥ��
	Status replace(String oldStr, String newStr);//�滻
	Status insert(String& t, int pos);//��ָ����λ�ò���t
	Status del(int pos, int len);//��posɾ������len���Ӵ�
private:
	char str[MAX_STRLEN+1];//����˳��洢���ַ�����Ҫ\0��ʾ�ַ����Ľ�β
	int length;
};

