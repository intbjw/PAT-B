//��vector���洢���������飬��ʡ�ռ�
//dfs��������map[][]����¼�����������ͨ��
//���ֹ�ģ��1000
#include<iostream>
#include<vector>
using namespace std;

int map[1001][1001];//0��ʾ��ͬ��1��ʾ��ͨ
vector<int> path[1001];//ÿ�������һ������������������

void dfs(int a,int visit[],int b){//��֪����·�� a->b
    visit[a]=1;
    map[a][b]=1;
    map[b][a]=1;
    for(int i=0;i<path[a].size();i++){//����������a������δ�����ʹ��ĵ�
         if(visit[path[a][i]]==0){
             dfs(path[a][i],visit,b);
         }
    }
}

int main(){
    int n,m,i,j,a,b,cnt=0;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>a>>b;
        path[a].push_back(b);//b��a�������㴮��
    }
    for(i=1;i<=n;i++){
        int visit[1001]={0};//ÿ���㿪ʼ�ı�����Ҫ��չ������ͼ ,��ͼʱ��¼�Ƿ���ʹ�ĳ��
        dfs(i,visit,i);//�������������·������Ϊ��ʼ״̬
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(map[i][j]==0)//i->j��ͨ
            break;
        }
        if(j==n+1)//i������j��ͨ
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
