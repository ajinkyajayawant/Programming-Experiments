/*problem done*/

/*simple iteration from n=1 to n=max of n possible*/
#include<stdio.h>
#include<math.h>
#define NUMBER 2000000

int main(){
	long int m=0,n=1,arr[2];
	const double rhs=NUMBER*4;//to use or not?
	const long int maxn=(long int)sqrt(rhs/2);
	long int exp=0;
	int least=0xc0de;
	long int diff=0;//arbit huge value assigned to least for comparison
	//c0de is 49374 in decimal	

	while(n<=maxn){
		m=(long int)sqrt(rhs/(n*(n+1)));
		diff=(long int)( (NUMBER > (exp=(n*(n+1)*m*(m+1))/4)) ? NUMBER-exp : exp-NUMBER);
		least=smaller(least,diff);
		if(least==diff)
			arr[0]=n;arr[1]=m;
		++n;
	}
	
	printf("The area is %ld\n\n",n*m);
	return 0;
}

int smaller(int a,int b){
	return (a<b)?a:b;
}
