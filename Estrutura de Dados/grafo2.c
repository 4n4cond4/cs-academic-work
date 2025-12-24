#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int destino;
    int custo;
    struct lista *prox;
} lista;

void inicializar(lista **g, int n) {
    for (int i = 0; i <= n; i++)
        g[i] = NULL;
}

lista *inserirLista(lista *l, int destino, int custo) {
    lista *novo = (lista *)malloc(sizeof(lista));
    novo->destino = destino;
    novo->custo = custo;
    novo->prox = l;
    return novo;
}

void inserirAresta(lista **g, int origem, int destino, int custo) {
    g[origem] = inserirLista(g[origem], destino, custo);
}

lista *removerLista(lista *l, int destino) {
    if (l == NULL)
        return NULL;

    if (l->destino == destino) {
        lista *aux = l->prox;
        free(l);
        return aux;
    }

    l->prox = removerLista(l->prox, destino);
    return l;
}

void removerAresta(lista **g, int origem, int destino) {
    g[origem] = removerLista(g[origem], destino);
}


void imprimirLista(lista *l) {
    while (l != NULL) {
        printf(" -> (%d, custo: %d)", l->destino, l->custo);
        l = l->prox;
    }
}

void imprimirGrafo(lista **g, int n) {
    printf("\nGrafo:\n");
    for (int i = 1; i <= n; i++) {
        printf("Vértice %d:", i);
        imprimirLista(g[i]);
        printf("\n");
    }
}

int grauSaida(lista *l) {
    int cont = 0;
    while (l != NULL) {
        cont++;
        l = l->prox;
    }
    return cont;
}

int grauEntrada(lista **g, int n, int v) {
    int cont = 0;
    for (int i = 1; i <= n; i++) {
        lista *l = g[i];
        while (l != NULL) {
            if (l->destino == v)
                cont++;
            l = l->prox;
        }
    }
    return cont;
}

void imprimirGraus(lista **g, int n, int v) {
    printf("\nGrau de saída do vértice %d: %d", v, grauSaida(g[v]));
    printf("\nGrau de entrada do vértice %d: %d\n", v, grauEntrada(g, n, v));
}

int ehCompleto(lista **g, int n) {
    for (int i = 1; i <= n; i++) {
        int grau = grauSaida(g[i]);
        if (grau != n - 1)
            return 0;
    }
    return 1;
}

int existe(int *vet, int valor, int n) {
    for (int i = 0; i < n; i++)
        if (vet[i] == valor)
            return 1;
    return 0;
}

void caminhos(int *vet, int pos, int destino, lista **g) {
    if (vet[pos - 1] == destino) {
        for (int i = 0; i < pos; i++)
            printf("%d ", vet[i]);
        printf("\n");
        return;
    }

    lista *l = g[vet[pos - 1]];
    while (l != NULL) {
        if (!existe(vet, l->destino, pos)) {
            vet[pos] = l->destino;
            caminhos(vet, pos + 1, destino, g);
        }
        l = l->prox;
    }
}

int menor(int a, int b) {
    if (a == -1) return b;
    if (b == -1) return a;
    return (a < b ? a : b);
}

int caminhoMaisCurto(lista **g, int n, int origem, int destino) {
    int *dist = (int *)malloc((n + 1) * sizeof(int));
    int *fila = (int *)malloc((n + 1) * sizeof(int));
    int frente = 0, tras = 0;

    for (int i = 1; i <= n; i++)
        dist[i] = -1;

    dist[origem] = 0;
    fila[tras++] = origem;

    while (frente < tras) {
        int atual = fila[frente++];
        lista *l = g[atual];

        while (l != NULL) {
            if (dist[l->destino] == -1) {
                dist[l->destino] = dist[atual] + 1;
                fila[tras++] = l->destino;
            }
            l = l->prox;
        }
    }

    int resposta = dist[destino];
    free(dist);
    free(fila);
    return resposta;
}

int caminhoMenorCusto(lista **g, int n, int origem, int destino) {
    int *custo = (int *)malloc((n + 1) * sizeof(int));
    int *visitado = (int *)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++)
        custo[i] = 999999;

    custo[origem] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;
        for (int j = 1; j <= n; j++)
            if (!visitado[j] && (u == -1 || custo[j] < custo[u]))
                u = j;

        if (custo[u] == 999999)
            break;

        visitado[u] = 1;

        lista *l = g[u];
        while (l != NULL) {
            if (custo[l->destino] > custo[u] + l->custo)
                custo[l->destino] = custo[u] + l->custo;
            l = l->prox;
        }
    }

    int resultado = custo[destino];
    free(custo);
    free(visitado);
    return resultado;
}

void destruirLista(lista *l) {
    while (l != NULL) {
        lista *aux = l;
        l = l->prox;
        free(aux);
    }
}

void destruirGrafo(lista **g, int n) {
    for (int i = 1; i <= n; i++)
        destruirLista(g[i]);
    free(g);
}


int main() {

    char op = 'S';
    int origem, destino, custo;
    int n, m;

    while(op != 'n' && op != 'N'){
    printf("Digite o número de vértices e arestas: ");
    scanf("%d %d", &n, &m);

    lista **g = (lista **)malloc((n + 1) * sizeof(lista *));
    inicializar(g, n);

    printf("Digite as arestas (origem destino custo):\n");
        scanf("%d %d %d", &origem, &destino, &custo);
        inserirAresta(g, origem, destino, custo);

    imprimirGrafo(g, n);

    int v;
    printf("\nDigite o vértice para verificar graus: ");
    scanf("%d", &v);
    imprimirGraus(g, n, v);

    if (ehCompleto(g, n))

        printf("\nO grafo é completo.\n");
    else
        printf("\nO grafo não é completo.\n");

    printf("\nDigite a origem e o destino: ");
    scanf("%d %d", &origem, &destino);

    int *vet = (int *)malloc((n + 1) * sizeof(int));
    vet[0] = origem;

    printf("\nCaminhos de %d até %d:\n", origem, destino);
    caminhos(vet, 1, destino, g);

    printf("\nMenor número de arestas: %d\n", caminhoMaisCurto(g, n, origem, destino));
    printf("Menor custo: %d\n", caminhoMenorCusto(g, n, origem, destino));

    printf("\nDeseja continuar? S/N: ");
    scanf(" %c", &op);

    free(vet);
    destruirGrafo(g, n);
  
    }
    printf("\n...Encerrando o programa. Até mais!\n");
    return 0;
}
