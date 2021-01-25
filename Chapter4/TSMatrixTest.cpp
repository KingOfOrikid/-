#include "TSMatrix.h"

using namespace std;
int main_TSMatrixTest()
{
	Triple a1;
	a1.row = 1;
	a1.col = 1;
	a1.data = 1;
	Triple a2;
	a2.row = 2;
	a2.col = 3;
	a2.data = 5;
	Triple a3;
	a3.row = 3;
	a3.col = 1;
	a3.data = 3;
	Triple data[] = { a1,a2,a3 };
	TSMatrix ts1(3, 3, 3, data);
	ts1.print();
	cout << "×ªÖÃºó:" << endl;
	TSMatrix ts2;
	ts1.transpose(ts2);
	ts2.print();
	
}