#include<iostream>
using namespace std;
int cw=0,bestw=0,n,i,c;
int w[40],bestx[40],b[40];
void backtrack(int t)
{
  if(t>n)
   {
     if(bestw<cw)bestw=cw;
     return ;
   }
   if(cw+w[t]<=c)
   {
   cw+=w[t];
   backtrack(t+1);
   cw-=w[t];
   }
  backtrack(t+1);
}

int main()
{
   cin>>n>>c;
    bestw=0;
   for(i=0;i<n;i++)
       cin>>w[i];
   backtrack(0);
   cout<<bestw<<endl;
}
