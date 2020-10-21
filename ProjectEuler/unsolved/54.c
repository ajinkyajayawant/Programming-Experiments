//terminal instruction cat ./poker.txt | tr 'T' '10' > ./poker1.txt


/*this is for determining who wins at a hand in poker*/
/*given that someone wins in a hand*/

/*plan: make 8 arrays of length 6 each bcuz 1 hand is of 5 cards*/
/*then each winning type(flush,straight,....) can be checked from */
/*top to bottom for each hand*/

/*assign default values to the array after it has bee used*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define N 5
#define M 6 // length of hand +1
#define MULTIPLIER 20
#define ZERO 48 //ascii value of zero

int greater(int,int);
int find_rank(int a[],int b[],int c[], int d[]);
int InputHand(int a[],int b[],int c[], int d[],FILE *);
int InputCard(int a[],int b[],int c[], int d[],FILE *);
void AssignArr(int a[],int b[],int c[], int d[],int);
int fgetword(FILE *,char **);
int findlen(char a[],int);
int RoyalFlush(int a[],int d[],int b[],int c[]);
int StraightFlush(int a[],int b[],int c[],int d[]) ;
int FourOfAKind(int a[]);
int FullHouse(int a[]);
int Flush(int a[],int b[],int c[],int d[]);
int Straight(int a[]);
int ThreeOfAKind(int a[]);
int TwoPairs(int a[]);
int OnePair(int a[]);
int HighCard(int a[]);
void qusort(int a[],int,int);
void swap(int a[],int,int);
int FindDistinct(int a[],int,char);

int main(){
	/*written empty entries 100 since now entire array can be sorted*/
	int h[M];
	int d[M];
	int s[M];
	int c[M];
	int ret1_val=0,ret2_val=0,eof_check=0,wins=0,equal=0;
	FILE *fpr=NULL,*fpw=NULL;

		int count=0;//testing
	AssignArr(h,d,s,c,M);
	fpr=fopen("poker.txt","r");
	fpw=fopen("HandsWin.txt","w");
	if(fpr==NULL){
		fprintf(stderr,"Input file opening failed\n");
		return 1;
	}

	if(fpw==NULL){
		fprintf(stderr,"Output file opening failed\n");
		return 1;
	}
	/*fill the arrays for first bout*/
	while((eof_check=InputHand(h,d,s,c,fpr))!=EOF){	//condition to continue the loop
		int hand1_val=0,hand2_val=0,i=0;//take the first hand , fill it properly ,
		//get the return value
		hand1_val=find_rank(h,d,s,c);//set the arrays in initial order
		++count;//testing
		printf("Hand1Val=%d\n",hand1_val);//testing
		
		AssignArr(h,d,s,c,M);
		eof_check=InputHand(h,d,s,c,fpr);
		if(eof_check==EOF)
			break;
		hand2_val=find_rank(h,d,s,c);
		printf("Hand2Val=%d\n",hand2_val);//testing
		
		AssignArr(h,d,s,c,M);
		if(hand1_val>hand2_val){
			fputc('1',fpw);
			fputc('\n',fpw);
			++wins;
		}
		else if(hand1_val==hand2_val){
			++equal;//testing, from this it seems that i have
			//done error 0 times
		}
		else{
			fputc('0',fpw);
			fputc('\n',fpw);
		}
	
	}	//take the second hand , fill it
		//compare the two hands , and output the winner
	/*give to functions for checking*/

	fclose(fpr);
	fclose(fpw);
	printf("no of times player wins is : %d\n",wins);
	printf("no of times i have done error: %d\n",equal);
	return 0;
}

/*functions will return value of highest value*/
/*card if that type(flush,fullhouse,...) exists*/
/*and 0 if that type does not exist*/

/*this will find the absolute importance of a particular hand*/
/*eg:if we have FourOfAKind then value will be (3*20)+*/
/*10(if highest value card is jack)*/

/*find rank function will sort and give the arrays*/
/*to the corresponding functions*/

