/*instructions for compiling and running*/
/*g++ ./81.cpp /home/ajinkya/dev_cpp/my_template_func/getword1.c -o ./81*/
/*./81 < ./matrix.txt*/
/*cd to ~/dev_cpp/euler/unsolved/81*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#define LNUM 6
#define ARRSZ 80
using namespace std;

int matrix[ARRSZ][ARRSZ];
int dy_mat[ARRSZ][ARRSZ];
extern int getword1(char *,int);
unsigned long int min(unsigned long int,unsigned long int);
unsigned long int LeastPath(int , int );

int main(){
	char number[LNUM];
	bool input_end=false;
	int ret_val=0;

	for(int i=0;i<ARRSZ;++i)
		for(int j=0;j<ARRSZ;++j)
			dy_mat[i][j]=0;

	for(int i=0;i<ARRSZ;++i)
		for(int j=0;j<ARRSZ;++j)
			matrix[i][j]=0;


	/*get numbers into the matrix*/
		for(int i=0;i<ARRSZ && input_end==false;++i)
			for(int j=0;j<ARRSZ && input_end==false;++j){
				if((ret_val=getword1(number,LNUM))!=EOF)
					matrix[i][j]=atoi(number);
				else
					input_end=true;
			}

	/*call recursive fn*/
	cout<<"The least path sum is :"<<LeastPath(0,0)<<"\n";
	return 0;
}

unsigned long int LeastPath(int row , int column ){
	unsigned long int catch1=0,catch2=0,value=0;//value is the thing ti return
	if(dy_mat[row][column]!=0)
		value=dy_mat[row][column];
	else{
		if(column<ARRSZ-1 && row<ARRSZ-1){
			catch1=LeastPath(row+1,column);
			catch2=LeastPath(row,column+1);
			value=dy_mat[row][column]=matrix[row][column]+min(catch1,catch2);
		}
		else if(column<ARRSZ-1 && row==ARRSZ-1){
			catch2=LeastPath(row,column+1);
			value=dy_mat[row][column]=matrix[row][column]+catch2;
		}
		else if(column==ARRSZ-1 && row<ARRSZ-1){
			catch1=LeastPath(row+1,column);
			value=dy_mat[row][column]=matrix[row][column]+catch1;
		}
		else if( column==ARRSZ-1 && row==ARRSZ-1 )
			value=dy_mat[row][column]=matrix[row][column];
	}
	return value ;
}

unsigned long int min(unsigned long int a , unsigned long int b){
	return a<b?a:b;
}
