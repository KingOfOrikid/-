#include "LinkList.h"
Status isNum(string str);

LinkList::LinkList()
{
	head = new Node;
	head->next = nullptr;
	size = 0;
}

//���������鴴����������
LinkList::LinkList(int a[],int n)
{
	head = new Node;
	head->next = nullptr;
	size = 0;
	Node *pNew = nullptr;
	Node *pTemp = head;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		for (int j = i+1; j < n; j++)
		{
			if (a[i]>a[j])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
		//��a[i]С�ں����Ԫ��ʱ����a[i]����������������
		pNew = new Node;
		pNew->next = nullptr;
		pNew->data = a[i];
		pTemp->next = pNew;
		//��ָ��Ų����һλ
		pTemp = pNew;
		size++;
	}
}


LinkList::~LinkList()
{
	Node *ptr;
	while (head!=NULL)
	{																
		ptr = head;
		head = head->next;
		delete ptr;
	}
}

//�û��������Ⱥ����ݣ�������������
Status LinkList::create(int size)//˳�򴴽�
{
	//�����ַ��ж��û������Ƿ�Ϸ�
	string input;
	int temp = 0;
	//�ж�size�Ƿ���ϳ���
	if (size < 0)
	{
		cout << "Error create..." << endl;
		return ERROR;
	}
	Node *pNew = nullptr;
	Node *pTemp = head;
	for (int i = 0; i < size; i++)
	{
L1:		pNew = new Node;
		pNew->next = nullptr;
		cout << "�������" << i + 1 << "��Ԫ�أ�";
		cin >> input;
		//�ж��û������Ԫ���Ƿ������֣�������ǵĻ�Ҫ���û���������
		if (!isNum(input))
		{
			cout << "���������֣�" << endl;
			goto L1;
		}
		else
		{
			//���û���������ַ���תΪ����
			stringstream st;
			st << input;
			st >> pNew->data;
		}
		//�ж��û�������˳���Ƿ�Ϊ���򣬲�Ҫ���û�����������
		while (pTemp->data > pNew->data)
		{
L2:			input = '0';
			cout << "���벻�Ϸ����������������" << i + 1 << "��Ԫ�أ�";
			cin >> input;
			if (!isNum(input))
			{
				cout << "���������֣�" << endl;
				goto L2;
			}
			else
			{
				//���ַ���ת��Ϊ����
				stringstream st;
				st << input;
				st >> pNew->data;
			}
		}
		pTemp->next = pNew;
		//������һ�β����λ��
		pTemp = pNew;
	}
	//����size
	this->size = size;
	cout << "�������" << endl;
	return OK;
}

//����λ�÷��������д�λ�õ�Ԫ��
Status LinkList::get(ElemType &e, int pos)
{
	//�ж��û���Ҫ���ҵ�λ���Ƿ�Ϸ�
	if (pos<1||pos>size)
	{
		cout << "����λ�ò��Ϸ���" << endl;
		return ERROR;
	}
	Node *ptr = head;
	//���������ҵ���posλ��
	for (int i = 0; i <= pos-1; i++)
	{
		//��û���ҵ���Ӧ��λ�ã�ָ��Ų����һλ
		ptr = ptr->next;
	}
	e = ptr->data;
	return OK;
}

//��λ�ò���Ԫ��
Status LinkList::insert(ElemType e, int pos)
{
	//�ж��û�����λ���Ƿ�Ϸ�
	if (pos < 1 || pos>size + 1)
	{
		cout << "����λ�ò��Ϸ���" << endl;
		return ERROR;
	}
	Node *pNew = new Node;
	//������ָ��ʧ�ܣ�����
	if (pNew == NULL)
	{
		cout << "Error create..." << endl;
		exit(OVERFLOW);
	}
	pNew->data = e;
	//����ȥ�ҵ�pos��λ��
	Node *ptr = head;
	for (int i = 1; i < pos; i++)
	{
		ptr = ptr->next;
	}
	pNew->next = ptr->next;
	ptr->next = pNew;
	size++;
	return OK;
}

//������ĳԪ�ز�������
Status LinkList::insert(ElemType e)
{
	Node *pNew = new Node;
	if (pNew == NULL)
	{
		cout << "Error create..." << endl;
		exit(OVERFLOW);
	}
	pNew->data = e;
	//����ȥ�������Ԫ�ؿ������������
	Node *ptr = head;
	for (int i = 1; i < size+1; i++)
	{
		if (e>=ptr->next->data)
		{
			//���iΪ�������ʾ����Ԫ�ش����������һ��Ԫ�أ�������Ԫ�ز����ĩ
			if (i==size)
			{
				ptr = ptr->next;
				pNew->next = ptr->next;
				ptr->next = pNew;
				break;
			}
			else
			{
				//���iδ��������һλ��������Ԫ�ش���i+1λ�õ�Ԫ�أ�ָ��Ų����һλ
				ptr = ptr->next;
			}
		}
		else
		{
			//������Ԫ��С��i+1λ�õ�Ԫ�أ�������Ԫ�ز���i��
			pNew->next = ptr->next;
			ptr->next = pNew;
			break;
		}
	}
	size++;
	return OK;
}

//ɾ��������ĳλ�õ�Ԫ�أ�������ɾ����Ԫ�ص�ֵ
Status LinkList::del(ElemType &e, int pos)
{
	//���λ���Ƿ�Ϸ�
	if (pos<1 || pos>size)
	{
		cout << "ɾ��λ�ò��Ϸ���" << endl;
		return ERROR;
	}
	Node *ptr = head;
	for (int i = 1; i < pos; i++)
	{
		ptr = ptr->next;
	}
	Node *q = ptr->next;
	ptr->next = ptr->next->next;
	e = q->data;
	free(q);
	size--;
	return OK;
}

//���������Ƿ���ĳԪ�أ�����еĻ�����Ԫ�ص�λ��
Status LinkList::find(ElemType e)
{
	Node *ptr = head->next;
	for (int i = 0; i < size; i++)
	{
		if (e==ptr->data)
		{
			return i + 1;
		}
		else
		{
			ptr = ptr->next;
			continue;
		}
	}
	cout << e << "Ԫ�ز��ڱ������У�" << endl;
	return ERROR;
}

//���ش�ʱ��
int LinkList::length()
{
	return size;
}

//����ʱ�����Ƿ�Ϊ��
bool LinkList::isEmpty()
{
	if (head->next=NULL)
	{
		return true;
	}
	return false;
}

//���Ŀǰ������Ϣ
void LinkList::print()
{
	if (size > 0)
	{
		Node *pTemp = head;
		cout << "��������Ϊ��" << size << "��������Ϊ��" << pTemp->next->data;
		pTemp = pTemp->next;
		while (pTemp->next != NULL)
		{
			cout << "," << pTemp->next->data;
			pTemp = pTemp->next;
		}
		cout << endl;
	}
	else
	{
		cout << "��ǰ���Ա�Ϊ��" << endl;
		exit(OVERFLOW);
	}
}

//�ж��ַ��������Ƿ�ȫΪ����
Status isNum(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		int asc = (int)str[i];
		if (asc >= 48 && asc <= 57)
		{
			continue;
		}
		else
		{
			return ERROR;
		}
	}
	return OK;
}
