#include<stdio.h>  
#include<stdlib.h>

//4) Desenvolva um programa em linguagem C que contenha uma função sem valor de
//retorno (do tipo void) capaz de receber dois números inteiros como parâmetros,
//identificados como A e B.
//Requisitos:
//▪ A função deve calcular a soma entre os valores de A e B.
//▪ O resultado da soma deve ser armazenado na variável A.
//▪ A função não deve retornar nenhum valor (void), mas deve modificar diretamente o valor da variável A
//por meio do uso de ponteiros.
//▪ Após a chamada da função, o programa principal (main) deve imprimir os valores atualizados de A e
//B.

//Exemplo de comportamento esperado:
//▪ Se o usuário informar A = 5 e B = 3, após a execução da função, o valor de A deve ser 8 e B deve
//permanecer 3.

void RECEBA (int *a, int *b){

int soma = *a + *b;
*a = soma;

}
void menu(){

     printf("ALTERANDO VALORES\n");
}

int main(){
int valor[2];

  menu();
    
for(int i = 0; i<2; i++){
    printf("\nDigite o %do valor inteiro: ", i+1);
    scanf("%d", &valor[i]);
    }
    
    RECEBA (&valor [0], valor [1]);
   
    printf("\n Valor 1 = %d", valor[0]);
   
    printf("\n Valor 2 = %d", valor[1]);
    
    printf("\n");
    return 0;
}
