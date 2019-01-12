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
    cout<<"�������������Ʒ������";
    cin>>n;
    cout<<"�����뱳��������";
    cin>>c;
    cout<<"��ֱ�����"<<n<<"����Ʒ��������";
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    cout<<"��ֱ�����"<<n<<"����Ʒ�ļ�ֵ��";
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    cout<<"�����������ɵ�����ֵΪ��"<<Knaspsack()<<endl;
    Traceback();
    cout<<"���Ž�Ϊ��";
    for(int i=1;i<=n;i++){
            cout<<x[i]<<" ";
    }
    return 0;
}
