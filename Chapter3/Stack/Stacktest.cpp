#include "Stack.h"

int main_Stacktest()
{
	Stack<char> s1;//����int���͵�stack
	s1.initStack();
	while (true)
	{
		char input;
		cout << "��������Ҫ��ջ��Ԫ��:";
		cin >> input;
		s1.push(input);
		cout << "�Ƿ������ջ(y or n):";
		char ch;
		cin >> ch;
		if (ch == 'n')
		{
			break;
		}
	}
	s1.traverse();
	char e;
	s1.getTop(e);
	cout << e << endl;
	while (!s1.isEmpty())
	{
		s1.pop(e);
		cout << s1.isEmpty() << endl;
		cout << "��ջ��Ԫ��:" << e << endl;
	}
	system("pause");
	return 0;
}