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

//���ع��캯����ʹ�������˳�������Ϊ������������������������飬����Ϊ����ĳ���
SqList::SqList(int a[], int n)
{
	//Ϊ���鿪�ٿռ�
	data=(ElemType*)malloc(sizeof(ElemType)*n);
	//�������ʧ�ܣ����������
	if (!data)
	{
		exit(OVERFLOW);
	}
	length = n;
	listSize = n;
	//���������ð�����򣬲���ֵ
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

//��λ�ò���Ԫ�أ�������룩
Status SqList::insert(ElemType e, int pos)
{
	//�ж�λ���Ƿ�Ϸ�
	if (pos<1 || pos>length + 1)
	{
		cout << "λ�ò��Ϸ�!" << endl;
		return(ERROR);
	}
	//�жϴ洢�ռ��Ƿ�����
	if (length >= listSize)
	{
		//�������ռ�����������������ռ�
		ElemType* newbase = (ElemType*)realloc(data, (listSize + INCREMENT) * sizeof(ElemType));
		if (!newbase)
		{
			exit(OVERFLOW);
		}
		data = newbase;
	}
	//����
	/*ʹ��ָ����в���
	ElemType* q = &data[pos - 1];
	for (ElemType* p = &data[length - 1]; p >= q; p--)
	{
		*(p + 1) = *p;
	}
	//����Ԫ��
	*q=e;
	length++;
	*/
	length++;
	for (int i = length - 1; i > pos - 1; i--)
	{
		data[i] = data[i - 1];
	}
	//����Ԫ��
	data[pos - 1] = e;
	return OK;
}

//������ĳԪ�ز���˳���˳����룩
Status SqList::insert(ElemType e)
{
	//�жϴ���ռ��Ƿ�����
	if (length >= listSize)
	{
		ElemType* newbase = (ElemType*)realloc(data, (listSize + INCREMENT) * sizeof(ElemType));
		if (!newbase)
		{
			exit(OVERFLOW);
		}
		data = newbase;
	}
	//�������бȽϣ��������Ԫ��С��Ŀǰ��������Ԫ�أ�����벢������Ԫ�غ���
	for (int i = 0; i < length; i++)
	{
		if (e >= data[i])
		{
			//�жϲ���Ԫ���Ƿ���Ҫ������˳���ĩβ
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

//ɾ��˳�����ĳλ�õ�Ԫ�أ�������ɾ����Ԫ�ص�ֵ
Status SqList::del(ElemType& e, int pos)
{
	//�ж�λ���Ƿ�Ϸ�
	if (pos<1 || pos>length)
	{
		cout << "λ�ò��Ϸ���" << endl;
		exit(ERROR);
	}
	//����ɾ����Ԫ��
	e = data[pos - 1];
	//�ƶ�Ԫ��
	for (int i = pos; i < length; i++)
	{
		data[i - 1] = data[i];
	}
	//����һ
	length--;
	return OK;
}

//��˳������Ƿ���ĳԪ�أ�����еĻ�����Ԫ�ص�λ�ã��������ô��ĸ�λ�ÿ�ʼ���ң�Ĭ�ϴ�ͷ��ʼ
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
				cout << "����ʧ�ܣ�δ�ҵ���Ԫ�أ�" << endl;
				return ERROR;
			}
			continue;
		}
	}
}

//����λ�÷��������д�λ�õ�Ԫ��
Status SqList::get(ElemType& e, int pos)
{
	//�ж�λ���Ƿ�Ϸ�
	if (pos<1 || pos>length + 1)
	{
		cout << "λ�ò��Ϸ�!" << endl;
		return ERROR;
	}
	e = data[pos - 1];
	return OK;
}

//���Ŀǰ˳�����Ϣ
void SqList::print()
{
	if (length>0)
	{
		cout << "��ǰ���Ա�ĳ���Ϊ" << length << ",Ԫ��Ϊ��";
		cout << data[0];
		for (int i = 1; i < length; i++)
		{
			cout << "," << data[i];
		}
		cout << endl;
	}
	else
	{
		cout << "��ǰ���Ա�Ϊ��" << endl;
	}
}