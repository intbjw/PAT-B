#include <stdio.h>

#include <stdlib.h>

#define SIZE (1000000)

void input(int [],int);

int q_time(int a[],int);



int main(void)

{

	int n;

	scanf("%d",&n);

	int * a = calloc(SIZE,sizeof(int));

	input(a,2*n);

	printf("%d\n", q_time(a,SIZE));

	return 0;

}



int q_time(int a[],int n){

	int sum = 0;

	while(-- n){

		if(a[n] > 1){

			sum ++;

		}

	}

	return sum;

}



void input(int a[],int n){

	while(n --){

		int s , t;

		scanf("%d%d",&s,&t);

		int i;

		for(i = s;i < t;i ++){

			a[i] ++;

		}

	}

}
