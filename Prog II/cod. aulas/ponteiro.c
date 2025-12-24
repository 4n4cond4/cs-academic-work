#include<stdio.h>
#include<stdlib.h>


int *p, *q;
int x;


int main(){

p = (int *) malloc(sizeof(int));
*p = 9;
q = p;

printf("o endereço de p é = %d e de q é = %d", p,q);  
printf("\nO valor de p é = %d e o endereço de q é = %d", *p, q);
printf("\n");

x = 11;
*q = x;

printf("\nO valor de p é = %d e o valor de q é = %d", *p, *q);

p = (int *) malloc(sizeof(int));

*p = 15;

printf("\nO valor de p é = %d e o endereço de q é = %d\n", *p, *q);

}