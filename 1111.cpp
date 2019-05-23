#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#define N 31
using namespace std;
long F[N];  
int main(){
    int n;
    memset(F,0,sizeof(F));
    F[0]=0;F[1]=0;F[2]=1;
    for(int i=3;i<N;i++){
        F[i]=(i-1)*(F[i-1]+F[i-2]);
    }
    while(scanf("%d",&n)!=EOF){
        printf("%ld\n",F[n]);
    }
    return 0;
}
