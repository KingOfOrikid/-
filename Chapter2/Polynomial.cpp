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
	//�Ƚ��������鳤���Ƿ���ȣ������Ƿ��Ӧ��ȷ��
	if (len_1!=len_2)
	{
		cout << "ָ��ϵ��������Ӧ����ȷ��" << endl;
		return ERROR;
	}
	//������������ֵ����ʽ����
	Node *pNew = NULL;
	Node *pTemp = head;
	for (int i = 0; i < len_1; i++)
	{
		pNew = new Node;
		pNew->next = NULL;
		pNew->coef = coe[i];
		pNew->expn = exp[i];
		pTemp->next = pNew;
		//������һ�β���λ��
		pTemp = pNew;
	}
	size = len_1;
	cout << "�������" << endl;
	return OK;
}

Status Polynomial::plus(Polynomial& p1, Polynomial& p2)
{
	Node *p = p1.head->next;
	Node *q = p2.head->next;
	Node *s = p1.head;//����p1��ǰ��
	int sign = 0;
	//�����������ʽ�Ƿ�Ϊ��
	while(p != NULL&&q != NULL)
	{
		//��p1��ָ��С��p2��ָ��ʱ��p1ָ�����
		if (p->expn<q->expn)
		{
			s = s->next;
			p = p->next;
		}
		//��p1��ָ������p2��ָ��ʱ����p2Ų��p1ָ��ǰ
		else if (p->expn > q->expn)
		{
			s->next = q;
			s = s->next;
			q = q->next;
			s->next = p;
			p1.size++;
			sign++;
		}
		//��p1ָ����p2ָ����ȣ�ϵ�����
		else
		{
			p->coef = p->coef + q->coef;
			sign++;
			//�����ʱϵ��Ϊ0��ɾ���˽��
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
	//���p2��û�б����꣬��p2ʣ�����ȫ��Ų��p1ĩβ
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
		cout << "����������ʽ�Ƿ���Ч��" << endl;
		return OVERFLOW;
	}*/
}

Status Polynomial::mulp(Polynomial p1, Polynomial p2)
{
	Node *p = p1.head->next;
	Node *q = p2.head->next;
	vector<float> coe;
	vector<int> exp;
	//�ȼ��������˵�ʽ���Ƿ�Ϸ�
	//ָ����ָ��p1�ĵ�һ����㣬������p2���г˷��������ݴ浽ϵ�������ָ��������
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
	//���ָ���������Ƿ�����ָͬ��������У���ϵ�������ж�Ӧ�����
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
		//������һ�β���λ��
		pTemp = pNew;
	}
	size = coe.size();
	cout << "�������" << endl;
	return OK;
}

void Polynomial::print()
{
	if (size>0)
	{
		cout << "�˶���ʽ������Ϊ:" << size << endl;
		cout << "����ʽʽ��Ϊ��";
		Node *pTemp = head;
		pTemp = pTemp->next;
		cout << "(" << pTemp->coef << "��" << "x^" << pTemp->expn << ")";
		for (int i = 1; i < size; i++)
		{
			pTemp = pTemp->next;
			cout << "+" << "(" << pTemp->coef << "��" << "x^" << pTemp->expn << ")";
		}
		cout << endl;
	}
	else
	{
		cout << "��ǰ����ʽΪ�գ�" << endl;
		exit(OVERFLOW);
	}
}
