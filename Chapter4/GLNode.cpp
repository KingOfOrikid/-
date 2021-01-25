#include "GLNode.h"

using namespace std;


/*
创建一个广义表
看作一个字符串书写
*/
void preStr(string &str, string &hstr)//把表头分离出来
{
	//已提前去除两边的括号
	//a,(b,c,d)
	int n = str.size();
	//找第一个左括号，若第一个左括号是第一个字符，那么第一个左括号到第一个右括号内的元素就是表头元素
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
		//若第一个左括号不是第一个字符，那么字符串第一个字符就是表头
		hstr = str[0];
		str = str.substr(1, n - 1);
	}
	
}


void inital(GLNode *&gl,string s)
{
	//检查是否只有一个元素
	string tmp;
	//去掉首尾括号
	for (int i = 1; i < s.size()-1; i++)
	{
		tmp[i - 1] = s[i];
	}
	if (tmp.size()==0)//空
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
		if (tmp.size() == 1)//单个元素，建立原子节点
		{
			gl->tag = 0;
			gl->afom = tmp[0];
		}
		else
		{
			gl->tag = 1;
			GLNode *p, *q;
			p = gl;//p指向当前子表
			string hsub;
			do //重复建立n个子表
			{
				preStr(tmp, hsub);//tmp中分理出表头串hsub，同时，tmp去除了hsub
				inital(p->ptr.hp, hsub);
				q = p;//记录p，下面sub不为空，要再建立一个表尾节点，q记录上一层的p，用以连接q->ptr.tp = q 
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