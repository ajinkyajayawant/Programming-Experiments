#include<stdio.h>
#define DEC 10
#define START 2
#define END 99
#define SIZE 188

void mul_arr(char*,int);
void print_arr(char*);//testing

int main(){
	unsigned int i=START,sum=0;
	char final[SIZE];
	final[0]='1';final[1]='\0';
	while(i<=END){
		print_arr(final);//testing
		mul_arr(final,i++);
	}
	i=0;
	while(final[i]!='\0')
		sum+=final[i++]-'0';
	print_arr(final);//testing
	printf("sum:%d\n",sum);
	return 0;
}

/*s is in reverse number order*/
void mul_arr(char s[],int num){
	unsigned char i=0;
	unsigned int temp=0,carry=0;
	
	while(s[i]!='\0'){
		temp=(s[i]-'0')*num+carry;
		s[i]=temp%DEC+'0';
		carry=temp/DEC;
		++i;
	}
	while(carry!=0){
		temp=carry;
		s[i]=temp%DEC+'0';
		carry=temp/DEC;
		++i;
	}
	s[i]='\0';
}

void print_arr(char array[]){//testing
	int i;
	for(i=0;array[i]!='\0';++i)
		printf("%c ",array[i]);
	putchar('\n');
	return;
}
