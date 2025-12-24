#include<stdio.h>
#include<stdlib.h>

//Inserir uma aresta no grafo  

//RemoverLista uma aresta do grafo

//Imprimir grafo 

//Imprimir os graus de entrada e saída de um vértice

//Verificar se um grafo é completo

//Imprimir todos os caminhos entre uma origem e um destino 

//Imprimir o caminho mais curto (com menor número de arestas)

//Imprimir o caminho de menor custo (menor soma dos custos das arestas)

//Sair (destruir?)

typedef struct lista{

    int destino;
    int custo;
    struct lista *prox;  
    
}lista;

void inicializar(lista **g, int n){
int i;

    for(i=0; i<=n; i++)
    g[i] = NULL;
       
}

lista *InserirLista(lista *l, int d, int c){

    lista *no = (lista*)malloc(sizeof(lista));

    no->destino = d;
    no->custo = c;
    no->prox = l;
    return no;
}

void InserirAresta(lista **g, int origem, int destino, int custo){

    g[origem] = InserirLista(g[origem], destino, custo);

}

lista *RemoverLista(lista *l, int d){

if(l == NULL)
    return NULL;

  if(l->destino == d){  
    lista *aux = l->prox;
    free(l);
    return aux;
    }
l->prox = RemoverLista(l->prox, d);
return l;

}

void RemoverAresta(lista **g, int origem, int destino){

g[origem] = RemoverLista(g[origem], destino);

}

int existe(int *vet, int valor, int n){
    int i;
    for(i=0; i<n; i++)
        if(vet[i] == valor)
            return 1;
    return 0;
}

void caminhos (int *vet, int pos, int destino, lista **g){

    if(vet [pos-1] == destino)
    {
        int i;
        for(i=0; i<pos; i++){
            printf(" %d ", vet[i]);
            printf("\n");
            }
        } 

    else
    {
        lista *l = g[vet[pos-1]];
        while (l != NULL)
        {
        //CRIAR FUNÇÃO VERIFICANDO EXISTENCIA DE ELEMENTO NA lista    
          if(!existe(vet, l->destino, pos))  
            {
                vet[pos] = l->destino;
                caminhos(vet, pos+1, destino, g);
            }
        l = l->prox;
        }    
    }
}

void ImprimirLista(lista *l){
    if(l != NULL){
        printf (" - (%d, %d)", l->destino, l->custo);
        ImprimirLista(l->prox);

    }
}

void ImprimirGrafo(lista **g, int n){

int i;
printf("\nGrafo: ");
    for(i=1; i<=n; i++){
        printf("\n\t%d", i);
        ImprimirLista(g[i]);
        printf("\n");
    }
}

void Destruirlista(lista *l){
    if(l != NULL){

      lista *aux = l;
      l = l->prox;  
      free(aux);      
    }
}

void DestruirGrafo(lista **g, int n){

int i; 

for(i=0; i<=n; i++)
    Destruirlista(g[i]);
    free(g);
}


int main(){
int *vet, n, m;

int orig, dest, custo;

printf("Digite o numero de vertices e arestas: ");
scanf("%d%d", &n, &m);

lista **g = (lista**)malloc((n+1) * sizeof(lista*));
inicializar(g, n);

printf("Digite as arestas: \n");
scanf("%d %d %d", &orig, &dest, &custo);
InserirAresta(g, orig, dest, custo);

ImprimirGrafo(g, n);

printf("Digite a origem e o destino: ");
scanf("%d%d", &orig, &dest);

vet = (int*)malloc((n+1) * sizeof(int));
vet[0] = orig;

printf("\nCaminhos de %d até %d: ", orig, dest);
caminhos(vet, 1, dest, g);

return 0;
}