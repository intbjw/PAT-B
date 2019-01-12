#include <bits/stdc++.h>
using namespace std;
int n,c;
int w[100];
int v[100];
int m[100][100];
int x[100];

int Knaspsack()
{
    for(int i=0;i<=n;i++){
        m[i][0] = 0;
    }
    for(int i=0;i<=c;i++){
        m[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++){
            if(j<w[i]){
                m[i][j] = m[i-1][j];
            }else{
                m[i][j] = max(m[i-1][j],m[i-1][j-w[i]]+v[i]);
            }
        }
    }
    return m[n][c];
}

void Traceback()
{
    for(int i=1;i<n;i++){
        int j = fabs(6-i);
        if(m[i][c]==m[i+1][c]){
            x[j] = 0;
        }else{
            x[j] = 1;
            c -= w[j];
        }
    }
    if(m[n][c]){
        x[1] = 1;
    }else{
        x[1] = 0;
    }
}

int main()
{
    cout<<"请输入待放入物品数量：";
    cin>>n;
    cout<<"请输入背包容量：";
    cin>>c;
    cout<<"请分别输入"<<n<<"种物品的重量：";
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    cout<<"请分别输入"<<n<<"种物品的价值：";
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    cout<<"背包可以容纳的最大价值为："<<Knaspsack()<<endl;
    Traceback();
    cout<<"最优解为：";
    for(int i=1;i<=n;i++){
            cout<<x[i]<<" ";
    }
    return 0;
}
