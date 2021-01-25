#include "Stack.h"
//进制转换
int main_Convert()
{
	Stack<int> s;
	s.initStack();
	while (true)
	{
		int number = 0;
		int decimal = 0;
		cout << "请输入要转换的整数：";
		cin >> number;
		cout << "请输入要转换的进制：";
		cin >> decimal;
		while (number)
		{
			int k = number%decimal;
			s.push(k);
			number = number / decimal;
		}
		//退栈
		cout << "转换后：";
		while (!s.isEmpty())
		{
			int x;
			s.pop(x);
			cout << x;
		}
		cout << endl;

		char ch;
		cout << "是否需要继续转换(y or n)：";
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
			cout << "输入字符错误！" << endl;
			return 0;
		}
	}
	system("pause");
	return 0;
}