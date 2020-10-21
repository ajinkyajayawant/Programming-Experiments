/*compile time instruction:*/
/* gcc  ./13.c /home/ajinkya/dev_cpp/my_template_func/Add2Arr.c -o ./13*/
/*execution instruction :*/
/*./13 < ./numbers.txt*/
/*Total of all numbers :5537376230390876637302048746832985971773659831892672*/
/*array of max 50 +4 +1 characters*/
#include<stdio.h>
#include<stdlib.h>
#define NOS 100
#define MAX 50
#define EXTRA 11
#define END 1
#define DEC 10
#define SIZE 2

void print_arr(char*);
void accept_num(char*,int);
void reverse(char*);
int getch(void);
void ungetch(int);
extern void Add2Arr(char *,char *,int,int);

/*for getch*/
char buffer[SIZE];
int last=0;//last empty position

int main(){
	char num[MAX+EXTRA+END];//this much length required for sum
	char sum[MAX+EXTRA+END];
	char i=1;
	sum[0]='\0';
	/*loop does 100 times*/
	while(i<=NOS){
		/*accepting number*/
		accept_num(num,MAX+EXTRA+END);
		Add2Arr(num,sum,MAX+EXTRA+END,MAX+EXTRA+END);//adding it
		++i;
	}
	/*printing first 10 digits*/
	reverse(sum);
	printf("Answer:");
	print_arr(sum);
	return 0;
}

void accept_num(char s[],int maxlen){
	int i=0;
	char c;
	while((c=getch())!=EOF && c!='\n' && c!='\r' && i<maxlen){
		s[i]=c;
		++i;
	}
	/*eat white space characters*/
	if(c!=EOF){
		while((c=getch())=='\n' || c=='\r' || c=='\f')
			;
		ungetch(c);
	}
	s[i]='\0';
	reverse(s);
	if(i==maxlen)
		printf("Number array insufficient\n");
	return;
}

void reverse(char torvs[]){//torvs=to reverse
	int forward=0,backward=0;
	char temp;
	while(torvs[backward]!='\0')
		++backward;
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

void print_arr(char array[]){
	int i;
	for(i=0;array[i]!='\0';++i)
		printf("%c",array[i]);
	putchar('\n');
	return;
}

int getch(void){
	char temp;
	if(last!=0){
		temp=buffer[--last];
		buffer[last]='\0';
		return (int)temp;
	}
	else
		return((int)getchar());
}

void ungetch(int charac_to_push){
	/*assuming buffer size sufficient*/
	buffer[last++]=(char)charac_to_push;
	buffer[last]='\0';
}
