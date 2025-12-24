#include<stdio.h>
#include<stdlib.h>
#define max 10

struct lista{
    int elem[max];
    int n;

};

void crialista (struct lista *li){
    li -> n = 0;
}

int acessarLista (struct lista *li, int k){
    int dado;
    if((k < 0) || (k > li -> n-1)){

        printf("\nElementos fora do limite!\n");
    }
    else{
        dado = li -> elem[k];
        
    }
    return dado;
}

void alterarLista(struct lista *li, int k, int dado){
    if((k < 0) || (k > li -> n-1) || (li -> n > max-1)){
         
        printf("\nElementos fora do limite!\n");
    }
    else {
        li->elem[k] = dado;
    }
}

void insereLista(struct lista *li, int k, int dado){
    if((k < 0) || (k > li -> n-1) || (li -> n > max-1)){

        printf("\nElementos fora do limite!\n");
    }
    else{
        
        for(int i = li->n; i > k; i--){
            li->elem[i] = li->elem[i-1];
        }
    
    li->elem[k] = dado;
    li->n++;
    }
}

void insereFinal(struct lista *li, int dado){

    if(li->n > max-1){
        printf("\nLista cheia!\n");

    }
    else{

        li->elem[li->n] = dado;
        li->n++;
    }
}

void removePos(struct lista *li, int k){
    if((k<0) || (k > li->n-1) || (li->n > max-1)){
        printf("\nElementos fora do limite!\n");
    }
    else{

        for(int i = k; i < li->n-1; i++){
            li->elem[i] = li->elem[i+1];

        }
        li->n--;
    }
}

void removeFim(struct lista *li){
    if(li -> n <= 0){
        printf("\nLista esta vazia!\n");
    }
    else{
        li -> n--;
    }
}

void mostrarLista (struct lista *li){
    printf("\nLista = { ");
    for(int i = 0; i < li->n; i++){
        printf(" %ls", li->elem);

    }
    printf(" }\n");
}

int main(){

    struct lista li;
    int elem, pos, op, i = 0;
    crialista (&li);

    while(i != 2){

        printf("\nDigite:\n 1 - Inserir no final da lista\n 2 - Inserir em uma Posiçao\n 3 - Acessar Elemento\n 4 - Alterar elemento\n 5 - Remove na posição\n 6 - Remove no Final\n 7 - Mostrar lista\n");
        printf("\nDigite: ");
        scanf("%d", &op);

        switch(op){

            case 1:{
                printf("\nEntre com o elemento a ser inserido: ");
                scanf("%d", &elem);
                insereFinal(&li, elem);
                break;
            }
            case 2:{
                printf("\nEntre com o elemento a ser inserido: ");
                scanf("%d", &elem);
                
                printf("\nEntre com a posição do elemento: ");
                scanf("%d", &pos);

                insereLista(&li, pos, elem);
                break;
            }
            case 3:{
                printf("\nEntre com a posição do elemento a ser acesso: ");
                scanf("%d", &pos);

                printf("\nElemento é: %d", acessarLista(&li, pos));
                break;
            }
            case 4:{
                printf("\nEntre com o elemento a ser inserido: ");
                scanf("%d", &pos);
                alterarLista(&li, pos, elem);
                break;
            }
            case 5:{
                printf("\nEntre com a posiçao do elemento: ");
                scanf("%d", &pos);
                removePos(&li, pos);
                break;
            }
            case 6:{
                removeFim(&li);
                break;
            }
            case 7:{
                mostrarLista(&li);
                break;
            }

            default:{
                printf("\nOpção inválida!\n");
            }
        }

        printf("\nDigite: 1 - Continuar/ 2 - Sair\n");
        scanf("%d", &i);

        if(i == 2){
            printf ("\n\n");
         
        }

    }    

    return 0;
}