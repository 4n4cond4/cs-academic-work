#include<stdio.h>
#include<stdlib.h>

//Crie um programa em C que permita fazer a conversão cambial entre Reais e Dólares. Considere
//como taxa de câmbio US$1,0 = R$5,30. Leia um valor em Reais e mostre o correspondente em
//Dólares.

int main(){
	
float dolar, real, repete, sair;

printf("\tCONVERSAO CAMBIAL:");

printf("\n\nValor em Reais: R$");
scanf(" %f", &real);

dolar = real / 5.3 ;

printf("\nValor em Dolares: US$%.2f", dolar);

}
