#include<stdio.h>
#include<stdlib.h>

int dobro (int num) {
	
	return num*2;
	
}
// RODOU DE PREMERA
int main(){
	
int numero, fdobro;
	
	printf("\n Digite um numero inteiro: ");
	scanf("%d", &numero);
	
	fdobro = dobro(numero);
	printf("\n\n Dobro do numero: %d ", fdobro);
	
	return 0;
}
