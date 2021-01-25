#include <iostream>
#include <vector>

using namespace std;

const int Max = 5;//定义数组AB的容量最大值
void BubbleSort(int arr[]);
int main()
{
	int ListA[Max];
	int ListB[Max];
	vector<int> ListC;//定义一个无固定容量的数组作为合并后的数组
	int input;
	for (int i = 0; i<Max; i++)
	{
		cout << "请输入A[" << i << "]" << endl;
		cin >> input;
		ListA[i] = input;
	}
	for (int i = 0; i<Max; i++)
	{
		cout << "请输入B[" << i << "]" << endl;
		cin >> input;
		ListB[i] = input;
	}
	BubbleSort(ListA);
	BubbleSort(ListB);
	//对两个数组进行排序
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
	//将未遍历完的数组的所有元素放入C数组
	for (int i = 0; i < ListC.size(); i++)
	{
		cout << ListC[i] << endl;
	}
	//遍历输出合并后的数组
	return 0;
}

/*功能：冒泡排序
  参数：
        arr[]--需要从小到大排序的数组
  返回值：
        无
*/
void BubbleSort(int arr[])
{
	for (int i = 0; i < Max; i++)
	{
		int tump = 0;//定义一个中间量
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