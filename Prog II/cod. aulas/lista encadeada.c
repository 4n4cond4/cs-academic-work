#include<stdlib.h>
#include<stdio.h>


int tam;

struct Node
{
    int info;
    struct Node *prox;
};

typedef struct  Node node;

void inicia_lista(node *li){

    li -> prox = NULL;
    tam = 0;

}

node *aloca(){

    node *novo = (node*) malloc(sizeof(node));

    if(!novo){
    printf("\nnão foi possivel alocar!");
    exit(1);
    }

    else{
        printf("\nDigite o valor do elemento: ");
        scanf("%d", &novo->info);
    }
    return novo;
}

int verifica_Vazia(node *li){

    if(li->prox == NULL){

        return 1;
    }
        else{
            return 0;
    }
}

void insereInicio (node *li){
    node *novo = aloca();
    node *Antcabeca = li -> prox;

    li->prox = novo;
    novo->prox = Antcabeca;
    tam++;
}

void insereFim(node *li){

    node *novo  = aloca();
    novo->prox = NULL;

    if(verifica_Vazia(li)){
        li->prox = novo;

    }
    else{
        node *tmp = li->prox;

        while (tmp ->prox != NULL){
            tmp = tmp->prox;
        }
        tmp ->prox = novo;
    }
    tam++;
}

void inserePos(node *li, int pos){
    int cont;
    if(pos > 0 && pos <= tam + 1){
        if(pos == 1){
            insereInicio(li);
        }
        else{
            node *atual = li->prox;
            node *anterior = li;
            node *novo = aloca();

            for(cont = 1; cont < pos; cont++){
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = novo;
            novo->prox = atual;
            tam++;
        }
    } else{
        printf("\nElemento invalido!\n\n");
    }
}
node *retiraInicio(node *li){
    if(li->prox == NULL){
        printf("\nA lista esta vazia!");
        return NULL;

    }
    else{
        node *tmp = li->prox;
        li->prox = tmp->prox;
        tam--;
    }
}

node *retiraFim(node *li){
    if(li->prox == NULL){
        printf("Lista vazia\n");
        return NULL;
    }
    else{
        node *ultimo = li->prox;
        node *penultimo = li;

        while (ultimo ->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo-> prox;
        }
        
        penultimo -> prox = NULL;
        tam --;
        return ultimo;

    }
}
node *retiraPos(node *li, int pos){

int cont;
    if(pos > 0 && pos <= tam){
        
        if(pos == 1){
            return retiraInicio(li);
        }
        else{

            node *atual = li->prox;
            node *anterior = li;
            for(cont = 1; cont < pos; cont++){
                anterior = atual;
                atual = atual -> prox;

            }

            anterior->prox = atual->prox;
            tam--;
            return atual;

        }
   
    }
    else{
        printf("\nElemento invalido\n");
        return NULL;
    }
}

void exibe(node *li){

    printf("\n------------------------------\n");

    if(verifica_Vazia(li)){
        printf("\nLista vazia!\n");
        return;
    }
    node *tmp = li->prox;
    printf("\nLista: ");
    while (tmp != NULL){
        printf("%d", tmp ->info);
        tmp = tmp->prox;
    }
    printf("\nOrdem de inserção: ");

    for(int cont = 0; cont < tam; cont++){
        printf("%d",cont + 1);
    }
    printf("\n\n");

}
void libera(node *li){
    node *atual = li->prox;
    while (atual != NULL){

        node *prox = atual ->prox;
        free(atual);
        atual = prox;
    }
    li->prox = NULL;
    tam = 0;
}

int main(){

node *li = (node*) malloc(sizeof(node));


node *tmp;

int i=0;
int op, pos;

inicia_lista(li);


while( i != 2){

    printf(" 1-Insere Inicio:\n 2-Insere Fim:\n 3-Insere Posição:\n 4-Remove Inicio:\n 5-Remove Fim:\n 6-Remove Posição:\n 7-Exibe Lista:\n 8-Excluir Lista:");
    printf("\n Digite: ");
    scanf("%d", &op);

    if(op == 1){
        insereInicio(li);

    }
    else if(op == 2){
        insereFim(li);
   
    }else if(op == 3){
        printf("\nDigite a posição a ser inserida: ");
        scanf("%d", &pos);
        inserePos(li, pos);
    }

    else if(op == 4){
        tmp = retiraInicio(li);
        if(tmp != NULL){
            printf("\nVAlor Retirado %d\n", tmp->info);
            free(tmp);
        }

    } else if(op == 5){
        tmp = retiraFim(li);
        if(tmp != NULL){
            printf("\nValor Retirado %d\n", tmp->info);
            free(tmp);
        }
    } else if(op == 6){
        printf("\nDigite a posião a ser removida: ");
        scanf("%d", &pos);
        tmp = retiraPos(li, pos);
      
        if(tmp != NULL){
        printf("\nValor Retirado %d\n", tmp->info);
        free(tmp);
        }
    } else if(op == 7){
        exibe(li);

    } else if(op == 8){
        libera(li);
    }

    printf("\nDigite 1- Continuar \ 2 - Sair\n");
    scanf("%d", &i);

    if(i != 2){
        printf("\n---------------------------\n");
   
    } else if(i == 2){
        libera(li);
       }
    }
    return 0;
}