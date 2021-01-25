#include "String.h"



String::String()
{
}

String::String(const char *ch)
{
	length = strlen(ch);
	//判断长度
	if (length > MAX_STRLEN)
	{
		cout << "建立字符串过长！" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			str[i] = *(ch + i);//指针取值
		}
	}
}


String::~String()
{
}


Status String::concat(String& t)//两个串进行连接
{
	bool uncat = false;
	//现有长度等于max，不能连接
	if (length == MAX_STRLEN)
	{
		uncat = false;
	}
	//两个长度之和没超过max就直接相加
	else if (length + t.length <= MAX_STRLEN)
	{
		for (int i = 0; i < t.length; i++)
		{
			str[length + i] = t.str[i];
		}
		length += t.length;
		uncat = true;
	}
	//两个长度相加超过max就截断
	else
	{
		for (int i = 0; i < MAX_STRLEN - length; i++)
		{
			str[length + i] = t.str[i];
		}
		length = MAX_STRLEN;
	}
	return uncat;
}

Status String::size()//求串长
{
	return length;
}

void String::print()//输出字符串
{
	for (int i = 0; i < length; i++)
	{
		cout << str[i];
	}
	cout << endl;
}

Status String::strcopy(String& t)//t拷贝给当前对象
{   //完善：t长度大于当前的长度，截断
	if (t.length > MAX_STRLEN)
	{
		for (int i = 0; i < MAX_STRLEN; i++)
		{
			str[i] = t.str[i];
		}
		length = MAX_STRLEN;
	}
	else
	{
		for (int i = 0; i < t.length; i++)
		{
			str[i] = t.str[i];
		}
		length = t.length;
	}
	return OK;
}

Status String::empty()//判空操作
{
	if (length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//两个串进行比较，返回负数表示当前对象小与t，返回0表示相等，返回整数表示大于t
int String::strcmpy(String& t)
{
	if (length != t.length)
	{
		return length - t.length;
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			if (str[i] != t.str[i])
			{
				return str[i] - t.str[i];
			}
		}
	}
	return 0;//表示全部相等
}

Status String::substring(String& t, int pos, int len)//求子串操作，从pos起取长度为len的子串
{
	//判断pos起是否可以取长度为len的子串
	if (pos - 1 + len > length)
	{
		for (int i = 0; i < length; i++)
		{
			t.str[i] = str[pos - 1 + i];
		}
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			t.str[i] = str[pos - 1 + i];
		}
	}
	return OK;
}

int String::index(String& t, int pos)//简单模式匹配
{
	int i = pos;
	int j = 0;
	while (i < length&&j < t.length)
	{
		if (str[i] == t.str[j])
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
	return 0;
}

Status String::replace(String oldStr, String newStr)//替换
{
	int i = 0;
	int j = 0;
	String temp(oldStr);
	//首先看串中是否包含需要替换的子串
	while (i < length&&j < temp.length)
	{
		if (str[i] == temp.str[j])
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
	if (j >= temp.length)
	{
	}
	else
	{
		cout << "串中没有你所需要替换的字符串！" << endl;
		return 0;
	}
	return OK;
}

Status String::insert(String& t, int pos)//在指定的位置插入t
{
	return OK;
}

Status String::del(int pos, int len)//在pos删除长度len的子串
{
	return OK;
}

Status String::clear()//清空串
{
	length = 0;
	return OK;
}