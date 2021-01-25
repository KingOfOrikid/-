#include "String.h"

int main_StringTest()
{
	String str1("hello");
	String str2(" world");
	str1.print();
	str2.print();
	str1.concat(str2);
	str1.print();
	String str3("hi");
	String str4;
	str4.strcopy(str3);
	str4.print();

	cout << str1.index(str2,0) << endl;
	system("pause");
	return 0;
}