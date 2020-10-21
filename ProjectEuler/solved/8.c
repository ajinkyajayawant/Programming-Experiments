#include<stdio.h>
#define TOT 1000

int mul4(char,char,char,char);
int mul2(int,char);
int div2(int,char);
int bigg_ret(int,int);

int main(){
	unsigned int max_prod,i=0,prod4=1;
	char num_arr[TOT+1],c;

	/*inputting the number*/
	while((c=getchar())!=EOF){
		if(c=='\n')
			;
		else
			num_arr[i++]=c;
	}
	num_arr[i]='\0';

	i=0;
	/*doing the calculations*/
	prod4=mul4(num_arr[i],num_arr[i+1],num_arr[i+2],num_arr[i+3]);
	max_prod=mul2(prod4,num_arr[i+4]);
	++i;
	while(i<=TOT-4){//try and see why 4 is written
		if(prod4!=0)
			prod4=mul2(div2(prod4,num_arr[i-1]),num_arr[i+3]);
		else
			prod4=mul4(num_arr[i],num_arr[i+1],num_arr[i+2],num_arr[i+3]);
			
		if(num_arr[i-1]>=num_arr[i+4])
			;
		else
			max_prod= bigg_ret(max_prod,(mul2(prod4,num_arr[i+4])));
		++i;
	}

	/*printing the max number*/
	printf("%d\n",max_prod);

	return 0;
}

int mul4(char a1,char a2,char a3,char a4){
	return (a1-'0')*(a2-'0')*(a3-'0')*(a4-'0');
}

int mul2(int a1,char a2){
	return (a1)*(a2-'0');
}

int div2(int a1,char a2){//you have to make sure its divisible
	return (a1)/(a2-'0');
}

int bigg_ret(int i1,int i2){
	return (i1>=i2)?i1:i2;
}
