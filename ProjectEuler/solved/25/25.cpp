/*cd to : ~/dev_cpp/euler/unsolved/25*/
/*compile instructions :*/
/*g++ ./25.cpp /home/ajinkya/dev_cpp/my_template_func/Add2Arr.c /home/ajinkya/dev_cpp/my_template_func/findlen.c /home/ajinkya/dev_cpp/my_template_func/print_arr.cpp -o ./25*/
/*execute instruction : ./25*/
#include<iostream>
#include<cstring>
using namespace std;

#define WANTLEN 1000
#define EXTRA 5

extern void Add2Arr(char *,char*,int , int);
extern int findlen(char *,int);
extern void RPrintArr(char *, int);

int main(){
	long unsigned int count=3;
	char fibonacci1[WANTLEN+EXTRA];
	char fibonacci2[WANTLEN+EXTRA];
	char store[WANTLEN+2];
	bool add1=true;
	fibonacci1[0]='1';fibonacci1[1]='\0';
	fibonacci2[0]='2';fibonacci2[1]='\0';
	store[0]='\0';
	while(findlen(fibonacci2,WANTLEN+EXTRA)!=WANTLEN){
		/*this conditions are so that alternatively both blocks are entered*/
		strcpy(store,fibonacci2);
		Add2Arr(fibonacci1,fibonacci2,WANTLEN+EXTRA,WANTLEN+EXTRA);
		strcpy(fibonacci1,store);
		++count;//count indicates the term number of fibinacci2
	}
	cout<<count<<"\n";
	return 0;
}
