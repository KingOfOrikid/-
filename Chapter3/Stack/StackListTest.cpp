#include "StackList.h"

int main_StackListTest()
{
	StackList<int> s1;
	s1.initStack();
	while (true)
	{
		int input;
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
	int e;
	while (!s1.isEmpty())
	{
		s1.pop(e);
		cout << "��ջ��Ԫ��:" << e << endl;
	}
	system("pause");
	return 0;
}