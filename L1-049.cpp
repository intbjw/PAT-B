#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct node
{
	vector<int>q;
	int num;
}ac[105];
int main()
{
	int n,total=0;
	cin>>n;
	int x,y;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		ac[i].num=x*10;
		total+=x*10;
	}
//	cout<<total<<endl;
	int id=1;
	while(total--)
	{
		for(int i=1;i<=n;i++)
		{
			if(ac[i].q.size()!=ac[i].num)
			{				//只剩下一个学校了
				if(ac[i].q.empty()==false&&ac[i].q.back()+1==id)
				{
					ac[i].q.push_back(id+1);
					id+=2;
				}
				else
				{
					ac[i].q.push_back(id);
					id++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<"#"<<i<<endl;
		for(int j=0;j<ac[i].q.size();j++)
		{
			if(j%10==0&&j!=0)cout<<endl;
			if(j%10!=0)cout<<" ";
			cout<<ac[i].q[j];
		}
		cout<<endl;
	}
	return 0;
}
