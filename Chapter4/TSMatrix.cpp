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
		int q = 0;//转置后t矩阵的保存位置
		for (int col = 1; col <= nu; col++)
		{
			for (int p = 0; p < tu; p++)
			{
				if (data[p].col == col)
				{
					//转置
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
			//遍历非零元;找下标为(row,col)的非零元是否存在
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