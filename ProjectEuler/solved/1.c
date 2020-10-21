#include<stdio.h>
#define NUM1 3
#define NUM2 5
#define NUM3 15
#define MAX 1000

int main(){
	int sum1=0,sum2=0,sum3=0,mul1=0,mul2=0,mul3=0;
	while(mul1<MAX){
		sum1+=(mul1=mul1+NUM1);
	}
	sum1-=mul1;
	while(mul2<MAX){
		sum2+=(mul2=mul2+NUM2);
	}
	sum2-=mul2;
	while(mul3<MAX){
		sum3+=(mul3=mul3+NUM3);		
	}
	sum3-=mul3;
	printf("%d\n",sum1+sum2-sum3);
	return 0;
}
