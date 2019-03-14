#include <iostream>
using namespace std;
int num=1;
void hanoi(char a,char b,char c,int n) {
    if(n==1){
        printf("第%d步:将%d号盘子%c---->%c\n", num,n,a,c);
        num++;
    }
    else{
        hanoi(a,c,b,n-1);
        printf("第%d步:将%d号盘子%c---->%c\n", num,n,a,c);
        num++;
        hanoi(b,a,c,n-1);
    }
}
int main()
{
    int n;
    std::cin >> n;
    hanoi('1','2','3',n);
    printf("最后总的步数%d\n", num-1);
    return 0;
}
