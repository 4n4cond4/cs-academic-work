#include<stdio.h>
#include<stdlib.h>

typedef struct {
	
char nome [31];
int idade;
float altura;
	
} Pessoa;


int main(){

 Pessoa pessoa;
 
 printf("Digite seu nome: ");
 scanf("%s", &pessoa.nome);

 printf("Digite sua idade: ");
 scanf("%d", &pessoa.idade);
 
 printf("Digite sua altura: ");
 scanf("%f", &pessoa.altura);
 
 
 
 printf("\n\nNome: %s / Idade: %d anos / Altura: %.2f m", pessoa.nome, pessoa.idade, pessoa.altura);
 
 return 0;
 
}

