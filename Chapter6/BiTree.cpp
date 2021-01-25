#include "BiTree.h"



BiTree::BiTree()
{
	createBiTree(&root);
}


BiTree::~BiTree()
{
}

//利用先序遍历思想建立二叉树，采用的方法是二叉链表
void BiTree::createBiTree(BiNode **pRoot)//指向指针的地址
{
	char ch;
	cin >> ch;//输入一个字符序列
	if (ch == '#')
	{
		pRoot = NULL;//当前二叉树为空
	}
	else
	{
		//不为空的话建立根节点
		*pRoot = new BiNode(ch, NULL, NULL);
		if (*pRoot != NULL)
		{
			//如果分配不失败
			createBiTree(&(*pRoot)->lchild);//建立左子树
			createBiTree(&(*pRoot)->rchild);//建立右子树
		}
		else
		{
			//分配失败退出
			exit(OVERFLOW);
		}
	}
}

void BiTree::preOrderTraverse()
{
	cout << "先序输出的二叉树为:";
	_preOrderTraverse(root);
	cout << endl;
}

//利用先序遍历思想输出二叉树
void BiTree::_preOrderTraverse(BiNode* pRoot)
{
	if (pRoot != NULL)
	{
		//访问根节点
		cout << pRoot->data;
		//先序遍历左子树
		_preOrderTraverse(pRoot->lchild);
		//先序遍历右子树
		_preOrderTraverse(pRoot->rchild);
	}
}

void BiTree::inOrderTraverse()
{
	cout << "中序输出的二叉树为:";
	_inOrderTraverse(root);
	cout << endl;
}

//利用中序遍历思想输出二叉树
void BiTree::_inOrderTraverse(BiNode* pRoot)
{
	if (pRoot != NULL)
	{
		//先序遍历左子树
		_inOrderTraverse(pRoot->lchild);
		//访问根节点
		cout << pRoot->data;
		//先序遍历右子树
		_inOrderTraverse(pRoot->rchild);
	}
}

void BiTree::postOrderTraverse()
{
	cout << "后序输出的二叉树为:";
	_postOrderTraverse(root);
	cout << endl;
}

//利用后序遍历思想输出二叉树
void BiTree::_postOrderTraverse(BiNode* pRoot)
{
	if (pRoot != NULL)
	{
		//先序遍历左子树
		_postOrderTraverse(pRoot->lchild);
		//先序遍历右子树
		_postOrderTraverse(pRoot->rchild);
		//访问根节点
		cout << pRoot->data;
	}
}

int BiTree::leafCount() const
{
	return _leafCount(root);
}

//递归统计叶子结点的个数
int BiTree::_leafCount(BiNode* pRoot) const
{
	//如果当前节点为NULL
	if (pRoot == NULL)
	{
		return 0;
	}
	//判断叶子结点
	if (pRoot->lchild == NULL&&pRoot->rchild == NULL)
	{
		return 1;
	}
	//叶子结点的个数是左子树上叶子结点的个数和右子树上叶子结点的个数之和
	return _leafCount(pRoot->lchild) + _leafCount(pRoot->rchild);
}

int BiTree::leafCountByTrav() const
{
	int count = 0;
	_leafCountByTrav(root, count);
	return count;
}

//自行实现，利用先序遍历的思想求叶子结点leafCountByTrav
void BiTree::_leafCountByTrav(BiNode* pRoot,int& count) const
{
	//如果根结点不为空的话
	if (pRoot != NULL)
	{
		if (pRoot->lchild == NULL&&pRoot->rchild == NULL)
		{
			//为叶结点则计数器加1
			count += 1;
		}
		//先序遍历左右子树
		_leafCountByTrav(pRoot->lchild, count);
		_leafCountByTrav(pRoot->rchild, count);
	}
	else
	{
		count += 0;
	}
}

int BiTree::nodeCount() const
{
	int count = 0;
	_nodeCount(root, count);
	return count;
}

//遍历统计结点个数
void BiTree::_nodeCount(BiNode* pRoot, int& count) const
{
	if (pRoot != NULL)
	{
		//后序遍历求左子树上的结点
		_nodeCount(pRoot->lchild, count);
		//后序遍历求右子树上的结点
		_nodeCount(pRoot->rchild, count);
		//访问根结点
		count++;
	}
}

int BiTree::nodeCountByRecu() const
{
	return _nodeCountByRecu(root);
}

//递归统计结点个数
int BiTree::_nodeCountByRecu(BiNode* pRoot) const
{
	if (pRoot != NULL)
	{
		//如果此结点不为空，那就递归它的左右子树并在总数上加1
		return _nodeCountByRecu(pRoot->lchild) + _nodeCountByRecu(pRoot->rchild) + 1;
	}
	else
	{
		return 0;
	}
	
}