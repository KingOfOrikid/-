#include "Queu.h"
using namespace std;

int main_QueTest()
{
	Queu<int> q;//声明int类型的stack
	q.initStack();
	while (true)
	{
		int input;
		cout << "请输入你要进栈的元素:";
		cin >> input;
		q.push(input);
		cout << "是否继续进栈(y or n):";
		char ch;
		cin >> ch;
		if (ch == 'n')
		{
			break;
		}
	}
	q.traverse();
	int e;
	q.getTop(e);
	cout << e << endl;
	while (!q.isEmpty())
	{
		q.pop(e);
		cout << "退队列的元素:" << e << endl;
	}
	system("pause");
	return 0;
}