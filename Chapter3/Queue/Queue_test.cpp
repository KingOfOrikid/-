#include "Queue.h"

using namespace std;
int main()
{
	Queue<int> q1;
	q1.initQueue();
	while (true)
	{
		cout << "请输入需要入队的元素:";
		int e;
		cin >> e;
		q1.push(e);
		cout << "是否继续输入(y or n):";
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
		cout << "出队的元素为" << e << endl;
	}
	q1.traverse();
	system("pause");
	return 0;
}