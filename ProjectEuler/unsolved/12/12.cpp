/*this program takes infinite amount of time to execute*/
#include<iostream>
using namespace std;

typedef unsigned long int triangleNum;

int main(){
	triangleNum number=0,i=0;
	unsigned long int natural_num=1;
	int count=0;
	bool got=false;
	while(got!=true){
		number+=(natural_num++);
		for(i=1,count=0;i<=number;++i){
			if(number%i==0)
				++count;	
		}
		if(count>500)
			got=true;
	}
	cout<<number<<"\n";
	return 0;
}
