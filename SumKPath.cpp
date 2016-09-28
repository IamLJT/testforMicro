/*
题目：输入一个整数和一棵二元树。
从树的根结点开始往下访问一直到叶结点所经过的所有结点形成一条路径。
打印出和与输入整数相等的所有路径。
例如输入整数22 和如下二元树
10
/ \
5 12
/ \
4 7
则打印出两条路径：10, 12 和10, 5, 7。
*/

#include <iostream>
using namespace std;
#define MAX_HEIGHT 100

int flag=0;

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;
};

void printPath(int path[], int top)
{
	printf("%d",path[0]);
	for(int i=1; i<top; i++)
		printf(" %d",path[i]);//	打印路径
	flag++;
	printf("\n");
}

void helper(TreeNode *root, int sum, int path[], int top)
{
	path[top++]=root->data;
	sum-=root->data;
	if(root->left==NULL&&root->right==NULL)
	{
		if(sum==0) 
			printPath(path,top);
	}
	else
	{
		if(root->left!=NULL)
			helper(root->left,sum,path,top);
		if(root->right!=NULL)
			helper(root->right,sum,path,top);
	}
	top--;
	sum+=root->data;	//	形参返回后无任何影响
}

void printPaths(TreeNode *root, int sum)
{
	int path[MAX_HEIGHT];
	helper(root,sum,path,0);
}

TreeNode* addTree(TreeNode *&root, int x)
{
	if(root==NULL)
	{
		root=(TreeNode*)malloc(sizeof(TreeNode));
		if(!root)
		{
			printf("内存分配失败！");
			exit(1);
		}
		root->data=x;
		root->left=root->right=NULL;
	}
	else
	{
		if(x<root->data)
			root->left=addTree(root->left, x);
		else if(x>root->data)
			root->right=addTree(root->right, x);
	}
	return root;
}

int main()
{
	TreeNode* root=NULL;
	int x;
	while(scanf("%d",&x))
		root=addTree(root,x);
	int sum;
	getchar();
	scanf("%d",&sum);
	printPaths(root,sum);
	if(flag==0)
		printf("No Path!\n");
	system("pause");
	return 0;
}