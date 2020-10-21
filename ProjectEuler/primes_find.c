/*finding and printing all prime numbers upto a certain number*/
#include<stdio.h>
#define PRIME1 2
#define PRIME2 3
#define NUMBER 200 //we want prime numbers till NUMBER in this case
#define MAX 100 //100 primes fit along with sr.no
#define STEP 2

int main(){
	unsigned int  prime_store[MAX],num_check;
	int i=0,ele_filled=1;
	prime_store[0]= 2;//we will remember no of elements for last element
	printf("%2d:%3d\n",i+1,PRIME1);
	num_check=PRIME2;
	while(num_check<=NUMBER){
		i=0;
		while(i<ele_filled){
			if(num_check%prime_store[i]==0)
				break;			//this is not a prime number
			++i;
		}
		if(i==ele_filled){
			/*fill the prime number*/
			prime_store[i]=num_check;
			printf("%2d:%3d\n",i+1,num_check);
			++ele_filled;	
		}
		num_check+=STEP;
	}
	return 0;
}
