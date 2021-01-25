#include "LinkList.h"
Status isNum(string str);

int main_Test_2()
{
	int a[5] = { 11,34,56,32,68 };
	Status flag;
	LinkList linklst(a,5);//使用数组初始化一个顺序链表
	int e, pos;
	while (true)
	{
		cout << "请输入你想执行的操作(0-插入)、(1-删除)、(2-查找位置)、(3-查找元素)、(4-链表长度)、(5-现有链表内容)、(6-创建新链表)、(9-退出):";
		char ch;
		cin >> ch;
		//插入方法，可以选泽顺序插入和位置插入
		if (ch == '0')
		{
			int choose;
			cout << "请输入插入方式(0-顺序插入)、(1-指定位置插入):";
			cin >> choose;
			if (choose == 0)
			{
				cout << "请输入要插入的元素：";
				cin >> e;
				flag = linklst.insert(e);
				if (flag)
				{
				cout << "插入成功！插入后：" << endl;
				linklst.print();
				}
				else
				{
				cout << "插入失败！" << endl;
				}
			}
			else if (choose == 1)
			{
				cout << "请输入要插入的元素及位置：";
				cin >> e >> pos;
				flag = linklst.insert(e, pos);
				if (flag)
				{
					cout << "插入成功！插入后：" << endl;
					linklst.print();
				}
				else
				{
					cout << "插入失败！" << endl;
				}
			}
		}
		//根据用户给的位置删除某个元素
		else if (ch == '1')
		{
			cout << "请输入你要删除的元素的位置：";
			cin >> pos;
			flag = linklst.del(e, pos);
			if (flag)
			{
				cout << "删除成功！删除的元素为：" << e << ",删除后：" << endl;
				linklst.print();
			}
			else
			{
				cout << "删除失败！" << endl;
			}
		}
		//查找某元素是否在链表中，在链表中哪一个位置
		else if (ch=='3')
		{
			string input="1";
			while (isNum(input))
			{
				cout << "请输入你要查找的元素：" ;
				cin >> input;
				if (isNum(input))
				{
					stringstream st;
					st << input;
					st >> e;
					if (linklst.find(e) != 0)
					{
						int pos = linklst.find(e);
						cout << e << "元素在链表中所在的位置为第" << pos << "个" << endl;
						break;
					}
					else
					{
						break;
					}
				}
				else
				{
					continue;
				}
			} 
		}
		//根据位置查找链表中位于此位置的元素
		else if (ch == '2')
		{
			string input = "1";
			while (isNum(input))
			{
				cout << "请输入你要查找的位置：";
				cin >> input;
				if (isNum(input))
				{
					stringstream st;
					st << input;
					st >> pos;
					if (linklst.get(e,pos) != 0)
					{
						cout << "链表中位于" << pos << "位置的元素为" << e << endl;
						break;
					}
					else
					{
						break;
					}
				}
				else
				{
					continue;
				}
			}
		}
		//输出目前链表的长度
		else if (ch == '4')
		{
			cout << "现有链表长度为：" << linklst.length() << endl;
		}
		//输出目前链表中的元素
		else if (ch == '5')
		{
			linklst.print();

		}
		//创建新链表，覆盖原有链表
		else if (ch == '6')
		{
			string input = "1";
			while (isNum(input))
			{
				cout << "请输入要创建链表的大小：";
				cin >> input;
				if (isNum(input))
				{
					stringstream st;
					st << input;
					st >> e;
					linklst.create(e);
					linklst.print();
					break;
				}
				else
				{
					break;
				}
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