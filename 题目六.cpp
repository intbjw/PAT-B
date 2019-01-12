#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream cinfile;
	cinfile.open("1.txt",ios::in);
	string a;
	cinfile>>a;
	cinfile.close();
	int flag=0;
	int sum = 0;
	int temp =0,i;
	for(i=0;i<a.length();i++)
    {
        if(a[i]<='9'&&a[i]>='0')
            if(flag==0)
            {
                flag = 1;
                temp+=a[i]-'0';
            }
            else
            {
                temp*=10;
                temp+=a[i]-'0';
            }
        else
        {
            sum += temp;
            flag = 0;
            temp = 0;
        }
    }
    if(a[i-1]>='0'&&a[i-1]<='9')
        sum+=temp;
    cout<<sum<<endl;
	return 0;
}
