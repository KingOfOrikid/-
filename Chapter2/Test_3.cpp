#include "Polynomial.h"

int main()
{
	char choose;
	vector<float> c1,c2;
	vector<int> e1,e2;
	while (true)
	{
		cout << "请选择你要进行的操作(1-相加)、(2-相乘)、(其他-退出):";
		cin >> choose;
		if (choose=='1')
		{
			Polynomial p1, p2;
			int len1, len2;
			cout << "请输入第一个多项式的项数:";
			cin >> len1;
			int temp = 0;
			for (int i = 0; i < len1; i++)
			{
				cout << "请输入第" << i + 1 << "项的系数:";
				cin >> temp;
				c1.push_back(temp);
			}
			for (int i = 0; i < len1; i++)
			{
				cout << "请输入第" << i + 1 << "项的指数:";
				cin >> temp;
				e1.push_back(temp);
			}
			float *bufferC1 = new float[sizeof(c1)];
			if (!c1.empty())
			{
				memcpy(bufferC1, &c1[0], c1.size() * sizeof(float));
			}
			int *bufferE1 = new int[sizeof(e1)];
			if (!e1.empty())
			{
				memcpy(bufferE1, &e1[0], e1.size() * sizeof(int));
			}
			p1.create(bufferC1, bufferE1, c1.size(), e1.size());
			p1.print();

			cout << "请输入第二个多项式的项数:";
			cin >> len2;
			temp = 0;
			for (int i = 0; i < len2; i++)
			{
				cout << "请输入第" << i + 1 << "项的系数:";
				cin >> temp;
				c2.push_back(temp);
			}
			for (int i = 0; i < len2; i++)
			{
				cout << "请输入第" << i + 1 << "项的指数:";
				cin >> temp;
				e2.push_back(temp);
			}
			float *bufferC2 = new float[sizeof(c2)];
			if (!c2.empty())
			{
				memcpy(bufferC2, &c2[0], c2.size() * sizeof(float));
			}
			int *bufferE2 = new int[sizeof(e2)];
			if (!e2.empty())
			{
				memcpy(bufferE2, &e2[0], e2.size() * sizeof(int));
			}
			p2.create(bufferC2, bufferE2, c2.size(), e2.size());
			p2.print();

			p1.plus(p1, p2);
			cout << "相加的结果为：";
			p1.print();
			system("pause");
		}
		else if (choose == '2')
		{
			Polynomial p1, p2, p3;
			int len1, len2;
			cout << "请输入第一个多项式的项数:";
			cin >> len1;
			int temp = 0;
			for (int i = 0; i < len1; i++)
			{
				cout << "请输入第" << i + 1 << "项的系数:";
				cin >> temp;
				c1.push_back(temp);
			}
			for (int i = 0; i < len1; i++)
			{
				cout << "请输入第" << i + 1 << "项的指数:";
				cin >> temp;
				e1.push_back(temp);
			}
			float *bufferC1 = new float[sizeof(c1)];
			if (!c1.empty())
			{
				memcpy(bufferC1, &c1[0], c1.size() * sizeof(float));
			}
			int *bufferE1 = new int[sizeof(e1)];
			if (!e1.empty())
			{
				memcpy(bufferE1, &e1[0], e1.size() * sizeof(int));
			}
			p1.create(bufferC1, bufferE1, c1.size(), e1.size());
			p1.print();

			cout << "请输入第二个多项式的项数:";
			cin >> len2;
			temp = 0;
			for (int i = 0; i < len2; i++)
			{
				cout << "请输入第" << i + 1 << "项的系数:";
				cin >> temp;
				c2.push_back(temp);
			}
			for (int i = 0; i < len2; i++)
			{
				cout << "请输入第" << i + 1 << "项的指数:";
				cin >> temp;
				e2.push_back(temp);
			}
			float *bufferC2 = new float[sizeof(c2)];
			if (!c2.empty())
			{
				memcpy(bufferC2, &c2[0], c2.size() * sizeof(float));
			}
			int *bufferE2 = new int[sizeof(e2)];
			if (!e2.empty())
			{
				memcpy(bufferE2, &e2[0], e2.size() * sizeof(int));
			}
			p2.create(bufferC2, bufferE2, c2.size(), e2.size());
			p2.print();

			p3.mulp(p1, p2);
			cout << "相乘的结果为:";
			p3.print();
			system("pause");
		}
		else
		{
			break;
		}
	}
	system("pause");
	return 0;
}