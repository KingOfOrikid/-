#pragma once
#include "predefine.h"
//结点类型
struct BiNode
{
	char data;//存字符
	BiNode* lchild;
	BiNode* rchild;
	BiNode(char ch, BiNode *lc, BiNode *rc):data(ch),lchild{lc},rchild(rc){}
};
class BiTree
{
public:
	BiTree();
	~BiTree();
	void preOrderTraverse();//先序遍历算法
	void inOrderTraverse();//中序遍历算法
	void postOrderTraverse();//后序遍历算法

	int leafCount() const;//不能修改,迭代的思想求叶子结点
	int leafCountByTrav() const;//先序遍历的思想求叶子结点

	int nodeCount() const;//遍历的思想求结点个数
	int nodeCountByRecu() const;//递归的思想求结点个数
protected:
	void createBiTree(BiNode**);//传一个指针的指针，只传*的话返回的是拷贝，内部需要对root进行一个修改，所以传root的地址
	void _preOrderTraverse(BiNode* pRoot);
	void _inOrderTraverse(BiNode* pRoot);
	void _postOrderTraverse(BiNode* pRoot);
	int _leafCount(BiNode* pRoot) const;
	void _nodeCount(BiNode* pRoot,int& count) const;
	void _leafCountByTrav(BiNode* pRoot,int& count) const;
	int _nodeCountByRecu(BiNode* pRoot) const;
private:
	//定义根节点
	BiNode *root;
};

