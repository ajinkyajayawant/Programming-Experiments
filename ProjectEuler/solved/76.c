#define N 100
#define P 100
#include<iostream>
using namespace std;


int FindPart(long int,long int);
int dynamic_arr[N][P];

int main(){
	int i=0,j=0;
	long int part_sum=0;
	for(i=0;i<100;++i)
		for(j=0;j<100;++j)
			dynamic_arr[i][j]=-1;

	i=1;
	while(i<=100)
		part_sum+=FindPart(100,i++);
	cout<<(part_sum-1)<<endl;
	return 0;
}

int FindPart(long int n,long int p){
	long int to_ret=0;
	long int first_term=0,second_term=0;
	if( n<p || n<=0 || p<=0 )
		;//to_ret remains zero
	else if(n==1)
		to_ret=1;
	else{
		if(dynamic_arr[n-1][p-1]!=-1)
			first_term=dynamic_arr[n-1][p-1];
		else
			first_term=FindPart(n-1,p-1);
		if(dynamic_arr[n-p][p]!=-1)
			second_term=dynamic_arr[n-p][p];
		else
			second_term=FindPart(n-p,p);
		to_ret=first_term+second_term;
	}
	dynamic_arr[n][p]=to_ret;
	return to_ret;	
}