void AssignArr(int hea[],int dia[],int spa[],int clu[],int size){
		int i=0;
		while(i<size)			
			hea[i++]=100;
		i=0;
		while(i<size)			
			dia[i++]=100;
		i=0;
		while(i<size)
			spa[i++]=100;
		i=0;
		while(i<size)
			clu[i++]=100;
}

int find_rank(int *hea,int *dia,int *spa,int *clu){
	int val_hand=0,arr_sto[M],i=0,j=0;
	qusort(hea,0,M-1);
	qusort(dia,0,M-1);
	qusort(spa,0,M-1);
	qusort(clu,0,M-1);

	while(i<M)//initialising so we can sort
		arr_sto[i++]=100;
		
	i=0;
	/*should this be wriiten in common?*/
	while(hea[j]!=100){
		arr_sto[i]=hea[j];
		++i;
		++j;
	}
	j=0;
	while(dia[j]!=100){
		arr_sto[i]=dia[j];
		++i;
		++j;
	}
	j=0;
	while(spa[j]!=100){
		arr_sto[i]=spa[j];
		++i;
		++j;
	}
	j=0;
	while(clu[j]!=100){
		arr_sto[i]=clu[j];
		++i;
		++j;
	}
	/*uptil here?*/

	qusort(arr_sto,0,M-1);

	printf("now arr is %d %d %d %d %d %d\n",arr_sto[0],arr_sto[1],arr_sto[2],arr_sto[3],arr_sto[4],arr_sto[5]);//testing
	if((val_hand=RoyalFlush(hea,dia,spa,clu))>0)
		;
	else if((val_hand=StraightFlush(hea,dia,spa,clu))>0)
		;
	else if((val_hand=FourOfAKind(arr_sto))>0)
		;
	else if((val_hand=FullHouse(arr_sto))>0)
		;
	else if((val_hand=Flush(hea,dia,spa,clu))>0)
		;
	else if((val_hand=Straight(arr_sto))>0)
		;
	else if((val_hand=ThreeOfAKind(arr_sto))>0)
		;
	else if((val_hand=TwoPairs(arr_sto))>0)
		;
	else if((val_hand=OnePair(arr_sto))>0)
		;
	else
		val_hand=HighCard(arr_sto);
	return val_hand;
}

int InputHand(int hea[],int dia[],int spa[],int clu[],FILE *fp){
	int ret_val=0,i=0;/*check whether return value is -1*/
	while(i<5){
		ret_val=InputCard(hea,dia,spa,clu,fp);
		if(ret_val==-1){
		printf("Memory operation given to InputCard failed\n");
			return -1;
		}
		if(ret_val==0)
			return EOF;
		++i;
	}
	return 1;//if all goes well
}

int InputCard(int hea[],int dia[],int spa[],int clu[],FILE *fp){
	int ret_check=0,i=0;
	char *word=NULL;

	ret_check=fgetword(fp,&word);
	if(ret_check==-1){
		printf("Allocating memory failed in fgetword\n");
		return -1;
	}
	if(ret_check==0){
		printf("length of string got=0\n");
		return 0;
	}
	switch (*(word+1)){
	case 'H':{
		/*find the first empty place in clurts*/
		i=0;
		while(hea[i]!=100 && i<M-1)
			++i;
		switch (*word){
			case 'J':
				hea[i]=11;
				break;
			case 'Q':
				hea[i]=12;
				break;
			case 'K':
				hea[i]=13;
				break;
			case 'A':
				hea[i]=14;
				break;
			case 'T':
				hea[i]=10;
				break;
			default:
				hea[i]=(int)(*word)-ZERO;
				break;
		}
	}
		break;
	case 'D':{
		/*find the first empty place in diarts*/
		i=0;
		while(dia[i]!=100 && i<M-1)
			++i;
		switch (*word){
			case 'J':
				dia[i]=11;
				break;
			case 'Q':
				dia[i]=12;
				break;
			case 'K':
				dia[i]=13;
				break;
			case 'A':
				dia[i]=14;
				break;
			case 'T':
				dia[i]=10;
				break;
			default:
				dia[i]=(int)(*word)-ZERO;
				break;
		}
	}
		break;
	case 'S':{
		/*find the first empty place in sparts*/
		i=0;
		while(spa[i]!=100 && i<M-1)
			++i;
		switch (*word){
			case 'J':
				spa[i]=11;
				break;
			case 'Q':
				spa[i]=12;
				break;
			case 'K':
				spa[i]=13;
				break;
			case 'A':
				spa[i]=14;
				break;
			case 'T':
				spa[i]=10;
				break;
			default:
				spa[i]=(int)(*word)-ZERO;
				break;
		}
	}
		break;
	case 'C':{
		/*find the first empty place in clurts*/
		i=0;
		while(clu[i]!=100 && i<M-1)
			++i;
		switch (*word){
			case 'J':
				clu[i]=11;
				break;
			case 'Q':
				clu[i]=12;
				break;
			case 'K':
				clu[i]=13;
				break;
			case 'A':
				clu[i]=14;
				break;
			case 'T':
				clu[i]=10;
				break;
			default:
				clu[i]=(int)(*word)-ZERO;
				break;
		}
	}
		break;
	}
	free(word);
	word=NULL;
	return 1;//if all goes well
}

