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
	int d;//����
}a[N];

vector<string>demand;
map<string,int>an,query;//an��ʾ�������Ⱥ��еı�ǩ��id���Եȣ�query��ʾҪ��ѯ��

//���ַ���s��ΪСд��
string mystrlwr(string s)
{
	for(int i=0;i<s.length();i++)
	  s[i]=tolower(s[i]);
	return s;
}

//�Կո���зָ��ַ���s�������ָ�������������v��
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
	getchar();//��ȡ�س�
	for(int i=1;i<=n;i++){
		string s;
		getline(cin,s);
		//ͳ������
		int cnt=0;
		for(int j=0;j<s.length()&&s[j]=='.';j++,cnt++);
		//��ȡ��ǩ
		int len=0,pos=-1;//�����#��pos�ͼ�¼#���±�
		for(int j=cnt;j<s.length();j++,len++)
		  if(s[j]==' '){
		  	if(j+1<s.length()&&s[j+1]=='#')
		  	  pos=j+1;
		  	break;
		  }
		a[i].d=cnt;
		a[i].lable=s.substr(cnt,len);
		//���ڱ�ǩ��ƥ���Сд�����У���˻�ΪСд
		a[i].lable=mystrlwr(a[i].lable);
		if(pos==-1)//���û��id���ԣ�����id=""
		  a[i].id="";
		else
		  a[i].id=s.substr(pos);
	}
	while(m--){
		char d[100];
		gets(d);
		split(d,demand);
		vector<int>ans;
		if(demand.size()==1){//���Ǻ��ѡ������ֱ�ӽ���ƥ��
			string q=demand[0];
			if(q[0]!='#')//��ѯ��ǩ��Сд������
			  q=mystrlwr(q);//��ΪСд
			//����ƥ��
			for(int i=1;i<=n;i++)
			  if(q==a[i].lable||q==a[i].id)
			    ans.push_back(i); //�����к�
		}
		else{
			query.clear();
			for(int i=0;i<demand.size()-1;i++){
				//ͳ�Ƹ��ֱ�ǩ��id���Եĸ���
				if(demand[i][0]!='#')//����Ǳ�ǩ�ͻ���Сд
				  demand[i]=mystrlwr(demand[i]);
				query[demand[i]]++;
			}
            string q=demand.back();
			if(q[0]!='#')//��ѯ��ǩ��Сд������
			  q=mystrlwr(q);//��ΪСд
			//����ƥ��
			for(int i=1;i<=n;i++)
			  if(q==a[i].lable||q==a[i].id){
			  	//��ȡa�����Ƚ��ı�ǩ��id����
				  an.clear();
				  for(int j=i-1;j>0&&a[j].d<=a[i].d;j--){
                    if(a[j].d==a[i].d)continue;//�ؼ���ϸ��
				  	an[a[j].lable]++;//���ڱ�ǩ����Ϊ�գ����ֱ�Ӽ�һ
				  	if(a[j].id!="")//ֻ����Ϊ�յ�id���м�һ
				  	  an[a[j].id]++;
				  }
				//�ж��Ƿ��������
				bool flag=true;
				//������ѯ������idѡ�����ͱ�ǩѡ����
				for(map<string,int>::iterator it=query.begin();it!=query.end();it++)
				  if(an.count(it->first)==0||an[it->first]<it->second){//���i������û�л����е��Ǹ�������
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
