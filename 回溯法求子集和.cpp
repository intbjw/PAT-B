#include<stdio.h>
# define M 100
 int n;//���������ϳ�Ա����
 int all;// �������Ӽ��ĺ�
 int arr[M];//����������
 int x[M]; //��¼�Ӽ���Ա
 int mark=0;

int Constrain(int t){
 int i;
 int sum=0;
 for(i=0;i<=t;i++) {//�Ӽ����
 if(x[i]==1) sum+=arr[i];
 }
 if(sum==all){
  printf("�ҵ����Ž�");
  for(i=0;i<=t;i++) {  //�����Ž��ӡ����
 if(x[i]==1) printf("%d ",arr[i]);
 }
 mark=1; //ֻҪ�ҵ����Ž⣬��ô����ͽ���
 }
}

int  Bound(int t){//�����û�е���Ҷ�ӽڵ�
 if(t<n)
  return 1;
 else return 0;
}
int  Backtrack(int t){//���͵��Ӽ��������ٽ���

 int i;

 if(t<n){
  for(i=0;i<=1;i++){
  x[t]=i;
  if(Constrain(t)&&Bound(t)){
  if(mark==1)return 0;
   Backtrack(t+1);
  }
 }
}
}

int main(){
 int i;
 scanf("%d %d",&n,&all);

 for(i=0;i<n;i++) {//�����������ϸ�ֵ
 scanf("%d",&arr[i]);
 }

 for(i=0;i<n;i++) {//��¼�Ӽ���Ա��һ��ʼΪ�գ�Ҳ���Ǳ�Ǽ���ΪȫΪ0
    x[i]=0;
 }

 Backtrack( 0);

}
