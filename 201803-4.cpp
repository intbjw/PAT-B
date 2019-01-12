#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int graph[5][5];

int judge()//是否结束，返回赢家
{
    for(int i = 0; i < 3; i++)if(graph[0][i] != 0 && graph[0][i] == graph[1][i] && graph[2][i] == graph[0][i])return graph[0][i];
    for(int i = 0; i < 3; i++)if(graph[i][0] != 0 && graph[i][0] == graph[i][1] && graph[i][2] == graph[i][0])return graph[i][0];
    if(graph[0][0] != 0 && graph[0][0] == graph[1][1] && graph[0][0] == graph[2][2])return graph[0][0];
    if(graph[2][0] != 0 && graph[2][0] == graph[1][1] && graph[2][0] == graph[0][2])return graph[2][0];
    return 0;
}

int getdonow()//当前空格子数
{
    int cnt = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(graph[i][j] == 0)cnt++;
        }
    }
    return cnt;
}

int dfs(int donow)
{
    int person = donow % 2;//当前操作者
    if(person == 0)person = 2;
    if(judge() != 0)return person == 2? donow+1 : -donow-1;//此时已结束，有赢家
    if(donow == 0)return 0;//此时已结束，平局
    int retmax = -100, retmin = 100;//完全可以合成一个写
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(graph[i][j] == 0){
                graph[i][j] = person;//准备下一步递归
                if(person == 1)retmax = max(retmax, dfs(donow-1));//max
                else retmin = min(retmin, dfs(donow-1));//min
                graph[i][j] = 0;//回溯
            }
        }
    }
    if(person == 1)return retmax;
    else return retmin;
}

int main()
{
    int T;
    int flag;
    int donow;
    scanf("%d", &T);
    while(T--)
    {
        memset(graph, 0, sizeof(graph));
        for(int i = 0; i < 3; i++)
        {
            scanf("%d%d%d", &graph[i][0], &graph[i][1], &graph[i][2]);
        }
        donow = getdonow();
        int ans = dfs(donow);
        if(ans > 0 && ans % 2 == 0)ans++;//如果题目严谨，没有什么用
        else if(ans < 0 && ans % 2 == 1)ans --;
        printf("%d\n", ans);

    }
    return 0;
}
