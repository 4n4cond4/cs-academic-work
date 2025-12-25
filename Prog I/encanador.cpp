#include<stdio.h>
#include<stdlib.h>

//Uma empresa contrata um encanador a R$ 45,00 por dia. Faça um programa que solicite o
//número de dias trabalhados pelo encanador e imprima a quantia líquida que deverá ser paga,
//sabendo que são descontados 8% para imposto de renda.

int main(){

int diaTrab;
float porDia = 45.0, valor, imposto; 

printf (" (Uma empresa contrata um encanador a R$ 45,00 por dia. \n Solicite o numero de dias trabalhados pelo encanador e imprima a quantia liquida que devera ser paga, \n sabendo que sao descontados 8%% para imposto de renda.)");


printf("\n\nDias trabalhados: ");
scanf("%d", &diaTrab);

valor = porDia * diaTrab;

printf("\nValor Total: R$%.2f\n", valor);

imposto = valor * 0.92;

printf("\nValor com desconto: R$%.2f", imposto);

return 0;

}
