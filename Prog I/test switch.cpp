#include<stdio.h>
#include<stdlib.h>

int main(){

char nome[31];	
int escolha, idade, todos;
	
	printf("1 - SOLICITA O NOME\n2 - SOLICITA A IDADE\n3 - SOLICITA NOME E IDADE\n");
	
	printf("\nSOLICITAR: ");
	scanf("%d", &escolha);
	
	switch(escolha){
		
	case 1:
		printf("\nDigite seu nome: ");
		scanf("%s", &nome[31]);
		break;
		 	
	case 2:
		printf("\nDigite sua idade: ");
		scanf("%d", &idade);
		break;	
	case 3:	
		printf("\nDigite seu nome e sua idade: ");
		scanf("%s %d", &nome[31], &idade);
		break;
		
	}
	
	
return 0;	
	
}
