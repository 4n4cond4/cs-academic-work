#include<stdio.h>
#include<stdlib.h>

//Escreva um programa que leia um valor de despesa de restaurante, o valor da gorjeta 
//(em porcentagem) e o número de pessoas para dividir a conta. Imprima o valor que cada um deve pagar.
//Assuma que a conta será dividida igualmente.	


//exercicio 4 Youtube
int main(){
	
int pessoas;
float despesa, gorjeta, divide;


printf("\t CONTA DE RESTAURANTE");

printf("\n\nNumero de pessoas presentes: ");
scanf("%d", &pessoas);

printf("\nTotal da conta: R$");
scanf("%f", &despesa);

gorjeta = despesa * 0.10;	
printf("\nGorjeta 10%%: R$%.2f\n", gorjeta);

divide = despesa/pessoas;
printf("\nValor por pessoa: R$%.2f", divide);

	
return 0;	
}
