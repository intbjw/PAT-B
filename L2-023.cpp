#include<stdio.h>
#include<set>
#include<string.h>
using namespace std;
int Map[510][510];
int visited[510];
int a[510],n,flag;
void DFS()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(Map[i][j]==1&&a[i]==a[j])
            {
                flag=1;
                break;
            }
        }
    }
}
int main()
{
    int i,j,m,k,t,x,y;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        Map[x][y]=Map[y][x]=1;
    }
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        memset(visited,0,sizeof(visited));
        flag=0;
        set<int> s;
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[j]);
            s.insert(a[j]);
        }
        if(s.size()!=k)
        {
            printf("No\n");
        }
        else
        {
            DFS();
            if(flag==0)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}
