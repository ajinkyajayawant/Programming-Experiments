#include<stdio.h>
#define DIM 20

int bigOfTwo(int,int);

int main(){
	int mat[DIM][DIM],i,j;
	unsigned int max=0;
	
	/*accepting the matrix*/
	for(i=0;i<DIM;++i)
		for(j=0;j<DIM;++j)
			scanf("%d",&mat[i][j]);
	
	/*vertical checking*/
	for(i=0;i<=DIM-4;++i){
		for(j=0;j<DIM;++j){
			max=bigOfTwo(max,mat[i][j]*mat[i+1][j]*mat[i+2][j]*mat[i+3][j]);	
		}
	}
	
	/*horizontal check*/
	for(i=0;i<DIM;++i){
		for(j=0;j<=DIM-4;++j){
			max=bigOfTwo(max,mat[i][j]*mat[i][j+1]*mat[i][j+2]*mat[i][j+3]);	
		}
	}	
	
	/*diagonal1 check*/
	for(i=0;i<=DIM-4;++i){
		for(j=0;j<=DIM-4;++j){
			max=bigOfTwo(max,mat[i][j]*mat[i+1][j+1]*mat[i+2][j+2]*mat[i+3][j+3]);	
		}
	}		
	
	/*diagonal2 check*/
	for(i=0;i<=DIM-4;++i){
		for(j=3;j<DIM;++j){
			max=bigOfTwo(max,mat[i][j]*mat[i+1][j-1]*mat[i+2][j-2]*mat[i+3][j-3]);	
		}
	}		
		
	/*printing max*/
	printf("max:%d\n",max);
	
	return 0;
}

int bigOfTwo(int a1,int a2){
	return a1>=a2?a1:a2;
}

