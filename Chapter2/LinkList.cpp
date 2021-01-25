#include "LinkList.h"
Status isNum(string str);

LinkList::LinkList()
{
	head = new Node;
	head->next = nullptr;
	size = 0;
}

//以现有数组创建增序链表
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
		//当a[i]小于后面的元素时，把a[i]的数据输入链表中
		pNew = new Node;
		pNew->next = nullptr;
		pNew->data = a[i];
		pTemp->next = pNew;
		//将指针挪至下一位
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

//用户给定长度和内容，创建增序链表
Status LinkList::create(int size)//顺序创建
{
	//定义字符判断用户输入是否合法
	string input;
	int temp = 0;
	//判断size是否符合长度
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
		cout << "请输入第" << i + 1 << "个元素：";
		cin >> input;
		//判断用户输入的元素是否是数字，如果不是的话要求用户重新输入
		if (!isNum(input))
		{
			cout << "请输入数字！" << endl;
			goto L1;
		}
		else
		{
			//将用户的输入的字符串转为数字
			stringstream st;
			st << input;
			st >> pNew->data;
		}
		//判断用户的输入顺序是否为增序，并要求用户按增序输入
		while (pTemp->data > pNew->data)
		{
L2:			input = '0';
			cout << "输入不合法，请以增序输入第" << i + 1 << "个元素：";
			cin >> input;
			if (!isNum(input))
			{
				cout << "请输入数字！" << endl;
				goto L2;
			}
			else
			{
				//将字符串转换为数字
				stringstream st;
				st << input;
				st >> pNew->data;
			}
		}
		pTemp->next = pNew;
		//保留下一次插入的位置
		pTemp = pNew;
	}
	//更新size
	this->size = size;
	cout << "创建完毕" << endl;
	return OK;
}

//根据位置返回链表中此位置的元素
Status LinkList::get(ElemType &e, int pos)
{
	//判断用户想要查找的位置是否合法
	if (pos<1||pos>size)
	{
		cout << "输入位置不合法！" << endl;
		return ERROR;
	}
	Node *ptr = head;
	//遍历链表，找到第pos位置
	for (int i = 0; i <= pos-1; i++)
	{
		//若没有找到对应的位置，指针挪至下一位
		ptr = ptr->next;
	}
	e = ptr->data;
	return OK;
}

//按位置插入元素
Status LinkList::insert(ElemType e, int pos)
{
	//判断用户输入位置是否合法
	if (pos < 1 || pos>size + 1)
	{
		cout << "插入位置不合法！" << endl;
		return ERROR;
	}
	Node *pNew = new Node;
	//若创建指针失败，报错
	if (pNew == NULL)
	{
		cout << "Error create..." << endl;
		exit(OVERFLOW);
	}
	pNew->data = e;
	//遍历去找第pos个位置
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

//按增序将某元素插入链表
Status LinkList::insert(ElemType e)
{
	Node *pNew = new Node;
	if (pNew == NULL)
	{
		cout << "Error create..." << endl;
		exit(OVERFLOW);
	}
	pNew->data = e;
	//遍历去找输入的元素可以在哪里插入
	Node *ptr = head;
	for (int i = 1; i < size+1; i++)
	{
		if (e>=ptr->next->data)
		{
			//如果i为表长，则表示输入元素大于链表最后一个元素，把输入元素插入表末
			if (i==size)
			{
				ptr = ptr->next;
				pNew->next = ptr->next;
				ptr->next = pNew;
				break;
			}
			else
			{
				//如果i未到表的最后一位，且输入元素大于i+1位置的元素，指针挪至下一位
				ptr = ptr->next;
			}
		}
		else
		{
			//当输入元素小于i+1位置的元素，将输入元素插入i后
			pNew->next = ptr->next;
			ptr->next = pNew;
			break;
		}
	}
	size++;
	return OK;
}

//删除链表中某位置的元素，并储存删除的元素的值
Status LinkList::del(ElemType &e, int pos)
{
	//检查位置是否合法
	if (pos<1 || pos>size)
	{
		cout << "删除位置不合法！" << endl;
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

//找链表中是否有某元素，如果有的话返回元素的位置
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
	cout << e << "元素不在本链表中！" << endl;
	return ERROR;
}

//返回此时表长
int LinkList::length()
{
	return size;
}

//检查此时链表是否为空
bool LinkList::isEmpty()
{
	if (head->next=NULL)
	{
		return true;
	}
	return false;
}

//输出目前链表信息
void LinkList::print()
{
	if (size > 0)
	{
		Node *pTemp = head;
		cout << "此链表长度为：" << size << "个，内容为：" << pTemp->next->data;
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
		cout << "当前线性表为空" << endl;
		exit(OVERFLOW);
	}
}

//判断字符串内容是否全为数字
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
