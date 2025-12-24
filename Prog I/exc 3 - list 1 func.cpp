#include<stdio.h>
#include<stdlib.h>

int fatorial (int num){

int i, fat = 1;

for(i = 1; i <= num; i++)
	
	fat = fat * i;
	
	return fat;
}

int main(){
	
int numero, result;
	
	printf("\n Digite um numero inteiro: ");
	scanf("%d", &numero);
	
	result = fatorial(numero);
	
	printf("\n\n Fatorial de %d: %d", numero, result);
	printf("\n");
	
	
	return 0;
}
