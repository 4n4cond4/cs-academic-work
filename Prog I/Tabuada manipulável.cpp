#include <stdio.h>
#include <stdlib.h>

int main(){

int x, n, produto;	

for(int x=1; x<=10; x=x+1){
printf("\nTABUADA: \n");
scanf("%d %d", &x, &n);	
produto = x*n;	
printf(" X = %d\n", produto); 
}
return 0;	
	
 }
