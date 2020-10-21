/*program successful*/
/*declarations and thorough checking remaining*/
#include<stdio.h>
#include<string.h>
/*this is for maloc*/
#include<stdlib.h>
#include<ctype.h>//for isalpha
#define MPOSSI 7000 //max possible
#define N 20

/*for this question , assign ascii value to each name ,
store it in an array , then sort the array and find the 
final sum multiplying rank and ascii value*/

int fgetword(FILE *filepointer,char **wordtofill);
int findlen(char givenarray[],int maxpossiblelen);
void qusort(char *arrofps[],int leftpos,int rightpos);
void swap(char *arrray[],int pos1,int pos2);
int findwrdval(char array[]);// finds ascii total of characters of a word .
void ilprint_arr(unsigned int array[], int size);// this functon prints long arrays given their size \
and that they are terminated by 0 .
void print_arr(char *,int);
void print_sarr(char* arr[],int maxsz);


int main(){
	char *bigar[MPOSSI];
	char *name=NULL;
	long long sum=0;
	FILE *filep=NULL;
	int j=0,size=-2;//-2 is arbit initial value

	/*allocating all array pointers to zero*/
	while(j<MPOSSI)
		bigar[j++]=NULL;
	j=0;

	filep=fopen("./names.txt","r");
	/*take the inputs , and store ascii values in array*/
	while(size!=0){
		size=fgetword(filep,&name);
		if(name==NULL){
			printf("Memory allocation failed\n");
			return 1;
		}//changed , deleted freeing part	
		bigar[j++]=name;//changed
		name=NULL;//for next input incase 
	}

	/*sort the array*/
	qusort(bigar,0,j-2);//since the iterator will go one step ahead of size zero array element
	/*do arthmatic operations and find the sum*/
	j=0;
	while(bigar[j]!=0){
		sum+=((j+1)*findwrdval(bigar[j]));
		++j;
	}
	fclose(filep);

	/*freeing the space*/
	j=0;
	while(bigar[j]!=NULL){
		free(bigar[j]);
		bigar[j]=NULL;
		++j;
	}

	printf("Required sum is :%lld\n",sum);

	return 0;
}

/*remember to free the pointers in the main function*/
/*if empty array is received calling function should 
come to know end of file reached*/
/*close the fil in the main function*/

/*this fgetword is tailored for this sum to return an ascii value*/
int fgetword(FILE *fp, char **p2wrd){//fgetword returns the length and fills the pointer
//in case of memory probs i.e p2wrd is NULL, it returns -1
	char c,s[N];
	int i=0,len=0,value=0;
	while(!isalpha(c=fgetc(fp)) && c!=EOF);
	ungetc(c,fp);
	while(isalpha(c=fgetc(fp)) && c!=EOF)
		s[i++]=c;
	s[i]='\0';
	len=findlen(s,N);
	(*p2wrd)=malloc((len+1)*sizeof(char));//len+1 is for the end '\0'
	if((*p2wrd)==NULL)
		return -1;
	strcpy((*p2wrd),s);
	return len;//changed
}


int findlen(char array[],int maxsize){
	int i=0;
	while(i<maxsize && array[i]!='\0')
		++i;
	return i;
}

void qusort(char *v[], int left, int right){
	int i, last;
	void swap(char *v[],const int i,const int j);
	if (left >= right) /* do nothing if array contains */
		return;
	/* fewer than two elements */
	swap(v, left, (left + right)/2); /* move partition elem */
	last = left;
	/* to v[0] */
	for (i = left + 1; i <= right; i++) /* partition */
		if (strcmp(v[left],v[i])>0)//if(v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);
	/* restore partition elem */
	qusort(v, left, last-1);
	qusort(v, last+1, right);
	return;
}

void swap(char *array[],const int i,const int j){
	char *temp;
	temp=array[j];
	array[j]=array[i];
	array[i]=temp;
	return;
}

int findwrdval(char word[]){
	int k=0,val=0;
	while(word[k]!='\0')
		val+=((word[k++]-'A')+1);//this can be changed
	return val;
}

void ilprint_arr(unsigned int array[],int size){//size is length of the word
//when this int is included we can pass pointers containing words as well
	unsigned int i;
	for(i=0;i<size && array[i]!=0;++i)
		printf("%d ",array[i]);
	printf("\n\n");
	return;
}

void print_arr(char array[],int size){//size is length of the word
//when this int is included we can pass pointers containing words as well
	int i;
	for(i=0;i<size && array[i]!='\0';++i)
		printf("%c ",array[i]);
	putchar('\n');
	return;
}

void print_sarr(char *arr[],int size){
	int i=0;
	for(i=0;i<size && arr[i]!=NULL;++i)
		print_arr(arr[i],N);
}
