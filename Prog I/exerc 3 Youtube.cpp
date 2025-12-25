#include<stdio.h>
#include<stdlib.h>

// EXERCICIO 3) YOUTUBE
int main(){
	
int a, b;
	
printf("Digite o valor de A: ");
scanf("%d", &a);

printf("Digite o valor de B: ");
scanf("%d", &b);


a = a+b;
b = a-b;
a = a-b;


printf("\nValores invertidos:\n\n A: %d / B: %d", a, b);


return 0;	
}
