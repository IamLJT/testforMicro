/*
查找最小的k 个元素
题目：输入n 个整数，输出其中最小的k 个。
例如输入1，2，3，4，5，6，7 和8 这8 个数字，则最小的4 个数字为1，2，3 和4。

思路：构建小顶堆，即优先队列，只保留k个值
*/

#include <iostream>
using namespace std;

void swap(int a[], int i, int p)
{
	int temp=a[i];
	a[i]=a[p];
	a[p]=temp;
}

void siftup(int a[], int i, int n)
{
	while(i>0)
	{
		int j=(i&1==0?i-1:i+1);
		int p=(i-1)>>1;
		if(j<n&&a[j]<a[i]) i=j;
		if(a[i]<a[p]) swap(a,i,p);
		i=p;
	}
}

void siftdown(int a[], int i, int n)
{
	while(2*i+1<n)
	{
		int l=2*i+1;
		if(l+1<n&&a[l+1]<a[l]) l++;
		if(a[l]<a[i]) swap(a,i,l);
		i=l;
	}
}

void Build_Min_Heap(int a[], int n)
{
	for(int i=n/2; i>=0; i--)
		siftdown(a,i,n);	//	可以证明，建堆的过程复杂度为O(n)
}

int main()
{
	int a[]={4,7,2,7,3,6,4};
	int n=7;
	int k=3;
	Build_Min_Heap(a,n);
	for(int i=0;i<k;i++)
	{
		printf("%d ",a[0]);
		swap(a,0,n-1);
		n--;
		siftdown(a,0,n);
	}
	//	这个过程是klog(n)
	printf("\n");
	system("pause");
	return 0;
}