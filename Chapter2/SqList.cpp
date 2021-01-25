#include "SqList.h"



SqList::SqList()
{
	data = (ElemType*)malloc(sizeof(ElemType)*MAX);
	if (!data)
	{
		exit(OVERFLOW);
	}
	length = 0;
	listSize = MAX;
}

//重载构造函数，使构造出的顺序表内容为输入数组进行增序排序后的数组，长度为数组的长度
SqList::SqList(int a[], int n)
{
	//为数组开辟空间
	data=(ElemType*)malloc(sizeof(ElemType)*n);
	//如果开辟失败，报溢出错误
	if (!data)
	{
		exit(OVERFLOW);
	}
	length = n;
	listSize = n;
	//对数组进行冒泡排序，并赋值
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		for (int j = i+1; j < n; j++)
		{
			if (a[j] <= a[i])
			{
				temp=a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		data[i] = a[i];
	}
}

SqList::~SqList()
{
	free(data);
}

//按位置插入元素（无序插入）
Status SqList::insert(ElemType e, int pos)
{
	//判断位置是否合法
	if (pos<1 || pos>length + 1)
	{
		cout << "位置不合法!" << endl;
		return(ERROR);
	}
	//判断存储空间是否已满
	if (length >= listSize)
	{
		//如果储存空间已满，按增量扩充空间
		ElemType* newbase = (ElemType*)realloc(data, (listSize + INCREMENT) * sizeof(ElemType));
		if (!newbase)
		{
			exit(OVERFLOW);
		}
		data = newbase;
	}
	//插入
	/*使用指针进行插入
	ElemType* q = &data[pos - 1];
	for (ElemType* p = &data[length - 1]; p >= q; p--)
	{
		*(p + 1) = *p;
	}
	//插入元素
	*q=e;
	length++;
	*/
	length++;
	for (int i = length - 1; i > pos - 1; i--)
	{
		data[i] = data[i - 1];
	}
	//插入元素
	data[pos - 1] = e;
	return OK;
}

//按增序将某元素插入顺序表（顺序插入）
Status SqList::insert(ElemType e)
{
	//判断储存空间是否已满
	if (length >= listSize)
	{
		ElemType* newbase = (ElemType*)realloc(data, (listSize + INCREMENT) * sizeof(ElemType));
		if (!newbase)
		{
			exit(OVERFLOW);
		}
		data = newbase;
	}
	//遍历进行比较，如果插入元素小于目前遍历到的元素，则插入并将其他元素后移
	for (int i = 0; i < length; i++)
	{
		if (e >= data[i])
		{
			//判断插入元素是否需要插入至顺序表末尾
			if (i == length - 1)
			{
				length++;
				data[length-1] = e;
				break;
			}
			continue;
		}
		else
		{
			length++;
			for (int j = length - 1; j > i; j--)
			{
				data[j] = data[j-1];
			}
			data[i] = e;
			break;
		}
	}
	return OK;
}

//删除顺序表中某位置的元素，并储存删除的元素的值
Status SqList::del(ElemType& e, int pos)
{
	//判断位置是否合法
	if (pos<1 || pos>length)
	{
		cout << "位置不合法！" << endl;
		exit(ERROR);
	}
	//保存删除的元素
	e = data[pos - 1];
	//移动元素
	for (int i = pos; i < length; i++)
	{
		data[i - 1] = data[i];
	}
	//表长减一
	length--;
	return OK;
}

//找顺序表中是否有某元素，如果有的话返回元素的位置，可以设置从哪个位置开始查找，默认从头开始
Status SqList::find(ElemType e,int start)
{
	for (int i = start; i < length; i++)
	{
		if (data[i] == e)
		{
			return i+1;
		}
		else
		{
			if (i == length - 1)
			{
				cout << "查找失败！未找到该元素！" << endl;
				return ERROR;
			}
			continue;
		}
	}
}

//根据位置返回链表中此位置的元素
Status SqList::get(ElemType& e, int pos)
{
	//判断位置是否合法
	if (pos<1 || pos>length + 1)
	{
		cout << "位置不合法!" << endl;
		return ERROR;
	}
	e = data[pos - 1];
	return OK;
}

//输出目前顺序表信息
void SqList::print()
{
	if (length>0)
	{
		cout << "当前线性表的长度为" << length << ",元素为：";
		cout << data[0];
		for (int i = 1; i < length; i++)
		{
			cout << "," << data[i];
		}
		cout << endl;
	}
	else
	{
		cout << "当前线性表为空" << endl;
	}
}