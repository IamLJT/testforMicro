/*
题目：
输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。
要求不能创建任何新的结点，只调整指针的指向。
10
/ \
6 14
/ \ / \
4 8 12 16
转换成双向链表
4=6=8=10=12=14=16。
首先我们定义的二元查找树节点的数据结构如下：
struct BSTreeNode
{
int m_nValue; // value of node
BSTreeNode *m_pLeft; // left child of node
BSTreeNode *m_pRight; // right child of node
};

思路：直接中序遍历一遍，记录好上一个结点的位置
*/

#include <iostream>
using namespace std;

struct BSTreeNode
{
	int m_nValue;
	BSTreeNode *m_pLeft;
	BSTreeNode *m_pRight;
};

void helper(BSTreeNode *&head, BSTreeNode *&tail, BSTreeNode *&root)
{
	BSTreeNode *it, *rh;
	if(root==NULL)
	{
		head=NULL, tail=NULL;
		return;
	}
	helper(head, it, root->m_pLeft);
	helper(rh, tail, root->m_pRight);
	if(it!=NULL)
	{
		it->m_pRight=root;
		root->m_pLeft=it;
	}
	else
		head=root;
	if(rh!=NULL)
	{
		root->m_pRight=rh;
		rh->m_pLeft=root;
	}
	else
		tail=root;
}

BSTreeNode* treeLinkedList(BSTreeNode *root)
{
	BSTreeNode *head, *tail;
	helper(head, tail, root);
	return head;
}

BSTreeNode* addTree(BSTreeNode *&root, int x)
{
	if(root==NULL)
	{
		root=(BSTreeNode*)malloc(sizeof(BSTreeNode));
		if(!root)
		{
			printf("内存分配失败！");
			exit(1);
		}
		root->m_nValue=x;
		root->m_pLeft=root->m_pRight=NULL;
	}
	else
	{
		if(x<root->m_nValue)
			root->m_pLeft=addTree(root->m_pLeft, x);
		else if(x>root->m_nValue)
			root->m_pRight=addTree(root->m_pRight, x);
	}
	return root;
}

int main()
{
	BSTreeNode *root=NULL,*res=NULL;
	int x;
	while(scanf("%d",&x))
		root=addTree(root,x);
	res=treeLinkedList(root);
	system("pause");
	return 0;
}