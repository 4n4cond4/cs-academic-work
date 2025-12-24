#include <stdio.h>
#include <stdlib.h>  
#define MAX 100 


typedef struct minHeap{
    int info[MAX];
    int tm;
   } minHeap;

void inicializar(minHeap *h) {
    h->tm = 0;
}

void trocar(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void subir(minHeap *h, int i) {
    int pai = ((i - 1) / 2.0);
    while (i > 0 && h->info[i] < h->info[pai]) {
        trocar(&h->info[i], &h->info[pai]);
        i = pai;
        pai = ((i - 1) / 2.0);
    }
}

void descer(minHeap *h, int i) {
    int menor, esq, dir;
    while (1) {
        esq = (2 * i + 1);
        dir = (2 * i + 2);
        menor = i;

        if (esq < h->tm && h->info[esq] < h->info[menor]) {
            menor = esq;
        }
        if (dir < h->tm && h->info[dir] < h->info[menor]) {
            menor = dir;
        }

        if (menor == i) break;

        trocar(&h->info[i], &h->info[menor]);
        i = menor;
    }
}

void inserir(minHeap *h, int vlr) {
    if (h->tm == MAX) {
        printf("Heap cheia! Nao e possivel inserir.\n");
        return;
    }
    h->info[h->tm] = vlr;
        h->tm++;
    subir(h, h->tm);
    printf("Elemento %d inserido.\n", vlr);
}

void remover(minHeap *h) {
    if (h->tm == 0) {
        printf("Heap vazia! Nao ha elementos para remover.\n");
        return;
    }
    int removido = h->info[0];
    h->info[0] = h->info[h->tm - 1];
    h->tm--;
    descer(h, 0);
    printf("Elemento removido: %d\n", removido);
}

void imprimir(minHeap *h) {
    if (h->tm == 0) {
        printf("Heap vazia.\n");
        return;
    }
    printf("Heap: ");
    for (int i = 0; i < h->tm; i++) {
        printf("%d ", h->info[i]);
    }
    printf("\n");
}

void Destruir(minHeap *h) {
    if (h != NULL) {
        h->tm = 0; 
    }
}


void Menu (){
        printf("\n\n****************************************************************************\n");
        printf("| %-40s \t| %-40s \t|\n", "1. Inserir um elemento na heap", "2. Remover um elemento da heap");
        printf("| %-40s \t| %-40s \t|\n", "3. Imprimir a heap", "4. Sair" );
        printf("\n\n****************************************************************************\n");
    }       

int main() {

    minHeap heap;
    inicializar(&heap);

    int op, vlr;

    while(op != 4) {
        
        Menu();  
           printf("Opção desejada: ");
            
            if (scanf("%d", &op) != 1) {  
            printf("Opção inválida! Digite um número.\n");
            while (getchar() != '\n'); 
            op = 0; 
            continue;
            }
        switch (op) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &vlr);
                inserir(&heap, vlr );
                break;
            case 2:
                remover(&heap);
                break;
            case 3:
                imprimir(&heap);
                break;
            case 4:
                printf("\nEncerrando o programa...\n");
                Destruir(&heap);
                break;

            default:
                printf("Opção inválida!\n");
                break;
            }
        }
    
    return 0;
}
