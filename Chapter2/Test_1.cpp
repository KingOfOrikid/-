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
		cout << "����������ִ�еĲ���(0-����)��(1-ɾ��)��(2-����λ��)��(3-����Ԫ��)��(4-��ʾ��ǰ˳�������)��(����-�˳�):";
		char ch;
		cin >> ch;
		if (ch == '0')
		{
			int choose;
			cout << "��������뷽ʽ(0-˳�����)��(1-ָ��λ�ò���):";
			cin >> choose;
			if (choose == 0)
			{
				cout << "������Ҫ�����Ԫ�أ�";
				cin >> e;
				flag = lst.insert(e);
				if (flag)
				{
					cout << "����ɹ��������" << endl;
					lst.print();
				}
				else
				{
					cout << "����ʧ�ܣ�" << endl;
				}
			}
			else if(choose == 1)
			{
				cout << "������Ҫ�����Ԫ�ؼ�λ�ã�";
				cin >> e >> pos;
				flag = lst.insert(e, pos);
				if (flag)
				{
					cout << "����ɹ��������" << endl;
					lst.print();
				}
				else
				{
					cout << "����ʧ�ܣ�" << endl;
				}
			}	
		}
		else if (ch == '1')
		{
			cout << "��������Ҫɾ����Ԫ�ص�λ�ã�";
			cin >> pos;
			flag = lst.del(e, pos);
			if (flag)
			{
				cout << "ɾ���ɹ���ɾ����Ԫ��Ϊ��" << e << ",ɾ����" << endl;
				lst.print();
			}
			else
			{
				cout << "ɾ��ʧ�ܣ�" << endl;
			}
		}
		else if (ch=='2')
		{
			cout << "������������ҵ�λ��:";
			cin >> pos;
			flag=lst.get(e, pos);
			if (flag)
			{
				cout << "˳�����λ��" << pos << "��Ԫ��Ϊ" << e << endl;
			}
		}
		else if (ch == '3')
		{
			cout << "������������ҵ�Ԫ�أ�";
			cin >> e;
			if (lst.find(e))
			{
				pos = lst.find(e);
				cout << e << "Ԫ����˳������λ��Ϊ" << pos << endl;
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