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
void add_arr(char s1[],char s2[],int size1,int size2);
void accept_num(char*,int);
void reverse(char*);
int getch(void);
void ungetch(int);

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
		/*printf("num:");print_arr(num);//testing*/
		add_arr(num,sum,MAX+EXTRA+END,MAX+EXTRA+END);//adding it
		/*printf("sum:");print_arr(sum);//testing*/
		++i;
	}
	/*printing first 10 digits*/
	reverse(sum);
	printf("Answer:");
	print_arr(sum);
	return 0;
}
/*add array code is working*/
void add_arr(char s1[],char s2[],int size1,int size2){	//add s1 to s2 both's size is size
	int temp=0,carry=0,k=0,arr2ends=0;
	while(k<size1 && k<size2 && s1[k]!='\0'){//array 1 ends
		printf("%d ",carry);
		if(s2[k]=='\0')
			arr2ends=1;
		if(arr2ends!=1){
			temp=(s1[k]-'0')+(s2[k]-'0')+carry;	
		}
		else{
			temp=(s1[k]-'0')+carry;
		}
		s2[k]=(temp%DEC)+'0';
		carry=temp/DEC;
		++k;
	}
	while(carry!=0){
		printf("%d ",carry);
		if(s2[k]=='\0')
			arr2ends=1;
		if(arr2ends==1){
			s2[k]=carry+'0';
			carry=carry/DEC;//which will be zero
			
		}
		else{
			temp=carry+(s2[k]-'0');//there will not be more than one digit in carry
			s2[k]=temp%DEC+'0';
			carry=temp/DEC;
		}
		++k;
	}
	s2[k]='\0';
	if(k==size1 || k==size2)
		printf("Array insufficient\n");
	return;
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
