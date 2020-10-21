#define MAX 50
#define COND answer[2]=='8' && answer[4]=='7' && answer[6]=='6' && answer[8]=='5'\
&& answer[10]=='4' && answer[12]=='3' && answer[14]=='2' && answer[16]=='1' && (answer[17]=='\0' || answer[17]=='0')
#include<iostream>
using namespace std;

extern int Mul_2Arr(char*,char*,char*);
void print_arr(char *,int);
void reverse(char *);

int main(){
	char number[MAX]={'7','0','0','0','0','0','0','0','1','\0'};
	char answer[MAX];
	int got=0,i=0;

	answer[0]='\0';
	while(number[8]<='9' && got!=1){
		number[7]='0';
		while(number[7]<='9' && got!=1){
			number[6]='0';
			while(number[6]<='9' && got!=1){
				number[5]='0';
				while(number[5]<='9' && got!=1){
					number[4]='0';
					while(number[4]<='9' && got!=1){
						number[3]='0';
						while(number[3]<='9' && got!=1){
							number[2]='0';
							while(number[2]<='9' && got!=1){
								number[1]='0';
								while(number[1]<='9' && got!=1){
									answer[0]='\0';
									Mul_2Arr(number,number,answer);
									if(COND)
										got=1;
									++number[1];
								}
								++number[2];
							}
							++number[3];
						}
						++number[4];
					}
					++number[5];
				}
				++number[6];
			}
			++number[7];
		}
		++number[8];
	}
	i=1;
	while(i<=8)
		--number[i++];

	reverse(number);
	print_arr(number,MAX);
	reverse(answer);
	print_arr(answer,MAX);
	return 0;
}

void print_arr(char array[],int size){//size is length of the word
//when this int is included we can pass pointers containing words as well
	int i;
	for(i=0;i<size && array[i]!='\0';++i)
		cout<<array[i]<<" ";
	cout<<"\n";
	return;
}

void reverse(char torvs[]){//torvs=to reverse
	int forward=0,backward=0;
	int temp;
	while(torvs[backward]!='\0')
		++backward;//
	--backward;//now it points to last element of array
	while(backward>forward){
		temp=torvs[backward];
		torvs[backward]=torvs[forward];
		torvs[forward]=temp;
		--backward;
		++forward;
	}
	return;
}
