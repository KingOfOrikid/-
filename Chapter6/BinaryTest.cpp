#include "BiTree.h"

int main()
{
	cout << "�����뽨��(����)���У�";
	BiTree tr;
	tr.preOrderTraverse();
	tr.inOrderTraverse();
	tr.postOrderTraverse();
	cout << "�˶�����Ҷ�ӽ��ĸ�����:" << tr.leafCountByTrav() << endl;
	cout << "�˶��������ĸ�����:" << tr.nodeCountByRecu() << endl;
	cout << "�˶�����Ҷ�ӽ��ĸ�����:" << tr.leafCount() << endl;
	cout << "�˶��������ĸ�����:" << tr.nodeCount() << endl;
	system("pause");
	return 0;
}