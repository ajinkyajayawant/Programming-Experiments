/*cd to : ~/dev_cpp/euler/unsolved/56*/

/*compile time instructions:*/
/*g++ -g ./56.cpp /home/ajinkya/dev_cpp/my_template_func/print_arr.cpp /home/ajinkya/dev_cpp/my_template_func/mul_2arr.cpp /home/ajinkya/dev_cpp/my_template_func/itoa.c -o ./56*/
/*execute instructions :*/
/*./56*/
#include<iostream>
#include<cstdlib>
#include<cstring>
#define PRODLEN 202
#define LIMIT 100
#define ZERO 48
using namespace std;

char product[PRODLEN];

unsigned long int SumArr(char *);
unsigned long int Greater(unsigned long int,unsigned long int);
int PowerNumber(char*,char*,int);
extern int Mul_2Arr(char *,char*,char*);
extern void RPrintArr(char *,int);
int CheckOdd(int);
extern void itoa(int , char*);

int main(){
	unsigned long int sum=0,max=0;
	char store[4];
	store[0]='\0';
	product[0]='\0';

	for(int i=1;i<LIMIT;++i)//i^j
		for(int j=1;j<LIMIT;++j){
	/*calculate power of the number by square method*/
			itoa(i,store);
			PowerNumber(store,product,j);
			sum=SumArr(product);
			max=Greater(max,sum);
		}
	
	/*find the */
	cout<<"The max sum is "<<max<<"\n";
	return 0;
}

int PowerNumber(char a[],char answer[],int n){
	char catcher[PRODLEN];
	catcher[0]='\0';
	if(n==1)
		strcpy(answer,a);
	else if(CheckOdd(n)){

		PowerNumber(a,answer,(n-1)/2);
		strcpy(catcher,answer);
		Mul_2Arr(catcher,catcher,answer);
		strcpy(catcher,answer);
		Mul_2Arr(a,catcher,answer);
	}
	else{//n is even
		PowerNumber(a,answer,n/2);
		strcpy(catcher,answer);
		Mul_2Arr(catcher,catcher,answer);
	}
	return 0;
}

int CheckOdd(int n){
	return n%2==1?1:0;
}

unsigned long int SumArr(char array[]){
	int i=0,ans=0;
	while(array[i]!='\0')
		ans+=array[i++]-ZERO;
	return ans;
}

unsigned long int Greater(unsigned long int a, unsigned long int b){
	return a>b?a:b;
}
