#include "HString.h"

int main_HStringTest()
{
	/*HString s1("cyx18076014");
	HString s2("xy18076016");
	s1.print();
	s2.print();
	HString s3;
	s3.concat(s1, s2);
	s3.print();
	s3.del(3, 4);
	s3.print();
	HString t("xxx");
	s1.insert(4, t);
	s1.print();
	cout << s1.index(t, 0) << endl;
	HString temp;
	s1.substring(temp, 0, 3);
	temp.print();
	HString a("ABABABABD");
	HString b("ABABD");
	b.print();
	cout << a.index_kmp(b) << endl;*/

	HString s1("abxyabdabcdabcde");
	HString s2("xyabcdabxycdxy");
	HString s3;
	s3.ComMAXSubstring(s1, s2);
	system("pause");
	return 0;
}