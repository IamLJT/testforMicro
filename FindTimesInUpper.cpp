/*
腾讯面试题：
给你10 分钟时间，根据上排给出十个数，在其下排填出对应的十个数
要求下排每个数都是先前上排那十个数在下排出现的次数。
上排的十个数如下：
【0，1，2，3，4，5，6，7，8，9】
举一个例子，
数值: 0,1,2,3,4,5,6,7,8,9
分配: 6,2,1,0,0,0,1,0,0,0
0 在下排出现了6 次，1 在下排出现了2 次，
2 在下排出现了1 次，3 在下排出现了0 次....
以此类推..

解题思路：关键是理解“要求下排每个数都是先前上排那十个数在下排出现的次数”。

做以下分析：设总共有n个数，上排a[0...n-1],下排b[0...n-1]，。

1）下排n个数的累加和为n，即b[0]+b[1]+...+b[n-1] = n

2）ai*bi的累加和也为n，即a[0]*b[0]+a[1]*b[1]+...+a[n-1]*b[n-1] = n

3）对于b中任意一个元素b[j], 都存在i，a[i] = b[j].

4）对于b中任意一个元素b[j],都有b[j] >= 0

5）如果a中存在负数。其在b中出现的次数一定为0. 如果a中数值大于等于n，则其出现次数也为0.

6）a中至少有两个非0数值在b中出现的次数非0


思路：令A为上排数组，a为下排数组。首先，统计上层数字的个数,总次数应为
SUM(a[i]*A[i])，并且a[i]必须属于A[1-10]，当然总次数也必为SUM(a[i])=10,
而a[i]>=0，且a[i]不可能全部相等，因此必存在a[i]=0，那么A[i]也必有0；
*/