#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int a[1000];
	cin>>n;
	for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(i==1)
            cout<<(a[i]+a[i+1])/2;
        else if(i==n)
            cout<<" "<<(a[i]+a[i-1])/2;
        else
            cout<<" "<<(a[i+1]+a[i]+a[i-1])/3;

    }
	return 0;
}
