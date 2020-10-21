/*if sequence is 13,40,20,10,5,16,8,4,2,1 remember the indexes 13->1,40->2,20->3,10->4,5->5,16->6,8->7,4->8,2->9,1->10
now if we want to know length of sequence starting at 20 we do 10-3+1 */
/*and if we have completed numbers till 17 then we have the record of the lengths of all the
sequences from 1 to 17 plus the lengths of the sequences of , numbers that occured in those
1 to 17 sequences*/
/*a number cannot appear more than once in a sequence,otherwise the sequence will not converge,so no
worry about saving the same number twice*/
/*how much big should be the array which stores the elements of the current sequence*/
/*that is how big can be a sequence??*/
/*so make a linked list for the sequence*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000 	//1 million
#define PARITY 2

static unsigned long int lengths[MAX+1];

struct element{
	unsigned long int number,pos;//pos is the position of that number in the sequence
	struct element *next;
};

void add_ele_end(struct element *,struct element *);
void *give_mem(void);
unsigned long int big_give(unsigned long int,unsigned long int);

int main(){
	/*0th position in the lengths array is vacant since numbers start from 1*/
	unsigned long int i=0,number,maxlen=0,lchm=0;//check the range,lengths is for storing what is the length of sequence atarting with that number
	/*initialise the lengths array to zero*/
	while(i<=MAX)
		lengths[i++]=0;

	number=1;
	/*start the loop of numbers*/
	while(number<MAX){
	/*start the inner loop*/
		char seq_over='0';
		struct element *first=NULL,*iterate=NULL,*temp=NULL;
		/*len is for storing the length of the sequence starting with the number*/
		unsigned long int position=0,arr_num=number,len=0;//position is for number of elements already counted in the array
        /*lchm is longest chain number*/
		while(seq_over!='1'){
			struct element *filled=NULL;
			//arr_num is the number in the array,which can be incremented or decremented
			/*if got the number in lengths array or got 1 exit the loop*/
			if(arr_num<=MAX){
                if(lengths[arr_num]!=0){
                    len=position+lengths[arr_num];
                    if(len>maxlen)
                        lchm=number;
                    maxlen=big_give(maxlen,len);
                    seq_over='1';
                }
                else{//if arr_num is greater it just wont be there in the lengths array
                    ++position;
                    if( (filled=(struct element *)give_mem()) == NULL){
                        printf("Memory allocation failed\n");
                        return 1;
                    }
                    filled->number=arr_num;
                    filled->pos=position;
                    filled->next=NULL;
                    /*adding the number in the linked list*/
                    add_ele_end(first,filled);
                    if(position==1)
                        first=filled;//so that first does not remain a null pointer
                }
			}
			else{//if arr_num is greater it just wont be there in the lengths array
				++position;
				if( (filled=(struct element *)give_mem()) == NULL){
					printf("Memory allocation failed\n");
					return 1;
				}
				filled->number=arr_num;
				filled->pos=position;
				filled->next=NULL;
				/*adding the number in the linked list*/
				add_ele_end(first,filled);
				if(position==1)
                    first=filled;//so that first does not remain a null pointer
			}
			if(number==1){//first iteration
			    len=position;
			    if(len>maxlen)
                        lchm=number;
				maxlen=big_give(maxlen,len);
				seq_over='1';
			}
			/*if not find next element and add previous element to seq array*/
			if(seq_over!='1'){//find next element in the sequence,add it,increment the position
				if(arr_num%PARITY==0)//even number
					arr_num=arr_num/2;
				else
					arr_num=arr_num*3+1;
			}
			else{	//add the elements and the corresponding length of array in lengths array
				/*filled is now used so we can now use it for iteration along the list*/
				iterate=first;
                while(iterate!=NULL){
					    if((iterate->number)<=MAX )
                            lengths[iterate->number]=len-(iterate->pos)+1;
                        else
                            ;//dont fill it since it can be any large.
						iterate=iterate->next;
                }
			}
		}
		/*free the linked list*/
		iterate=first;
			while(iterate!=NULL){
				temp=iterate;
				iterate=iterate->next;
				free((void*)temp);
			}
		++number;
	}

	printf("The maximum lenth of sequence is:%ld\n",maxlen);
	printf("The number that gives max seq is:%ld\n",lchm);
	return 0;
}

void add_ele_end(struct element *start,struct element *fill){//add element at the end
	struct element *pointer=start;
	if(pointer==NULL)//means that first element itself is not there
		;//we can do nothing in this case
	else{
		while(pointer->next!=NULL)
			pointer=pointer->next;
		pointer->next=fill;
		fill->next=NULL;
	}
	return;
}

void *give_mem(void){
	return malloc(sizeof(struct element));
}

unsigned long int big_give(unsigned long int a1,unsigned long int a2){
	return a1>a2?a1:a2;
}
