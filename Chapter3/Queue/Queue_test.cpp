#include "Queue.h"

using namespace std;
int main()
{
	Queue<int> q1;
	q1.initQueue();
	while (true)
	{
		cout << "��������Ҫ��ӵ�Ԫ��:";
		int e;
		cin >> e;
		q1.push(e);
		cout << "�Ƿ��������(y or n):";
		char ch;
		cin >> ch;
		if (ch == 'y')
		{
			continue;
		}
		else if(ch=='n')
		{
			break;
		}
	}
	q1.traverse();
	int e;
	while (!q1.isEmpty())
	{
		q1.pop(e);
		cout << "���ӵ�Ԫ��Ϊ" << e << endl;
	}
	q1.traverse();
	system("pause");
	return 0;
}