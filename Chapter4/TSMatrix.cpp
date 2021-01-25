#include "TSMatrix.h"



TSMatrix::TSMatrix()
{
}


TSMatrix::TSMatrix(int m, int n, int t, Triple arr[])
{
	mu = m;
	nu = n;
	tu = t;
	for (int i = 0; i < t; i++)
	{
		data[i] = arr[i];
	}
}

TSMatrix::~TSMatrix()
{
}


Status TSMatrix::transpose(TSMatrix &t)
{
	t.mu = nu;
	t.nu = mu;
	t.tu = tu;

	if (t.tu)
	{
		int q = 0;//ת�ú�t����ı���λ��
		for (int col = 1; col <= nu; col++)
		{
			for (int p = 0; p < tu; p++)
			{
				if (data[p].col == col)
				{
					//ת��
					t.data[q].row = data[p].col;
					t.data[q].col = data[p].row;
					t.data[q].data = data[p].data;
					q++;

				}
			}
		}
	}

	return OK;
}

void TSMatrix::print()
{
	for (int row = 1; row <= mu; row++)
	{
		for (int col = 1; col <= nu; col++)
		{
			//��������Ԫ;���±�Ϊ(row,col)�ķ���Ԫ�Ƿ����
			int k = 0;
			for (k = 0; k < tu; k++)
			{
				if (row == data[k].row&&col == data[k].col)
				{
					cout << data[k].data << " ";
					break;
				}
			}
			if (k==tu)
			{
				cout << "0 ";
			}
		}
		cout << endl;
	}
}