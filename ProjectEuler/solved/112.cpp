/*bouncy numbers*/
#include<iostream>
#define CONSTANT 21780
#define LENGTH 10
#define BASE 10
#define START 100

using namespace std;

bool CheckBouncy(char *);
bool ICheckBouncy(char *);
bool DCheckBouncy(char *);
void itoa(unsigned long int,char *);
void reverse(char *);


int main(){
	unsigned long int number=START;
	unsigned long int count_bouncy=0;
	unsigned int check=0;
	char ready_num[LENGTH];

	while( number<=CONSTANT || (number*99)!=(count_bouncy*100) || check!=1 ){
		++number;
		itoa(number,ready_num);
		check=(int)CheckBouncy(ready_num);
	//	cout<<"check value is "<<check<<"for number "<<number<<"\n";//testing
	//	if(check==true)
	//		cout<<ready_num<<"\n";//print the number, printing
		count_bouncy+=check;
		
	}
	cout<<"The number of bouncy numbers are :"<<count_bouncy<<"\n";
	cout<<"The bouncy number acheiving 99perc bouncy nums is : "<<number<<"\n";
	return 0;
}

bool CheckBouncy(char save_num[]){
	bool bouncy=false;//0 means not bouncy
	bouncy= DCheckBouncy(save_num) && ICheckBouncy(save_num);
	return bouncy;
}

bool ICheckBouncy(char number[]){ //check whether number is bouncy of increasing type
	int i=1;
	while(number[i]!='\0' && number[i]>=number[i-1])
		++i;
	if(number[i]=='\0')
		return false;
	else
		return true;
}

bool DCheckBouncy(char number[]){
	int i=1;
	while(number[i]!='\0' && number[i]<=number[i-1])
		++i;
	if(number[i]=='\0')
		return false;
	else
		return true;
}

void itoa(unsigned long int number,char v[]){
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
