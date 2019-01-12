//用vector来存储不定长数组，节省空间
//dfs遍历，用map[][]来记录任意两点的连通性
//数字规模：1000
#include<iostream>
#include<vector>
using namespace std;

int map[1001][1001];//0表示不同，1表示相通
vector<int> path[1001];//每个点跟着一串不定数量的相连点

void dfs(int a,int visit[],int b){//已知有向路径 a->b
    visit[a]=1;
    map[a][b]=1;
    map[b][a]=1;
    for(int i=0;i<path[a].size();i++){//遍历所有与a相连的未被访问过的点
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
        path[a].push_back(b);//b在a的相连点串中
    }
    for(i=1;i<=n;i++){
        int visit[1001]={0};//每个点开始的遍历都要扩展到整张图 ,填图时记录是否访问过某点
        dfs(i,visit,i);//到自身存在有向路径，作为起始状态
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(map[i][j]==0)//i->j不通
            break;
        }
        if(j==n+1)//i与所有j相通
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