int fgetword(FILE *fp, char **p2wrd){//fgetword returns the length and fills the pointer
//in case of memory probs i.e p2wrd is NULL, it returns -1
	char c,s[M];
	int i=0,len=0;
	while(!isalnum(c=fgetc(fp)) && c!=EOF)
		;
	ungetc(c,fp);
	while(isalnum(c=fgetc(fp)) && c!=EOF)
		s[i++]=c;
	s[i]='\0';	
	len=findlen(s,N);
	(*p2wrd)=(char *)malloc((len+1)*sizeof(char));//len+1 is for the end '\0'
	if((*p2wrd)==NULL)
		return -1;
	strcpy((*p2wrd),s);
	return len;
}

/*just returns the size of the string*/
int findlen(char array[],int maxsize){
	int i=0;
	while(i<maxsize && array[i]!='\0')
		++i;
	return i;
}

int RoyalFlush(int *hea,int *dia,int *spa,int *clu){
	int hand_val=0;
	if((hea[0]==10 && hea[1]==11 && hea[2]==12 && hea[3]==13 && hea[4]==14) || (dia[0]==10 && dia[1]==11 \
	&& dia[2]==12 && dia[3]==13 && dia[4]==14)|| (spa[0]==10 && spa[1]==11 && spa[2]==12 && spa[3]==13 && spa[4]==14) \
	|| (clu[0]==10 && clu[1]==11 && clu[2]==12 && clu[3]==13 && clu[4]==14)){
		return 9*MULTIPLIER;
	}	
	else
		return 0;
}

int StraightFlush(int *hea,int *dia,int *spa,int *clu){
	if((hea[4]!=100)||(dia[4]!=100)||(spa[4]!=100)||(clu[4]!=100)){
		int t=hea[0];
		if(hea[1]==t+1 && hea[2]==t+2 && hea[3]==t+3 && hea[4]==t+4)
			return 8*MULTIPLIER+t+4;
		else if(dia[1]==dia[0]+1 && dia[2]==dia[0]+2 && dia[3]==dia[0]+3 && dia[4]==dia[0]+4)
			return 8*MULTIPLIER+dia[0]+4;
		else if(spa[1]==spa[0]+1 && spa[2]==spa[0]+2 && spa[3]==spa[0]+3 && spa[4]==spa[0]+4)
			return 8*MULTIPLIER+spa[0]+4;
		else if(clu[1]==clu[0]+1 && clu[2]==clu[0]+2 && clu[3]==clu[0]+3 && clu[4]==clu[0]+4)
			return 8*MULTIPLIER+clu[0]+4;
		else
			return 0;
	}
	else
		return 0;
}

int FourOfAKind(int arr_sto[]){
	int check=0,n_pairs=0;//check is for seeing how many distinct numbers are there in hand

	check=FindDistinct(arr_sto,M-1,'p');
	n_pairs=FindDistinct(arr_sto,M-1,'l');

	if(check==2 && n_pairs==4)
		return 7*MULTIPLIER+arr_sto[4];
	else
		return 0;
}

