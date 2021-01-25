#include "HString.h"



HString::HString()
{
	ch = NULL;
	length = 0;
}

//�������غ�������һ���ַ�����������һ���ַ���
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

Status HString::assign(const char* p)//����ֵ
{
	//�жϵ�ǰ�����Ƿ�������,�����ͷ�
	//�ж�p�Ƿ�Ϊ�գ�Ϊ�ղ���ֵ
	//����p�ĳ�������ռ����ǰ����
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
Status HString::concat(HString& s1, HString& s2)//s1��s2�����������µĴ�
{
	//����ռ�
	ch = (char*)malloc(sizeof(char)*(s1.length + s2.length));
	if (!ch)
	{
		exit(OVERFLOW);
	}

	//��s1��s2��ֵ����ǰ����
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
		cout << "��ǰ��Ϊ�գ�" << endl;
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
Status HString::del(int pos, int len)//pos��1��ʼ,��pos�𣬲�����pos
{
	//�����ж�posλ���Ƿ�Ϸ��Լ��Ƿ��㹻ɾ������Ϊlen���ַ���
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
	//������
	length -= len;
	//���·���ռ�
	ch = (char*)realloc(ch, sizeof(char)*length);
	if (!ch)
	{
		exit(OVERFLOW);
	}
	return OK;
}
Status HString::insert(int pos, HString& t)//��posλ�ú�����ַ���t(pos�Ǵ�1��ʼ��)
{
	int len = t.length;
	ch = (char*)realloc(ch, (length + len) * sizeof(char));
	if (!ch)
	{
		exit(OVERFLOW);
	}
	//�ж�λ���Ƿ�Ϸ�
	if (pos > length)
	{
		pos = length;
	}
	//�ƶ�
	for (int i = length - 1; i > pos - 1; --i)
	{
		ch[i + len] = ch[i];
	}
	//����
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
Status HString::substring(HString& sub, int pos, int len)//���Ӵ�����sub����
{
	//�жϲ����Ƿ�Ϸ�
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
	//��̬����next
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
	//ɾ��next
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
Status HString::replace(HString& oldStr, HString& newStr)//�滻����
{
	int pos = 0;
	if (oldStr.empty())
	{
		return ERROR;
	}
	//���������ҵ�oldStr
	do
	{
		pos = index_kmp(oldStr);
		//ɾ��oldStr
		if (pos >= 0)
		{
			del(pos, oldStr.length);
		}
		//����newStr
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
			//�Ľ��������в���
		}
		else
		{
			j = next[j];
		}
	}
}


//�����s��t��������Ӵ���s��t�е���ʼλ�úͳ��ȣ�����ж����ģ���ô�����
void HString::ComMAXSubstring(HString& s, HString& t)
{
	//�����ж��������Ƿ񶼺Ϸ�
	//��ȡ��s�ĵ�һ���ַ�������t���бȽ�
	//���s�е��ַ���t��ĳ���ַ���ͬ�Ļ�����¼�´�ʱ��λ�ã�����������غϵ��Ӵ�
	//�����ʱ�غϵ��Ӵ��ĳ��ȴ���Ŀǰ�غ��Ӵ������ֵ���Ǿͳ�Ϊ��󳤶��غ��Ӵ�
	//������t�Ժ�sŲ����һ���ַ���������

	//������̬�������ֹ����Ӵ�����ʼλ�ú�����Ӵ�����
	vector<int> PosS;
	vector<int> PosT;
	vector<int> Maxlen;

	//�ж��������ĳ����Ƿ�Ϸ�
	if (s.empty() || t.empty())
	{
		cout << "���봮���Ϸ���" << endl;
		exit(ERROR);
	}
	else
	{
		//���ȶ�������洢��ʱ��λ�á���ʱ�ĳ��Ⱥ�λ�úͳ���
		int posS, posT,tempS,tempT;
		int tempLen = 0;
		int maxLen = 0;
		//����s��
		for (int i = 0; i < s.length; i++)
		{
			//����t��
			for (int j = 0; j < t.length; j++)
			{
				tempLen = 0;
				//��s��t��ʼ�й����Ӵ���ʱ�򣬼�¼����ʼλ��
				if (s.ch[i] == t.ch[j])
				{
					tempS = i;
					tempT = j;
					//����ʼλ�ÿ�ʼ������������غ��Ӵ�
					while (s.ch[i]==t.ch[j])
					{
						tempLen++;
						j++;
						i++;
					}
					//������ɺ�i��j�ָ���ԭ����λ��׼����һ�α���
					i = tempS;
					j = tempT;
					//����ʱ�Ӵ��ĳ��ȴ���������Ӵ��ĳ���ʱ����ԭ�����������Ӵ�λ�úͳ���ɾ�����������ڵ�λ�úͳ���
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
					else if (tempLen == maxLen)//���������ĳ�����ͬ��ʱ�򣬲�ɾ��ԭ���ģ�ֱ�Ӵ������е�
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
		//���������󣬱��������Ӵ�λ�úͳ��ȵ����飬�������
		for (int i = 0; i < Maxlen.size(); i++)
		{
			cout << "������Ӵ��ĳ���Ϊ:" << Maxlen[i] << "," << "�ֱ���Ӵ�1�ĵ�" << PosS[i]+1 << "��ʼ�����Ӵ�2�ĵ�" << PosT[i]+1 << "��ʼ" << endl;
		}
		
	}
}
