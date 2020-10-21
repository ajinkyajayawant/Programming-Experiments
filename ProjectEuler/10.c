/*finding and printing all prime numbers upto a certain number*/
#include<stdio.h>
#define PRIME1 2
#define PRIME2 3
#define NUMBER 2000000 //we want prime numbers till NUMBER in this case
#define MAX 500000 //100 primes fit along with sr.no
#define STEP 2

int main(){
	unsigned long int  prime_store[MAX];
	unsigned long int num_check,sum=2;
	unsigned int i=0,ele_filled=1;
	prime_store[0]= 2;//we will remember no of elements for last element
	num_check=PRIME2;
	while(num_check<NUMBER){
		i=0;
		while(i<ele_filled && i<MAX){
			if( (num_check%prime_store[i]) ==0)
				break;			//this is not a prime number
			++i;
		}
		if(i==ele_filled){
			/*fill the prime number*/
			prime_store[i]=num_check;
			/*take the sum*/
			sum+=num_check;
			++ele_filled;	
		}
		num_check+=STEP;
	}
	printf("sum:%ld\n",sum);
	return 0;
}

/*
real	1m50.765s
user	1m50.500s
sys	0m0.040s
*/
