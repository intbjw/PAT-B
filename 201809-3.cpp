#include<iostream>
#include<map>
#include<cstring>
#include<vector>
#include<ctype.h>
#include<string>

using namespace std;

const int N=105;

struct Node{
	string lable,id;
	int d;//缩进
}a[N];

vector<string>demand;
map<string,int>an,query;//an表示各个祖先含有的标签，id属性等，query表示要查询的

//将字符串s化为小写串
string mystrlwr(string s)
{
	for(int i=0;i<s.length();i++)
	  s[i]=tolower(s[i]);
	return s;
}

//以空格进行分割字符串s，并将分割结果保存在向量v中
void split(char *s,vector<string>&v)
{
	v.clear();
	char *p=strtok(s," ");
	while(p){
		v.push_back(p);
		p=strtok(NULL," ");
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	getchar();//读取回车
	for(int i=1;i<=n;i++){
		string s;
		getline(cin,s);
		//统计缩进
		int cnt=0;
		for(int j=0;j<s.length()&&s[j]=='.';j++,cnt++);
		//获取标签
		int len=0,pos=-1;//如果有#，pos就记录#的下标
		for(int j=cnt;j<s.length();j++,len++)
		  if(s[j]==' '){
		  	if(j+1<s.length()&&s[j+1]=='#')
		  	  pos=j+1;
		  	break;
		  }
		a[i].d=cnt;
		a[i].lable=s.substr(cnt,len);
		//由于标签的匹配大小写不敏感，因此化为小写
		a[i].lable=mystrlwr(a[i].lable);
		if(pos==-1)//如果没有id属性，就让id=""
		  a[i].id="";
		else
		  a[i].id=s.substr(pos);
	}
	while(m--){
		char d[100];
		gets(d);
		split(d,demand);
		vector<int>ans;
		if(demand.size()==1){//不是后代选择器，直接进行匹配
			string q=demand[0];
			if(q[0]!='#')//查询标签大小写不敏感
			  q=mystrlwr(q);//化为小写
			//进行匹配
			for(int i=1;i<=n;i++)
			  if(q==a[i].lable||q==a[i].id)
			    ans.push_back(i); //保存行号
		}
		else{
			query.clear();
			for(int i=0;i<demand.size()-1;i++){
				//统计各种标签，id属性的个数
				if(demand[i][0]!='#')//如果是标签就化成小写
				  demand[i]=mystrlwr(demand[i]);
				query[demand[i]]++;
			}
            string q=demand.back();
			if(q[0]!='#')//查询标签大小写不敏感
			  q=mystrlwr(q);//化为小写
			//进行匹配
			for(int i=1;i<=n;i++)
			  if(q==a[i].lable||q==a[i].id){
			  	//获取a的祖先结点的标签和id属性
				  an.clear();
				  for(int j=i-1;j>0&&a[j].d<=a[i].d;j--){
                    if(a[j].d==a[i].d)continue;//关键：细节
				  	an[a[j].lable]++;//由于标签不会为空，因此直接加一
				  	if(a[j].id!="")//只将不为空的id进行加一
				  	  an[a[j].id]++;
				  }
				//判断是否符合条件
				bool flag=true;
				//遍历查询的所有id选择器和标签选择器
				for(map<string,int>::iterator it=query.begin();it!=query.end();it++)
				  if(an.count(it->first)==0||an[it->first]<it->second){//如果i的祖先没有或者有但是个数不够
				  	flag=false;
				  	break;
				  }
				if(flag)
				  ans.push_back(i);
			  }
		}
		printf("%d",ans.size());
		for(int i=0;i<ans.size();i++)
		  printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
