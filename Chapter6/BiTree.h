#pragma once
#include "predefine.h"
//�������
struct BiNode
{
	char data;//���ַ�
	BiNode* lchild;
	BiNode* rchild;
	BiNode(char ch, BiNode *lc, BiNode *rc):data(ch),lchild{lc},rchild(rc){}
};
class BiTree
{
public:
	BiTree();
	~BiTree();
	void preOrderTraverse();//��������㷨
	void inOrderTraverse();//��������㷨
	void postOrderTraverse();//��������㷨

	int leafCount() const;//�����޸�,������˼����Ҷ�ӽ��
	int leafCountByTrav() const;//���������˼����Ҷ�ӽ��

	int nodeCount() const;//������˼���������
	int nodeCountByRecu() const;//�ݹ��˼���������
protected:
	void createBiTree(BiNode**);//��һ��ָ���ָ�룬ֻ��*�Ļ����ص��ǿ������ڲ���Ҫ��root����һ���޸ģ����Դ�root�ĵ�ַ
	void _preOrderTraverse(BiNode* pRoot);
	void _inOrderTraverse(BiNode* pRoot);
	void _postOrderTraverse(BiNode* pRoot);
	int _leafCount(BiNode* pRoot) const;
	void _nodeCount(BiNode* pRoot,int& count) const;
	void _leafCountByTrav(BiNode* pRoot,int& count) const;
	int _nodeCountByRecu(BiNode* pRoot) const;
private:
	//������ڵ�
	BiNode *root;
};

