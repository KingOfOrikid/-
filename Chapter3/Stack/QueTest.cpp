#include "Queu.h"
using namespace std;

int main_QueTest()
{
	Queu<int> q;//����int���͵�stack
	q.initStack();
	while (true)
	{
		int input;
		cout << "��������Ҫ��ջ��Ԫ��:";
		cin >> input;
		q.push(input);
		cout << "�Ƿ������ջ(y or n):";
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
		cout << "�˶��е�Ԫ��:" << e << endl;
	}
	system("pause");
	return 0;
}