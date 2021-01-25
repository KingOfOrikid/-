#include "Array.h"

using namespace std;

int main()
{
	Array arr(3, 3, 3, 3);
	arr.assign(12, 1, 2, 2);
	int e = 0;
	arr.value(&e, 1, 2, 2);
	cout << e << endl;
	int bound1 = 3;
	int bound2 = 4;
	int bound3 = 5;
	Array arr1(3, bound1, bound2, bound3);
	for (int i = 0; i < bound1; i++)
	{
		for (int j = 0; j < bound2; j++)
		{
			for (int k = 0; k < bound3; k++)
			{
				arr1.assign(i * 100 + j * 10 + k * 1, i, j, k);
				arr1.value(&e, i, j, k);
				cout << "arr1[" << i << "][" << j << "][" << k << "]=" << e << " " << endl;
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}