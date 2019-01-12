#include<bits/stdc++.h>
using namespace std;
int m[100][100];//存放m(i,j)对应的值
void Knapsack(int *v,int *w,int c,int n,int m[100][100])//求最优值
{
    int jMax = min(w[n]-1,c);
    for(int j=0;j<=jMax;j++)
        m[n][j]=0;
    for(int j=w[n];j<=c;j++)
        m[n][j] = v[n];
    for(int i=n-1;i>1;i--)
    {
        jMax = min(w[i]-1,c);
        for(int j=0;j<jMax;j++)
            m[i][j] = m[i-1][j];
        for(int j=w[i];j<=c;j++)
            m[i][j] = max(m[i+1][j],m[i+1][j-w[i]]+v[i]);

    }
    m[1][c] = m[2][c];
    if(c>w[1])
        m[1][c] = max(m[1][c],m[2][c-w[1]]+v[1]);//返回最优值
}
void Traceback(int m[100][100],int * w,int c,int n,int *x)
{
    for(int i=1;i<n;i++)
        if(m[i][c]==m[i+1][c])
            x[i]=0;
        else
        {
            x[i]=1;
            c-=w[i];
        }
    x[n] = (m[n][c])?1:0;
}
int main()
{
    int n,c,w[100],v[100];
    int x[100];//存放最优解
    cout<<"依次输物品的个数、背包的容量："<<endl;
    cin>>n>>c;
    cout<<"输入各物品的重量："<<endl;
    for(int i=1;i<=n;i++)
        cin>>w[i];
    cout<<"输入各物品的价值："<<endl;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    Knapsack(v,w,c,n,m);
    Traceback(m,w,c,n,x);
    cout<<"问题的最优解为："<<endl;
    for(int i=1;i<=n;i++)
        cout<<x[i]<<" ";
    cout<<endl;
    cout<<"问题的最优值为："<<endl;
    cout<<m[1][c]<<endl;
    return 0;
}
