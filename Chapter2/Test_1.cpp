#include "SqList.h"

int main_Test_1()
{
	int a[6]={12,34,5,1,3,9999};
	int n = 6;
	int e=0, pos=0;
	SqList lst(a,n);
	lst.print();
	Status flag;
	while (true)
	{
		cout << "请输入你想执行的操作(0-插入)、(1-删除)、(2-查找位置)、(3-查找元素)、(4-显示当前顺序表内容)、(其他-退出):";
		char ch;
		cin >> ch;
		if (ch == '0')
		{
			int choose;
			cout << "请输入插入方式(0-顺序插入)、(1-指定位置插入):";
			cin >> choose;
			if (choose == 0)
			{
				cout << "请输入要插入的元素：";
				cin >> e;
				flag = lst.insert(e);
				if (flag)
				{
					cout << "插入成功！插入后：" << endl;
					lst.print();
				}
				else
				{
					cout << "插入失败！" << endl;
				}
			}
			else if(choose == 1)
			{
				cout << "请输入要插入的元素及位置：";
				cin >> e >> pos;
				flag = lst.insert(e, pos);
				if (flag)
				{
					cout << "插入成功！插入后：" << endl;
					lst.print();
				}
				else
				{
					cout << "插入失败！" << endl;
				}
			}	
		}
		else if (ch == '1')
		{
			cout << "请输入你要删除的元素的位置：";
			cin >> pos;
			flag = lst.del(e, pos);
			if (flag)
			{
				cout << "删除成功！删除的元素为：" << e << ",删除后：" << endl;
				lst.print();
			}
			else
			{
				cout << "删除失败！" << endl;
			}
		}
		else if (ch=='2')
		{
			cout << "请输入你想查找的位置:";
			cin >> pos;
			flag=lst.get(e, pos);
			if (flag)
			{
				cout << "顺序表中位于" << pos << "的元素为" << e << endl;
			}
		}
		else if (ch == '3')
		{
			cout << "请输入你想查找的元素：";
			cin >> e;
			if (lst.find(e))
			{
				pos = lst.find(e);
				cout << e << "元素在顺序表里的位置为" << pos << endl;
			}
		}
		else
		{
			break;
		}
	}
	system("pause");
	return 0;
}