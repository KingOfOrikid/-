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
	int *base;//数组元素基址,将数组(按行或者按列)拉成一个向量L所组成的线性结构的首地址
	int dim;//维度
	int *bounds;//数组维界地址,指向一个一维数组B,它存放了数组A各维度元素的数目
	int *constants;//数组映像函数常量基址,指向一个数组C, 它存放了"数组A各个维度上的数字加一时, 元素在线性结构L上所移动的距离"

public:
	Status value(int *e, ...);
	Status assign(int e, ...);

protected:
	Status locate(va_list ap, int* off);
};

