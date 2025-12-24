#include<stdio.h>   
#include<stdlib.h>
#define max 100

typedef struct {

    int final, inicio;
    int elem[max];

}Fila;

//ADICIONANDO FUNÇÃO PARA CONTEXTUALIZAR VARIÁVEIS

void iniciaFila (Fila *f){ 

f -> inicio = 0;
f -> fim = -1;

}

//FUNÇÃO DE REMOÇÃO
void removeFila (Fila *f){

    if(f -> fim < 0){
        printf("\nA fila está vazio!\n");
    }
    else { 

        for(int i = 0; i < f -> fim; i++){
            f -> elem[i] = elem[i+1];

        }
        f -> fim--;
    }

}