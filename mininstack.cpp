/*
题目：定义栈的数据结构，要求添加一个min 函数，能够得到栈的最小元素。
要求函数min、push 以及pop 的时间复杂度都是O(1)。
*/

#include <iostream>
using namespace std;

struct MinStackElement
{
	int data;
	int min;
};

struct MinStack
{
	MinStackElement* data;
	int size;
	int top;
};

MinStack MinStackInit(int maxSize)
{
	MinStack stack;
	stack.size=maxSize;
	stack.data=(MinStackElement*)malloc(sizeof(MinStackElement)*maxSize);
	stack.top=0;
	return stack;
}

void MinStackFree(MinStack stack)
{
	free(stack.data);
}

void MinStackPush(MinStack& stack, int d)
{
	if(stack.top==stack.size)
	{
		printf("out of stack space");
		return;
	}
	MinStackElement *p=&stack.data[stack.top];
	p->data=d;
	p->min=(stack.top==0?d:stack.data[stack.top-1].min);
	if(p->min>d)
		p->min=d;
	stack.top++;
}

int MinStackPop(MinStack& stack)
{
	if(stack.top==0) {printf("stack is empty\n");return -1;}
	return stack.data[--stack.top].data;
}

int MinStackMin(MinStack stack)
{
	if(stack.top==0) {printf("stack is empty\n");return -1;}
	return stack.data[stack.top-1].min;
}

void ShowText()
{
	printf("\tpress 1 to push number\n"
		"\tpress 2 to pop number\n"
		"\tpress 3 to show min number\n"
		"\tpress 4 to quit\n");
}

void main()
{
	MinStack stack=MinStackInit(10);
	ShowText();
	int x;
	while(scanf("%d",&x))
	{
		switch (x)
		{
		case 1:
			int n;
			scanf("%d",&n);
			MinStackPush(stack,n);
			break;
		case 2:
			if(MinStackPop(stack)!=-1)
				printf("%d\n", MinStackPop(stack));
			break;
		case 3:
			if(MinStackMin(stack)!=-1)
				printf("%d\n", MinStackMin(stack));
			break;
		default:
			MinStackFree(stack);
			return;
		}
	}
}