/*
��Ŀ��
����һ�ö�Ԫ�����������ö�Ԫ������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ����ָ���ָ��
10
/ \
6 14
/ \ / \
4 8 12 16
ת����˫������
4=6=8=10=12=14=16��
�������Ƕ���Ķ�Ԫ�������ڵ�����ݽṹ���£�
struct BSTreeNode
{
int m_nValue; // value of node
BSTreeNode *m_pLeft; // left child of node
BSTreeNode *m_pRight; // right child of node
};

˼·��ֱ���������һ�飬��¼����һ������λ��
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
			printf("�ڴ����ʧ�ܣ�");
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