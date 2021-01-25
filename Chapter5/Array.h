#pragma once
#include<stdarg.h>
#include "predefine.h"
class Array
{
public:
	Array();
	Array(int dim, ...);
	~Array();

private:
	int *base;//����Ԫ�ػ�ַ,������(���л��߰���)����һ������L����ɵ����Խṹ���׵�ַ
	int dim;//ά��
	int *bounds;//����ά���ַ,ָ��һ��һά����B,�����������A��ά��Ԫ�ص���Ŀ
	int *constants;//����ӳ����������ַ,ָ��һ������C, �������"����A����ά���ϵ����ּ�һʱ, Ԫ�������ԽṹL�����ƶ��ľ���"

public:
	Status value(int *e, ...);
	Status assign(int e, ...);

protected:
	Status locate(va_list ap, int* off);
};

