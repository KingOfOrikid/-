#include <iostream>
#include <vector>

using namespace std;

const int Max = 5;//��������AB���������ֵ
void BubbleSort(int arr[]);
int main()
{
	int ListA[Max];
	int ListB[Max];
	vector<int> ListC;//����һ���޹̶�������������Ϊ�ϲ��������
	int input;
	for (int i = 0; i<Max; i++)
	{
		cout << "������A[" << i << "]" << endl;
		cin >> input;
		ListA[i] = input;
	}
	for (int i = 0; i<Max; i++)
	{
		cout << "������B[" << i << "]" << endl;
		cin >> input;
		ListB[i] = input;
	}
	BubbleSort(ListA);
	BubbleSort(ListB);
	//�����������������
	int i = 0;
	int j = 0;
	while ((i<Max) && (j<Max))
	{
		if (ListA[i] <= ListB[j])
		{
			ListC.push_back(ListA[i]);
			i++;
		}
		else
		{
			ListC.push_back(ListB[j]);
			j++;
		}

	}
	if (i < Max)
	{
		for (int a = i; a < Max; a++)
		{
			ListC.push_back(ListA[a]);
			i++;
		}
	}
	if (j < Max)
	{
		for (int b = j; b < Max; b++)
		{
			ListC.push_back(ListB[b]);
			j++;
		}
	}
	//��δ����������������Ԫ�ط���C����
	for (int i = 0; i < ListC.size(); i++)
	{
		cout << ListC[i] << endl;
	}
	//��������ϲ��������
	return 0;
}

/*���ܣ�ð������
  ������
        arr[]--��Ҫ��С�������������
  ����ֵ��
        ��
*/
void BubbleSort(int arr[])
{
	for (int i = 0; i < Max; i++)
	{
		int tump = 0;//����һ���м���
		for (int j = i + 1; j < Max; j++)
		{
			if (arr[j] <= arr[i])
			{
				tump = arr[i];
				arr[i] = arr[j];
				arr[j] = tump;
			}
		}
	}
}