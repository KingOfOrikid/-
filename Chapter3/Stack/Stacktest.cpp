#include "Stack.h"

int main_Stacktest()
{
	Stack<char> s1;//声明int类型的stack
	s1.initStack();
	while (true)
	{
		char input;
		cout << "请输入你要进栈的元素:";
		cin >> input;
		s1.push(input);
		cout << "是否继续进栈(y or n):";
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
		cout << "退栈的元素:" << e << endl;
	}
	system("pause");
	return 0;
}