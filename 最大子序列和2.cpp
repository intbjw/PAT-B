#include<bits/stdc++.h>
using namespace std;
int maxSum(int a[],int left, int right)
{
	int sum = 0;
	if(left == right)	//如果序列长度为1，直接求解
	{
		if(a[left] > 0) sum = a[left];
		else sum = 0;
	}
	else
	{
		int center = (left + right) / 2;	//划分
		int leftsum = maxSum(a,left,center);	//对应情况1，递归求解
		int rightsum = maxSum(a, center + 1, right);//对应情况2， 递归求解
		int s1 = 0;
		int lefts = 0;
		for(int i = center; i >= left; i--)	//求解s1
		{
			lefts += a[i];
			if(lefts > s1) s1 = lefts;	//左边最大值放在s1
		}
		int s2 = 0;
		int rights = 0;
		for(int j = center + 1; j <= right; j++)//求解s2
		{
			rights += a[j];
			if(rights > s2) s2 =rights;
		}
		sum = s1 + s2;				//计算第3钟情况的最大子段和
		if(sum < leftsum) sum = leftsum;	//合并，在sum、leftsum、rightsum中取最大值
		if(sum < rightsum) sum = rightsum;
	}
	return sum;
}
int main()
{
    int n;
    int a[100];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int sum;
    sum = maxSum(a,1,n);
    printf("%d",sum);
    return 0;
}
