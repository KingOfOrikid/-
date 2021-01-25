#include "BiTree.h"

int main()
{
	cout << "请输入建树(先序)序列：";
	BiTree tr;
	tr.preOrderTraverse();
	tr.inOrderTraverse();
	tr.postOrderTraverse();
	cout << "此二叉树叶子结点的个数是:" << tr.leafCountByTrav() << endl;
	cout << "此二叉树结点的个数是:" << tr.nodeCountByRecu() << endl;
	cout << "此二叉树叶子结点的个数是:" << tr.leafCount() << endl;
	cout << "此二叉树结点的个数是:" << tr.nodeCount() << endl;
	system("pause");
	return 0;
}