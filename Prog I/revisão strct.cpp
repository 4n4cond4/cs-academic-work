#include<stdio.h>
#include<stdlib.h>

typedef struct{
	
char nome[51];
int idade;
float altura;
	
} Pessoa;


int main(){

 Pessoa pessoa;
 
 printf("Digite seu nome: ");
 scanf("%s", &pessoa.nome);
 
 printf("Nome: %s", pessoa.nome);
 printf("\n");
 return 0;
 
}

