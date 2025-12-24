#include <stdio.h>
#include <stdlib.h>

int tam;

typedef struct Node {
    int info;
    struct Node *prox;
} Node;

// Função inicializadora
void iniciaLista(Node *li) {
    li = NULL;
    tam = 0;
}

Node* aloca() {
    Node *novo = (Node*) malloc(sizeof(Node));
    if (!novo) {
        printf("\nNão foi possível alocar!\n");
        exit(1);
    } else {
        printf("\nDigite o elemento desejado: ");
        scanf("%d", &novo->info);
        novo->prox = NULL;
    }
    return novo;
}
