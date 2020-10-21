#include<stdio.h>

int main(){
	long int tot=0;
	int i=1,j;
	while(i<=100){
		j=i+1;
		while(j<=100){
			tot+=(i*j);
			++j;
		}
		++i;
	}
	printf("%ld\n",tot*2);
	return 0;
}
