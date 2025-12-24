#include<stdio.h>
#include<stdlib.h>

//FUNÇÃO PARA DIZER SE É
//POSITIVO OU NEGATIVO

int Valor(int num){

int tORf;

if 	(num < 0)

printf("\n\nResultado: Negativo");

else

printf("\n\nResultado: Positivo");

return tORf;
	
}

int main(){
	
int nmr, resultado;

	printf(" POSITIVO OU NEGATIVO?\n\n");	
	printf("Digite um numero inteiro: ");
	scanf("%d", &nmr);
	
resultado = Valor(nmr);	
	
	
return 0;	
}




