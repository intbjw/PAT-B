#include<bits/stdc++.h>
using namespace std;
int maxSum(int a[],int left, int right)
{
	int sum = 0;
	if(left == right)	//������г���Ϊ1��ֱ�����
	{
		if(a[left] > 0) sum = a[left];
		else sum = 0;
	}
	else
	{
		int center = (left + right) / 2;	//����
		int leftsum = maxSum(a,left,center);	//��Ӧ���1���ݹ����
		int rightsum = maxSum(a, center + 1, right);//��Ӧ���2�� �ݹ����
		int s1 = 0;
		int lefts = 0;
		for(int i = center; i >= left; i--)	//���s1
		{
			lefts += a[i];
			if(lefts > s1) s1 = lefts;	//������ֵ����s1
		}
		int s2 = 0;
		int rights = 0;
		for(int j = center + 1; j <= right; j++)//���s2
		{
			rights += a[j];
			if(rights > s2) s2 =rights;
		}
		sum = s1 + s2;				//�����3�����������Ӷκ�
		if(sum < leftsum) sum = leftsum;	//�ϲ�����sum��leftsum��rightsum��ȡ���ֵ
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
