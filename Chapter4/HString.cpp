#include "HString.h"



HString::HString()
{
	ch = NULL;
	length = 0;
}

//构造重载函数，给一个字符串常量构造一个字符串
HString::HString(const char* p)
{
	int len = strlen(p);
	ch = (char*)malloc(len * sizeof(char));
	if (!ch)
	{
		exit(OVERFLOW);
	}
	for (int i = 0; i < len; i++)
	{
		ch[i] = p[i];
	}
	length = len;
}


HString::~HString()
{
	ch = NULL;
	free(ch);
}

Status HString::assign(const char* p)//串赋值
{
	//判断当前对象是否有内容,有则释放
	//判断p是否为空，为空不赋值
	//根据p的长度申请空间给当前对象
	int len = strlen(p);
	if (!ch)
	{
		free(ch);
	}
	if (!len)
	{
		ch=NULL;
		length = 0;
		return ERROR;
	}
	else
	{
		ch = (char*)malloc(len * sizeof(char));

		if (!ch)
		{
			exit(OVERFLOW);
		}
		for (int i = 0; i < len; i++)
		{
			ch[i] = p[i];
		}
		length = len;
	}
	return OK;
}
Status HString::concat(HString& s1, HString& s2)//s1和s2连接起来给新的串
{
	//申请空间
	ch = (char*)malloc(sizeof(char)*(s1.length + s2.length));
	if (!ch)
	{
		exit(OVERFLOW);
	}

	//将s1，s2赋值给当前对象
	for (int i = 0; i < s1.length; i++)
	{
		ch[i] = s1.ch[i];
	}
	for (int i = 0; i < s2.length; i++)
	{
		ch[s1.length + i] = s2.ch[i];
	}
	length = s1.length + s2.length;
	return OK;
}
Status HString::print()
{
	if (!ch)
	{
		cout << "当前串为空！" << endl;
	}
	for (int i = 0; i < length; i++)
	{
		cout << ch[i];
	}
	cout << endl;
	return OK;
}
int HString::size()
{
	return length;
}
Status HString::del(int pos, int len)//pos从1开始,从pos起，不包括pos
{
	//首先判断pos位置是否合法以及是否足够删除长度为len的字符串
	if (pos >= length)
	{
		return ERROR;
	}
	if (pos + len > length)
	{
		len = length - pos + 1;
	}
	for (int i = pos; i < length - len; i++)
	{
		ch[i] = ch[i + len];
	}
	//表长减少
	length -= len;
	//重新分配空间
	ch = (char*)realloc(ch, sizeof(char)*length);
	if (!ch)
	{
		exit(OVERFLOW);
	}
	return OK;
}
Status HString::insert(int pos, HString& t)//在pos位置后插入字符串t(pos是从1开始的)
{
	int len = t.length;
	ch = (char*)realloc(ch, (length + len) * sizeof(char));
	if (!ch)
	{
		exit(OVERFLOW);
	}
	//判断位置是否合法
	if (pos > length)
	{
		pos = length;
	}
	//移动
	for (int i = length - 1; i > pos - 1; --i)
	{
		ch[i + len] = ch[i];
	}
	//插入
	for (int i = 0; i < len; i++)
	{
		ch[i + pos] = t.ch[i];
	}
	length = length + len;
	return OK;
}
Status HString::index(HString& t, int pos)
{
	int i = pos;
	int j = 0;
	while (i < length&&j < t.length)
	{
		if (ch[i] == t.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= t.length)
	{
		return i - t.length;
	}
	return OK;
}
Status HString::substring(HString& sub, int pos, int len)//求子串，用sub返回
{
	//判断参数是否合法
	if (pos < 0 || pos >= length || len<0 || len>length + 1 - pos)
	{
		return ERROR;
	}
	if (!sub.ch)
	{
		sub.ch = (char*)malloc(sizeof(char)*len);
		if (!sub.ch)
		{
			return ERROR;
		}
	}
	for (int i = 0; i < len; i++)
	{
		sub.ch[i] = ch[pos + i];
	}

	sub.length = len;
	return OK;
}
int HString::index_kmp(HString& t)
{
	//动态分配next
	int *next = new int[t.length];
	getNext(t, next);
	int i = 0;
	int j = -1;
	while (j < t.length&&i < length)
	{
		if (j == -1 || t.ch[j] == ch[i])
		{
			j++;
			i++;
		}
		else
		{
			j = next[j];
		}
	}
	//删除next
	delete[] next;

	if (j >= t.length)
	{
		return i - t.length;
	}
	else
	{
		return -1;
	}
}
bool HString::empty()
{
	if (length==0)
	{
		return true;
	}
	return false;
}
Status HString::replace(HString& oldStr, HString& newStr)//替换操作
{
	int pos = 0;
	if (oldStr.empty())
	{
		return ERROR;
	}
	//在主串里找到oldStr
	do
	{
		pos = index_kmp(oldStr);
		//删除oldStr
		if (pos >= 0)
		{
			del(pos, oldStr.length);
		}
		//插入newStr
		insert(pos, newStr);
	} while (pos >= 0);
	return OK;
}
void HString::getNext(HString& t, int next[])
{
	int k = 0;
	int j = -1;
	next[0] = -1;

	while (k < t.length - 1)
	{
		if ((j == -1) || (t.ch[k] == t.ch[j]))
		{
			k++;
			j++;
			next[k] = j;
			//改进代码自行补充
		}
		else
		{
			j = next[j];
		}
	}
}


//输出串s和t的最长公共子串在s和t中的起始位置和长度，如果有多个最长的，那么都输出
void HString::ComMAXSubstring(HString& s, HString& t)
{
	//首先判断两个串是否都合法
	//先取串s的第一个字符，遍历t进行比较
	//如果s中的字符与t中某个字符相同的话，记录下此时的位置，并往后计算重合的子串
	//如果此时重合的子串的长度大于目前重合子串的最大值，那就成为最大长度重合子串
	//遍历完t以后，s挪到后一个字符继续遍历

	//建立动态数组存出现公共子串的起始位置和最大子串长度
	vector<int> PosS;
	vector<int> PosT;
	vector<int> Maxlen;

	//判断两个串的长度是否合法
	if (s.empty() || t.empty())
	{
		cout << "输入串不合法！" << endl;
		exit(ERROR);
	}
	else
	{
		//首先定义变量存储暂时的位置、暂时的长度和位置和长度
		int posS, posT,tempS,tempT;
		int tempLen = 0;
		int maxLen = 0;
		//遍历s串
		for (int i = 0; i < s.length; i++)
		{
			//遍历t串
			for (int j = 0; j < t.length; j++)
			{
				tempLen = 0;
				//当s和t开始有公共子串的时候，记录下起始位置
				if (s.ch[i] == t.ch[j])
				{
					tempS = i;
					tempT = j;
					//从起始位置开始遍历，找最长的重合子串
					while (s.ch[i]==t.ch[j])
					{
						tempLen++;
						j++;
						i++;
					}
					//遍历完成后将i和j恢复到原来的位置准备下一次遍历
					i = tempS;
					j = tempT;
					//当此时子串的长度大于现有最长子串的长度时，把原来存进数组的子串位置和长度删除，存入现在的位置和长度
					if (tempLen > maxLen)
					{
						posS = tempS;
						posT = tempT;
						maxLen = tempLen;
						if (!Maxlen.empty())
						{
							PosS.pop_back();
							PosT.pop_back();
							Maxlen.pop_back();
						}
						PosS.push_back(posS);
						PosT.push_back(posT);
						Maxlen.push_back(maxLen);
					}
					else if (tempLen == maxLen)//当两个串的长度相同的时候，不删除原来的，直接存入现有的
					{
						posS = tempS;
						posT = tempT;
						maxLen = tempLen;
						PosS.push_back(posS);
						PosT.push_back(posT);
						Maxlen.push_back(maxLen);
					}
				}
				else
				{
					continue;
				}
			}
		}
		//遍历结束后，遍历储存子串位置和长度的数组，进行输出
		for (int i = 0; i < Maxlen.size(); i++)
		{
			cout << "最长公共子串的长度为:" << Maxlen[i] << "," << "分别从子串1的第" << PosS[i]+1 << "开始，从子串2的第" << PosT[i]+1 << "开始" << endl;
		}
		
	}
}
