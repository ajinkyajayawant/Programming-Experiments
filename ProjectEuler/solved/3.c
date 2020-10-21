/*decrease the memory usage of the program,to store 2 also we are using long int*/
/*incrementing by 2 and checking if number is prime,to increase speed of program*/
/*better implementation is possible*/
/*use of last_prime_f???????????????????*/

#include<stdio.h>
#include<stdlib.h>
#define STEP 2
#define GIVEN 600851475143
#define PRIME1 2
#define PRIME2 3

/*starting from 3 makes steps of two easy*/

struct prime{
	struct prime *nx_pr;
	unsigned long int prime;//number will definitely get decreased till this range,so long int will do
};

struct prime * all_pr(void);

int main(){
	int got_prime=0;
	unsigned long long int number=GIVEN,max_check;//check for prime nos till this number
	struct prime *lst_ptr,*i,*fst_ptr,*temp_del;//last pointer,i.e position of last empty prime filing,i is for going through the list
	struct prime *sclst_ptr;//for using the prime number
	unsigned long int last_prime_f,pr_check;//last prime factor uptil now of the given number
	/*pr_check is for checking whether pr_check is prime or not*/
	max_check=number;
	pr_check=PRIME2+STEP;
	/*initialising*/
	fst_ptr=all_pr();
	sclst_ptr=all_pr();
	if(fst_ptr==NULL || sclst_ptr==NULL){
		printf("Memory allocation not successful.\n");
		return 1;
	}
	fst_ptr->nx_pr=sclst_ptr;
	sclst_ptr->nx_pr=NULL;
	fst_ptr->prime= PRIME1;
	sclst_ptr->prime=PRIME2;
	lst_ptr=sclst_ptr->nx_pr;

	if(number%(fst_ptr->prime)!=0)
		max_check=number/fst_ptr->prime;
	
	while(number%(fst_ptr->prime)==0)
		number/=fst_ptr->prime;//that is 2
	/*checking whether the current prime is a factor of the number*/
	while( (sclst_ptr->prime) <= max_check){
		/*catching the last factor*/
		if((sclst_ptr->prime)==number)
			last_prime_f=sclst_ptr->prime;
		/*if not divide the number and decrease the max limit of the number*/
		if(number%(sclst_ptr->prime)!=0){//+ or -1 wont make a difference
			max_check=number/(sclst_ptr->prime);
		}

		/*check whether the given prime no is a factor*/
		/*loop for same factor repeatedly*/
		while(number%(sclst_ptr->prime)==0){
			last_prime_f=sclst_ptr->prime;
			number/=(sclst_ptr->prime);
			max_check=number;
		}
		/*find and add the next prime number*/
		/*check by all the numbers in the list*/
		while(!got_prime){
			i=fst_ptr;
			while(i!=NULL){
				if(pr_check%(i->prime) == 0)
					break;
				i=i->nx_pr;
			}
			if(i==NULL)
				got_prime=1;	
			pr_check+=STEP;
		}
		got_prime=0;//ready for the next loop
		/*initialise the first and last prime number location pointers*/
		sclst_ptr->nx_pr=all_pr();//linking the list
		if(sclst_ptr->nx_pr== NULL){
			printf("Memory allocation not successful.\n");
			return 1;
		}
		sclst_ptr=sclst_ptr->nx_pr;//initialising to proper value
		sclst_ptr->prime=pr_check-STEP;//since it has gone 1 step ahead
		lst_ptr=sclst_ptr->nx_pr=NULL;
	}
	/*ensuring last factor is taken*/
	/****************************/
	/*most important step*/
	if(number!=1)
		last_prime_f=number;
	/*limit crossed report the prime number*/
	printf("%ld\n",last_prime_f);
	/*free the allocated space*/
	i=fst_ptr;
	while(i!=NULL){
		temp_del=i->nx_pr;
		free(i);
		i=temp_del;
	}
	fst_ptr=sclst_ptr=lst_ptr=NULL;
	return 0;
}

struct prime * all_pr(void){
	return (struct prime *)malloc(sizeof(struct prime));
}
