#include "LinkList.h"
Status isNum(string str);

int main_Test_2()
{
	int a[5] = { 11,34,56,32,68 };
	Status flag;
	LinkList linklst(a,5);//ʹ�������ʼ��һ��˳������
	int e, pos;
	while (true)
	{
		cout << "����������ִ�еĲ���(0-����)��(1-ɾ��)��(2-����λ��)��(3-����Ԫ��)��(4-������)��(5-������������)��(6-����������)��(9-�˳�):";
		char ch;
		cin >> ch;
		//���뷽��������ѡ��˳������λ�ò���
		if (ch == '0')
		{
			int choose;
			cout << "��������뷽ʽ(0-˳�����)��(1-ָ��λ�ò���):";
			cin >> choose;
			if (choose == 0)
			{
				cout << "������Ҫ�����Ԫ�أ�";
				cin >> e;
				flag = linklst.insert(e);
				if (flag)
				{
				cout << "����ɹ��������" << endl;
				linklst.print();
				}
				else
				{
				cout << "����ʧ�ܣ�" << endl;
				}
			}
			else if (choose == 1)
			{
				cout << "������Ҫ�����Ԫ�ؼ�λ�ã�";
				cin >> e >> pos;
				flag = linklst.insert(e, pos);
				if (flag)
				{
					cout << "����ɹ��������" << endl;
					linklst.print();
				}
				else
				{
					cout << "����ʧ�ܣ�" << endl;
				}
			}
		}
		//�����û�����λ��ɾ��ĳ��Ԫ��
		else if (ch == '1')
		{
			cout << "��������Ҫɾ����Ԫ�ص�λ�ã�";
			cin >> pos;
			flag = linklst.del(e, pos);
			if (flag)
			{
				cout << "ɾ���ɹ���ɾ����Ԫ��Ϊ��" << e << ",ɾ����" << endl;
				linklst.print();
			}
			else
			{
				cout << "ɾ��ʧ�ܣ�" << endl;
			}
		}
		//����ĳԪ���Ƿ��������У�����������һ��λ��
		else if (ch=='3')
		{
			string input="1";
			while (isNum(input))
			{
				cout << "��������Ҫ���ҵ�Ԫ�أ�" ;
				cin >> input;
				if (isNum(input))
				{
					stringstream st;
					st << input;
					st >> e;
					if (linklst.find(e) != 0)
					{
						int pos = linklst.find(e);
						cout << e << "Ԫ�������������ڵ�λ��Ϊ��" << pos << "��" << endl;
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
		//����λ�ò���������λ�ڴ�λ�õ�Ԫ��
		else if (ch == '2')
		{
			string input = "1";
			while (isNum(input))
			{
				cout << "��������Ҫ���ҵ�λ�ã�";
				cin >> input;
				if (isNum(input))
				{
					stringstream st;
					st << input;
					st >> pos;
					if (linklst.get(e,pos) != 0)
					{
						cout << "������λ��" << pos << "λ�õ�Ԫ��Ϊ" << e << endl;
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
		//���Ŀǰ����ĳ���
		else if (ch == '4')
		{
			cout << "����������Ϊ��" << linklst.length() << endl;
		}
		//���Ŀǰ�����е�Ԫ��
		else if (ch == '5')
		{
			linklst.print();

		}
		//��������������ԭ������
		else if (ch == '6')
		{
			string input = "1";
			while (isNum(input))
			{
				cout << "������Ҫ��������Ĵ�С��";
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