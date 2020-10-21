#include<stdio.h>
#define MAX 336
#define DECIMAL 10
#define BASE 2

void mulci(int,char*,int);

int main(){
	unsigned int sum=0,multiplier=1,i=0;
	char store_wanted[MAX];//for storing number digit by digit
	store_wanted[0]='1';store_wanted[1]='\0';
	
	/*prepare 2^10*/
	i=1;
	while(i<=10){
		multiplier*=BASE;
		++i;
	}
	
	/*go on multiplying the number by2^10 till 2^1000*/
	i=1;
	while(i<=100){//change
		mulci(multiplier,store_wanted,MAX);
		++i;
	}
	
	/*find the sum of all numbers*/
	i=0;
	while(store_wanted[i]!='\0'){
		sum+=(store_wanted[i]-'0');
		++i;	
	}
	
	/*print the sum*/
	printf("sum of digits of 2^100 is:%d\n",sum);
	
	return 0;
}

void mulci(int num,char s[],int limit){//number is stored in reverse order in this array
	int i=0,temp=1,carry=0;//temp is some number 1 since we dont want temp==0  initilisation
	int got_end=0;
	while(i<limit && (got_end!=1 || carry!=0)){
		if(s[i]=='\0')
			got_end=1;
		if(got_end==1){
			temp=carry;
			s[i]=temp%DECIMAL+'0';
			carry=temp/DECIMAL;
		}
		else{
			temp=(s[i]-'0')*num+carry;
			s[i]=temp%DECIMAL+'0';
			carry=temp/DECIMAL;
		}
		++i;
	}
	if(i==limit)
		printf("Array incomplete to store new number\n");
	s[i]='\0';
	return;
}
