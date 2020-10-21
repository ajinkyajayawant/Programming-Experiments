#include<stdio.h>
#define MAX 4000000
#define SET 3

int main(){
	unsigned long int sum=2,take_sum=0,temp;
	int counter=0;
	int pre_num=1;
	while(sum<MAX){
		if(counter==0){
			take_sum+=sum;
		}
		temp=sum;
		sum+=pre_num;
		pre_num=temp;
		++counter;
		counter%=SET;
	}
	/*if one extra term is taken it will not affect take_sum*/
	printf("%ld\n",take_sum);
	return 0;
}
