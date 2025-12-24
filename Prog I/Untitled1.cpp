#include <stdio.h>
#include <stdlib.h>

int main (){
	
int numero1, numero2, aux;
printf("digite numero1: ");
scanf("%d", &numero1);
printf("digite numero2: ");
scanf("%d", &numero2);
aux = numero1;
numero1 = numero2;
numero2 = aux;

printf("Numero1: %d", numero1);
printf("\nNumero2: %d", aux);

return 0;


	
	
	
	
	
	
	
	
}
