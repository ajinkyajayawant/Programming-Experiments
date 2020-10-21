/*plan for the making the program*/
/*make an array of pointers*/
/*get and store pointers of words in that*/
/*arrange the words*/
/*find the sum*/
/*free the words*/

#include<stdio.h>
#define MPOSSI 10000

int main(){
	char *wrdpst[MPOSSI],*name;
	FILE *filep=NULL;
	int size=0;
	filep=fopen("./names.txt","r");
	size=fgetword(filep,&name);
	if()

	return 0;
}

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
	return findwrdval(s);
}