int FullHouse(int arr_sto[]){
	int check=0,n_pairs=0;

	check=FindDistinct(arr_sto,M-1,'p');
	n_pairs=FindDistinct(arr_sto,M-1,'l');

	if(check==2 && n_pairs==3)
		return 6*MULTIPLIER+arr_sto[4];
	else
		return 0;
}

int Flush(int *hea,int *dia,int *spa,int *clu){
		if(spa[0]==100 && clu[0]==100 && dia[0]==100)	
			return 5*MULTIPLIER+hea[4];
		else if(spa[0]==100 && clu[0]==100 && hea[0]==100)	
			return 5*MULTIPLIER+dia[4];
		else if(dia[0]==100 && clu[0]==100 && hea[0]==100)	
			return 5*MULTIPLIER+spa[4];
		else if(dia[0]==100 && spa[0]==100 && hea[0]==100)//only 1 possibility remaining	
			return 5*MULTIPLIER+clu[4];
		else
			return 0;
}

int Straight(int arr_sto[]){
	if(arr_sto[1]==arr_sto[0]+1 && arr_sto [2]==arr_sto[0]+2 && arr_sto[3]==arr_sto[0]+3\
	&& arr_sto[4]==arr_sto[0]+4)
		return 4*MULTIPLIER+arr_sto[4];
	else
		return 0;
}

int ThreeOfAKind(int arr_sto[]){
	int check=0,n_pairs=0;
	
	check=FindDistinct(arr_sto,M-1,'p');
	n_pairs=FindDistinct(arr_sto,M-1,'l');

	if(check==3 && n_pairs==3)
		return 3*MULTIPLIER+arr_sto[4];
	else
		return 0;
}

int TwoPairs(int arr_sto[]){
	int check=0,n_pairs=0;
	
	check=FindDistinct(arr_sto,M-1,'p');
	n_pairs=FindDistinct(arr_sto,M-1,'l');

	if(check==3 && n_pairs==2)
		return 2*MULTIPLIER+arr_sto[4];
	else
		return 0;

}

int OnePair(int arr_sto[]){
	int check=0;
	
	check=FindDistinct(arr_sto,M-1,'p');
	if(check==4)
		return 1*MULTIPLIER+arr_sto[4];
	else
		return 0;

}

int HighCard(int arr_sto[]){
	return arr_sto[4];
}

/*this function checks whether four of th given variables*/
/*are equal , if yes it returns the greatest value*/

/*note that this function changes the original array*/
int FindDistinct(int list[],int size,char c){
	int count=0,i=0;
	int max=0,temp=0;
	qusort(list,0,size-1);
	while(i<size){
		if(c=='p'){//p corresponds to pairs
			if(list[i]!=count){
				count=list[i];	
				++max;
			}
		}
		else if(c=='l'){//l corresponds to maximum length of a pair
			//since now we are measurin length of new \
			string of numbers
			if(list[i]==count)
				++temp;
			else{
				max=greater(max,temp);
				count=list[i];
				temp=1;
			}
		}
		++i;
	}
	max=greater(max,temp);//this will only be effective in case c=='l'
	return max;
}

int greater(int a,int b){
	return (a>b)?a:b;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qusort(int v[], int left, int right){
	int i, last;
	void swap(int v[],const int i,const int j);
	if (left >= right) /* do nothing if array contains */
		return;
	/* fewer than two elements */
	swap(v, left, (left + right)/2); /* move partition elem */
	last = left;
	/* to v[0] */
	for (i = left + 1; i <= right; i++) /* partition */
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);
	/* restore partition elem */
	qusort(v, left, last-1);
	qusort(v, last+1, right);
	return;
}

void swap(int array[],const int i,const int j){
	int temp;
	temp=array[j];
	array[j]=array[i];
	array[i]=temp;
	return;
}
//(fscanf(fpr,"%s %s %s %s %s",&word_catch[0],&word_catch[1]&,\
	word_catch[2],&word_catch[3],&word_catch[4]))==5

//possible errors that can occur:
//i variable is not the same in all cases , so
//different places i can behave differently
