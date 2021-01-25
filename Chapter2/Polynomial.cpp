#include "Polynomial.h"



Polynomial::Polynomial()
{
	head = new Node;
	head->next = nullptr;
	size = 0;
}


Polynomial::~Polynomial()
{
	Node *ptr;
	while (head != NULL)
	{
		ptr = head;
		head = head->next;
		delete ptr;
	}
}


Status Polynomial::create(float coe[],int exp[], int len_1, int len_2)
{
	//比较两个数组长度是否相等（数据是否对应正确）
	if (len_1!=len_2)
	{
		cout << "指数系数数量对应不正确！" << endl;
		return ERROR;
	}
	//遍历创建并赋值多项式链表
	Node *pNew = NULL;
	Node *pTemp = head;
	for (int i = 0; i < len_1; i++)
	{
		pNew = new Node;
		pNew->next = NULL;
		pNew->coef = coe[i];
		pNew->expn = exp[i];
		pTemp->next = pNew;
		//保留下一次插入位置
		pTemp = pNew;
	}
	size = len_1;
	cout << "创建完毕" << endl;
	return OK;
}

Status Polynomial::plus(Polynomial& p1, Polynomial& p2)
{
	Node *p = p1.head->next;
	Node *q = p2.head->next;
	Node *s = p1.head;//保存p1的前驱
	int sign = 0;
	//检查两个多项式是否为空
	while(p != NULL&&q != NULL)
	{
		//当p1的指数小于p2的指数时，p1指针后移
		if (p->expn<q->expn)
		{
			s = s->next;
			p = p->next;
		}
		//当p1的指数大于p2的指数时，将p2挪至p1指针前
		else if (p->expn > q->expn)
		{
			s->next = q;
			s = s->next;
			q = q->next;
			s->next = p;
			p1.size++;
			sign++;
		}
		//当p1指数和p2指数相等，系数相加
		else
		{
			p->coef = p->coef + q->coef;
			sign++;
			//如果此时系数为0，删除此结点
			if (p->coef == 0)
			{
				Node *t1 = p;
				p = p->next;
				s->next = p;
				free(t1);
				q = q->next;
				p1.size--;

			}
			else
			{
				s = p;
				p = p->next;
				q = q->next;
			}
		}
	}
	//如果p2还没有遍历完，把p2剩余的项全部挪至p1末尾
	if (p==NULL)
	{
		if (q!=NULL)
		{
			s->next = q;
			//free(p);
			p1.size += p2.size - sign;
		}
		return OK;
	}
	else
	{
		return OK;
	}
	/*if(p==NULL||q==NULL)
	{
		cout << "请检查两多项式是否都有效！" << endl;
		return OVERFLOW;
	}*/
}

Status Polynomial::mulp(Polynomial p1, Polynomial p2)
{
	Node *p = p1.head->next;
	Node *q = p2.head->next;
	vector<float> coe;
	vector<int> exp;
	//先检查两个相乘的式子是否合法
	//指针先指向p1的第一个结点，并遍历p2进行乘法，将数据存到系数数组和指数数组中
	if (p!=NULL&&q!=NULL)
	{
		for (int i = 0; i < p1.size; i++)
		{
			float tempc = 0;
			int tempe = 0;
			q = p2.head->next;
			for (int j = 0; j < p2.size; j++)
			{
				tempc = p->coef*q->coef;
				tempe = p->expn + q->expn;
				coe.push_back(tempc);
				exp.push_back(tempe);
				q = q->next;
			}
			p = p->next;
		}
	}
	//检查指数数组中是否有相同指数的项，若有，将系数数组中对应的相加
	for (int i = 0; i < exp.size(); i++)
	{
		for (int j = 0; j < exp.size(); j++)
		{
			if (i==j)
			{
				continue;
			}
			else
			{
				if (exp[i] == exp[j])
				{
					coe[i] += coe[j];
					coe.erase(coe.begin() + j);
					exp.erase(exp.begin() + j);
					j--;
				}
			}
		}
		
	}
	for (int i = 0; i < exp.size(); i++)
	{
		if (coe[i] == 0)
		{
			coe.erase(coe.begin() + i - 1);
			exp.erase(exp.begin() + i - 1);
		}
	}
	Node *pNew = NULL;
	Node *pTemp = head;
	for (int i = 0; i < coe.size(); i++)
	{
		pNew = new Node;
		pNew->next = NULL;
		pNew->coef = coe[i];
		pNew->expn = exp[i];
		pTemp->next = pNew;
		//保留下一次插入位置
		pTemp = pNew;
	}
	size = coe.size();
	cout << "创建完毕" << endl;
	return OK;
}

void Polynomial::print()
{
	if (size>0)
	{
		cout << "此多项式的项数为:" << size << endl;
		cout << "多项式式子为：";
		Node *pTemp = head;
		pTemp = pTemp->next;
		cout << "(" << pTemp->coef << "×" << "x^" << pTemp->expn << ")";
		for (int i = 1; i < size; i++)
		{
			pTemp = pTemp->next;
			cout << "+" << "(" << pTemp->coef << "×" << "x^" << pTemp->expn << ")";
		}
		cout << endl;
	}
	else
	{
		cout << "当前多项式为空！" << endl;
		exit(OVERFLOW);
	}
}
