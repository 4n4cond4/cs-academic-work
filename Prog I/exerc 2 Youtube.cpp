#include<stdio.h>
#include<stdlib.h>


//EXERCICIO 2) YOUTUBE

int main(){
	
int a, b, aux;
	
	printf(" A: ");
	scanf("%d", &a);
	
	printf("\n B: ");
	scanf("%d", &b);
	
	aux = a;
	a = b;
	b = aux;
	
	printf("\nValores invertidos: ");
	printf("\n\n A: %d / B: %d", a, b);
}

