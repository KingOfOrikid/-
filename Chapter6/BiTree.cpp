#include "BiTree.h"



BiTree::BiTree()
{
	createBiTree(&root);
}


BiTree::~BiTree()
{
}

//�����������˼�뽨�������������õķ����Ƕ�������
void BiTree::createBiTree(BiNode **pRoot)//ָ��ָ��ĵ�ַ
{
	char ch;
	cin >> ch;//����һ���ַ�����
	if (ch == '#')
	{
		pRoot = NULL;//��ǰ������Ϊ��
	}
	else
	{
		//��Ϊ�յĻ��������ڵ�
		*pRoot = new BiNode(ch, NULL, NULL);
		if (*pRoot != NULL)
		{
			//������䲻ʧ��
			createBiTree(&(*pRoot)->lchild);//����������
			createBiTree(&(*pRoot)->rchild);//����������
		}
		else
		{
			//����ʧ���˳�
			exit(OVERFLOW);
		}
	}
}

void BiTree::preOrderTraverse()
{
	cout << "��������Ķ�����Ϊ:";
	_preOrderTraverse(root);
	cout << endl;
}

//�����������˼�����������
void BiTree::_preOrderTraverse(BiNode* pRoot)
{
	if (pRoot != NULL)
	{
		//���ʸ��ڵ�
		cout << pRoot->data;
		//�������������
		_preOrderTraverse(pRoot->lchild);
		//�������������
		_preOrderTraverse(pRoot->rchild);
	}
}

void BiTree::inOrderTraverse()
{
	cout << "��������Ķ�����Ϊ:";
	_inOrderTraverse(root);
	cout << endl;
}

//�����������˼�����������
void BiTree::_inOrderTraverse(BiNode* pRoot)
{
	if (pRoot != NULL)
	{
		//�������������
		_inOrderTraverse(pRoot->lchild);
		//���ʸ��ڵ�
		cout << pRoot->data;
		//�������������
		_inOrderTraverse(pRoot->rchild);
	}
}

void BiTree::postOrderTraverse()
{
	cout << "��������Ķ�����Ϊ:";
	_postOrderTraverse(root);
	cout << endl;
}

//���ú������˼�����������
void BiTree::_postOrderTraverse(BiNode* pRoot)
{
	if (pRoot != NULL)
	{
		//�������������
		_postOrderTraverse(pRoot->lchild);
		//�������������
		_postOrderTraverse(pRoot->rchild);
		//���ʸ��ڵ�
		cout << pRoot->data;
	}
}

int BiTree::leafCount() const
{
	return _leafCount(root);
}

//�ݹ�ͳ��Ҷ�ӽ��ĸ���
int BiTree::_leafCount(BiNode* pRoot) const
{
	//�����ǰ�ڵ�ΪNULL
	if (pRoot == NULL)
	{
		return 0;
	}
	//�ж�Ҷ�ӽ��
	if (pRoot->lchild == NULL&&pRoot->rchild == NULL)
	{
		return 1;
	}
	//Ҷ�ӽ��ĸ�������������Ҷ�ӽ��ĸ�������������Ҷ�ӽ��ĸ���֮��
	return _leafCount(pRoot->lchild) + _leafCount(pRoot->rchild);
}

int BiTree::leafCountByTrav() const
{
	int count = 0;
	_leafCountByTrav(root, count);
	return count;
}

//����ʵ�֣��������������˼����Ҷ�ӽ��leafCountByTrav
void BiTree::_leafCountByTrav(BiNode* pRoot,int& count) const
{
	//�������㲻Ϊ�յĻ�
	if (pRoot != NULL)
	{
		if (pRoot->lchild == NULL&&pRoot->rchild == NULL)
		{
			//ΪҶ������������1
			count += 1;
		}
		//���������������
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

//����ͳ�ƽ�����
void BiTree::_nodeCount(BiNode* pRoot, int& count) const
{
	if (pRoot != NULL)
	{
		//����������������ϵĽ��
		_nodeCount(pRoot->lchild, count);
		//����������������ϵĽ��
		_nodeCount(pRoot->rchild, count);
		//���ʸ����
		count++;
	}
}

int BiTree::nodeCountByRecu() const
{
	return _nodeCountByRecu(root);
}

//�ݹ�ͳ�ƽ�����
int BiTree::_nodeCountByRecu(BiNode* pRoot) const
{
	if (pRoot != NULL)
	{
		//����˽�㲻Ϊ�գ��Ǿ͵ݹ����������������������ϼ�1
		return _nodeCountByRecu(pRoot->lchild) + _nodeCountByRecu(pRoot->rchild) + 1;
	}
	else
	{
		return 0;
	}
	
}