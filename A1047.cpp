#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
 
typedef struct Student 
{
	char name[20];
}Student;
std::vector<Student> sVec;
 
bool cmp(int s1, int s2)
{
	return strcmp(sVec[s1].name, sVec[s2].name) < 0;
}
int main()
{
	int s, c;
	while(scanf("%d%d",&s,&c)!=EOF)
	{
		std::vector<std::vector<int>> cVec(c);
		sVec.resize(s);
		//input 
		for(int i = 0; i < s; ++i)
		{
			int k;
			scanf("%s %d",sVec[i].name, &k);
			while(k--)
			{
				int cid;
				scanf("%d",&cid);
				cVec[cid-1].push_back(i);
			}
		}
		//sort and output
		for(int i = 0; i < (int)cVec.size(); ++i)
		{
			printf("%d %d\n",i+1, (int)cVec[i].size());
			std::sort(cVec[i].begin(), cVec[i].end(), cmp);
			for(int j = 0; j < (int)cVec[i].size(); ++j)
			{
				printf("%s\n",sVec[cVec[i][j]].name);
			}
		}
	}
	return 0;
}
