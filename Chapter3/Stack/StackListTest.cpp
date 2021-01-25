#include "StackList.h"

int main_StackListTest()
{
	StackList<int> s1;
	s1.initStack();
	while (true)
	{
		int input;
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
	int e;
	while (!s1.isEmpty())
	{
		s1.pop(e);
		cout << "退栈的元素:" << e << endl;
	}
	system("pause");
	return 0;
}