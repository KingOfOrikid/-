#include "Stack.h"
//����ƥ����

int main_BracketMatch() 
{
	Stack<char> s1;
	s1.initStack();
	string input;
	while (true)
	{
		s1.clear();
		input = "";
		cout << "����������Ҫ���ı��ʽ:";
		cin >> input;
		for (int i = 0; i < input.length(); i++)
		{
			//����������ʱ�������Ž�ջ
			if (input[i]=='('|| input[i] == '{' || input[i]=='[')
			{
				s1.push(input[i]);
			}
			else if (input[i] == ')' || input[i] == '}' || input[i]==']')
			{
				char elem;
				//�����ǰΪ��ջ��˵�������ű������Ŷ࣬ƥ��ʧ��
				if (s1.isEmpty())
				{
					cout << "ƥ��ʧ�ܣ�" << endl;
					return 0;
				}
				else
				{
					s1.pop(elem);
					if (input[i] == ')'&&elem == '(')
					{
						continue;
					}
					else if (input[i] == '}'&&elem == '{')
					{
						continue;
					}
					else if (input[i] == ']'&&elem == '[')
					{
						continue;
					}
					else
					{
						cout << "ƥ��ʧ�ܣ�" << endl;
						return ERROR;
					}
				}
			}
		}
		if (s1.isEmpty())
		{
			cout << "ƥ��ɹ���" << endl;
			return 0;
		}
		else
		{
			cout << "ƥ��ʧ�ܣ�" << endl;
		}
	}
	system("pause");
	return 0;
}