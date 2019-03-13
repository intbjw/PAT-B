#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        int temp;
        temp = k*k;
        for(int j=1;j<10;j++)
        {
            int temp0,l=10,flag=0;
            temp0 = temp*j;
            while(1)
            {
                if(k==temp0%l)
                {
                    cout<<j<<" "<<temp0<<endl;
                    flag=1;
                    break;
                }
                l*=10;
                if(k<temp%l)
                    break;
            }
            if(flag==1)
                break;
            if(j==9)
                cout<<"no"<<endl;

        }
    }

    return 0;
}
