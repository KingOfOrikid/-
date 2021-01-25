#include "Array.h"



Array::Array()
{
}


Array::Array(int dim, ...)
{
	int elemtotal = 1;//Ԫ�ص�����
	va_list vap;//�Ѻ���Ĳ����ռ���һ��
	//�ж�ά���Ƿ�Ϸ�
	if (dim<1 || dim>MAX_ARRAY_DIM)
		exit(ERROR);
	this->dim = dim;
	bounds = (int*)malloc(sizeof(int)*dim);
	if (!bounds)
		exit(OVERFLOW);

	va_start(vap, dim);
	for (int i = 0; i < dim; i++)
	{
		bounds[i] = va_arg(vap, int);//vapָ����Լ�����Ų
		if (bounds[i] < 0)
		{
			exit(UNDERFLOW);
		}
		elemtotal *= bounds[i];
	}

	va_end(vap);
	//���ٴ洢�ռ�
	base = (int*)malloc(sizeof(int)*elemtotal);
	if (!base)
		exit(OVERFLOW);

	constants = (int*)malloc(dim * sizeof(int));
	if (!constants)
		exit(OVERFLOW);
	constants[dim - 1] = 1;
	for (int i = dim - 2; i >= 0; i--)
	{
		constants[i] = bounds[i + 1] * constants[i + 1];
	}
}

Array::~Array()
{
	if (base)
	{
		free(base);
		base = NULL;
	}
	if (bounds)
	{
		free(bounds);
		bounds = NULL;
	}
	if (constants)
	{
		free(constants);
		constants = NULL;
	}
}



Status Array::locate(va_list ap, int* off)
{
	int i, ind;
	*off = 0;
	for (i = 0; i < dim; i++)
	{
		ind = va_arg(ap,int);//ȡһ���±�
		if (ind < 0 || ind >= bounds[i])
			return OVERFLOW;

		*off += constants[i] * ind;
	}

	return OK;
}


Status Array::value(int *e, ...)
{
	va_list ap;
	Status result;

	int off;

	va_start(ap, e);
	result = locate(ap, &off);
	if (result == OVERFLOW)
	{
		return result;
	}
	va_end(ap);

	*e = *(base + off);//��ֵ
	return OK;
}

Status Array::assign(int e, ...)
{
	va_list ap;
	Status result;
	int off;
	va_start(ap, e);
	result = locate(ap, &off);
	if (result == OVERFLOW)
	{
		return result;
	}
	va_end(ap);

	*(base + off) = e;
	return OK;
}