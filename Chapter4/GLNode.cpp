#include "GLNode.h"

using namespace std;


/*
����һ�������
����һ���ַ�����д
*/
void preStr(string &str, string &hstr)//�ѱ�ͷ�������
{
	//����ǰȥ�����ߵ�����
	//a,(b,c,d)
	int n = str.size();
	//�ҵ�һ�������ţ�����һ���������ǵ�һ���ַ�����ô��һ�������ŵ���һ���������ڵ�Ԫ�ؾ��Ǳ�ͷԪ��
	if (str[0]=='(')
	{
		int count = 0;
		int i = 1;
		for (i = 1; i < n; i++)
		{
			if (str[i] == ')')
			{
				hstr = '(' + str.substr(1, count) + ')';
				break;
			}
			count++;
		}
		str = str.substr(i + 1, n - count - 2);
	}
	else
	{
		//����һ�������Ų��ǵ�һ���ַ�����ô�ַ�����һ���ַ����Ǳ�ͷ
		hstr = str[0];
		str = str.substr(1, n - 1);
	}
	
}


void inital(GLNode *&gl,string s)
{
	//����Ƿ�ֻ��һ��Ԫ��
	string tmp;
	//ȥ����β����
	for (int i = 1; i < s.size()-1; i++)
	{
		tmp[i - 1] = s[i];
	}
	if (tmp.size()==0)//��
	{
		gl = NULL;
	}
	else
	{
		gl = (GLNode*)malloc(sizeof(GLNode));
		if (!gl)
		{
			exit(ERROR);
		}
		if (tmp.size() == 1)//����Ԫ�أ�����ԭ�ӽڵ�
		{
			gl->tag = 0;
			gl->afom = tmp[0];
		}
		else
		{
			gl->tag = 1;
			GLNode *p, *q;
			p = gl;//pָ��ǰ�ӱ�
			string hsub;
			do //�ظ�����n���ӱ�
			{
				preStr(tmp, hsub);//tmp�з������ͷ��hsub��ͬʱ��tmpȥ����hsub
				inital(p->ptr.hp, hsub);
				q = p;//��¼p������sub��Ϊ�գ�Ҫ�ٽ���һ����β�ڵ㣬q��¼��һ���p����������q->ptr.tp = q 
				if (!tmp.empty())
				{
					p = (GLNode*)malloc(sizeof(GLNode));
					if (!p)
					{
						exit(ERROR);
					}
					p->tag = 1;
					q->ptr.tp = p;
				}
			} while (!tmp.empty());
			q->ptr.tp = NULL;
		}
	}
}