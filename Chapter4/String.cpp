#include "String.h"



String::String()
{
}

String::String(const char *ch)
{
	length = strlen(ch);
	//�жϳ���
	if (length > MAX_STRLEN)
	{
		cout << "�����ַ���������" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			str[i] = *(ch + i);//ָ��ȡֵ
		}
	}
}


String::~String()
{
}


Status String::concat(String& t)//��������������
{
	bool uncat = false;
	//���г��ȵ���max����������
	if (length == MAX_STRLEN)
	{
		uncat = false;
	}
	//��������֮��û����max��ֱ�����
	else if (length + t.length <= MAX_STRLEN)
	{
		for (int i = 0; i < t.length; i++)
		{
			str[length + i] = t.str[i];
		}
		length += t.length;
		uncat = true;
	}
	//����������ӳ���max�ͽض�
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

Status String::size()//�󴮳�
{
	return length;
}

void String::print()//����ַ���
{
	for (int i = 0; i < length; i++)
	{
		cout << str[i];
	}
	cout << endl;
}

Status String::strcopy(String& t)//t��������ǰ����
{   //���ƣ�t���ȴ��ڵ�ǰ�ĳ��ȣ��ض�
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

Status String::empty()//�пղ���
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

//���������бȽϣ����ظ�����ʾ��ǰ����С��t������0��ʾ��ȣ�����������ʾ����t
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
	return 0;//��ʾȫ�����
}

Status String::substring(String& t, int pos, int len)//���Ӵ���������pos��ȡ����Ϊlen���Ӵ�
{
	//�ж�pos���Ƿ����ȡ����Ϊlen���Ӵ�
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

int String::index(String& t, int pos)//��ģʽƥ��
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

Status String::replace(String oldStr, String newStr)//�滻
{
	int i = 0;
	int j = 0;
	String temp(oldStr);
	//���ȿ������Ƿ������Ҫ�滻���Ӵ�
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
		cout << "����û��������Ҫ�滻���ַ�����" << endl;
		return 0;
	}
	return OK;
}

Status String::insert(String& t, int pos)//��ָ����λ�ò���t
{
	return OK;
}

Status String::del(int pos, int len)//��posɾ������len���Ӵ�
{
	return OK;
}

Status String::clear()//��մ�
{
	length = 0;
	return OK;
}