#include "Stack.h"
//����ת��
int main_Convert()
{
	Stack<int> s;
	s.initStack();
	while (true)
	{
		int number = 0;
		int decimal = 0;
		cout << "������Ҫת����������";
		cin >> number;
		cout << "������Ҫת���Ľ��ƣ�";
		cin >> decimal;
		while (number)
		{
			int k = number%decimal;
			s.push(k);
			number = number / decimal;
		}
		//��ջ
		cout << "ת����";
		while (!s.isEmpty())
		{
			int x;
			s.pop(x);
			cout << x;
		}
		cout << endl;

		char ch;
		cout << "�Ƿ���Ҫ����ת��(y or n)��";
		cin >> ch;
		if (ch == 'y')
		{
			continue;
		}
		else if (ch == 'n')
		{
			break;
		}
		else
		{
			cout << "�����ַ�����" << endl;
			return 0;
		}
	}
	system("pause");
	return 0;
}