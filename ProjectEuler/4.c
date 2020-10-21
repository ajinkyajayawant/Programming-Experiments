/*need to improve the method if possible*/

#include<stdio.h>

#define START 100
#define END 999
#define MUL 11
#define ARRSIZE 7

void itoa(long int number,char v[]);
void reverse(char torvs[]);
int check_pali(long int);

int main(){
	unsigned int is_pali=0;
	unsigned long int max_pali=0;
	unsigned long int pali;
	unsigned int num1=START,num2=START;
	while(num1%MUL!=0)
		++num1;
	while(num1<=999){
		num2=START;
		while(num2<=999){
			pali=num1*num2;
			is_pali=check_pali(pali);
			if(is_pali)
				(pali>max_pali) ? max_pali=pali :/*nothing*/0 ;//0 is because we have to assign some value to the expression
			is_pali=0;//initialise as before
			++num2;
		}
		num1+=MUL;
	}
	printf("%ld\n",max_pali);
	return 0;
}

int check_pali(long int num){
	int i=0,j=0,result=1;
	char num_arr[ARRSIZE];
	itoa(num,num_arr);
	while(num_arr[j]!='\0')
		++j;
	--j;
	while(i<=j && result==1){
		if(num_arr[i]!=num_arr[j])
			result=0;
		++i;
		--j;
	}
	return result;
}

/*itoa.c*/
void itoa(long int number,char v[]){
	int rmdr,i=0;//rmdr=remainder
	extern void reverse(char *);
	while(number!=0){
		rmdr=number%10;
		number-=rmdr;
		number/=10;
		v[i++]='0'+rmdr;
	}
	v[i]='\0';
	reverse(v);
	return;
}

/*reverse*/
void reverse(char torvs[]){//torvs=to reverse
	int forward=0,backward=0;
	int temp;
	while(torvs[backward]!='\0')
		++backward;//
		--backward;//now it points to last element of array
	while(backward>forward){
		temp=torvs[backward];
		torvs[backward]=torvs[forward];
		torvs[forward]=temp;
		--backward;
		++forward;
	}
	return;
}
