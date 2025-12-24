#include<stdio.h>
#include<stdlib.h>

//testando while 

//a ideia é que repita enquanto num for diferente de um numero inteiro

int main(){
	
	int num;
	printf("Digite um numero inteiro: ");
	scanf("%d", &num);
	
	while (scanf(" %d", &num) != 1){
	
		printf("\nEntrada invalida! Digite novamente: ");
}
		
return 0;
}
