#include <iostream>
using namespace std;
int main()
{
    string mingwen;
    int miyao[10];
    int h,n;
    cout <<"请输入要加密的明文\n" <<endl;
    cin >>mingwen;
    cout <<"请输入密钥长度\n" <<endl;
    cin >>n;
    // cout <<"请输入密钥\n" <<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cin >>miyao[i];
    // }
    int l=mingwen.size();
    if(l%n!=0)
        {
            h=l/n+1;
        }
    else
        {
            h=l/n;
        }
    for (int i = 0; i < n-(l%n); i++) {
      mingwen+='@';
    }
    // std::cout << n << '\n';
    // std::cout << h << '\n';
    int jz[n][h];
    for(int j=0;j<h;j++)
        {
            for(int k=0;k<n;k++)
            {
                //jz[j][k]==mingwen[j*n+k];
                cout << mingwen[j+k*h];
            }
            cout << " ";
        }

     // for(int m=1;m<=n;m++)
     // {
     //     for(int p=0;p<n;p++)
     //     {
     //         if(miyao[p]==m)
     //         {
     //             for(int z=0;z<h;z++)
     //             {
     //                 cout <<jz[z][p]<<endl;
     //             }
     //         }
     //     }
     // }
     // if(n*h-l!=0)
     // {
     //     for(int b=0;b<n*h-l;b++)
     //     {
     //         cout <<"@" <<endl;
     //     }
     // }
     return 0;

}
