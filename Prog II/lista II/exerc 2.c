#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct {

    int elem[max];
    int count;
} Lista;


//INICIANDO FUNÇÃO PARA CONTEXTUALIZAR VARIÁVEIS
void iniciaLista (Lista *l){
    l -> count = 0;

}

//FUNÇÃO PARA INSERIR UM ELEMENTO EM DETERMINADA POSIÇÃO
void inserirElem (Lista *l, int pos, int vlr){

    if ((pos < 0) || (pos > l -> count) || (l -> count > max-1)){
        printf("\nErro! Elemento fora da posição");
        
    }
    else {
        for(int i = l -> count; i > pos; i--){
            l -> elem[i] = l -> elem[i-1];
        }
        l -> elem[pos] = vlr;
        l -> count;
    }

}
