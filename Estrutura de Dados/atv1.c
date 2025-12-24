#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


//Implemente um programa que apresente na tela o seguinte menu de opções:

//1- Ler uma árvore de um arquivo fornecido pelo usuário

//2- Imprimir a árvore (opções: pré-ordem; em-ordem; pós-ordem; e em largura)

//3- Verificar se um elemento x existe na árvore

//4- Contar o número de elementos na árvore

//5- Imprimir os nós folhas da árvore

//6- Verificar se uma árvore está ordenada

//7- Verificar se uma árvore é completa

//8- Imprimir o nível a qual o nó x pertence

//9- Sair





typedef struct arvore{

int info;
struct arvore *esq;
struct arvore *dir;

}arvore;

arvore *No(int vlr){
//CRIA NOVOS NÓS
arvore *n = (arvore*)malloc(sizeof(arvore));
n->info = vlr;
n->esq = n->dir = NULL;
return n;

}

arvore *Ler(FILE *arq){
//LER ÁRVORE EM MEMÓRIA
int n;
char c;

fscanf(arq, "%c", &c);
fscanf(arq, "%d", &n);

if(n == -1){

    fscanf(arq, "%c", &c);
    return NULL;
}

else {

    arvore *no = (arvore*)malloc(sizeof(arvore));

    no->info = n;
    no->esq = Ler(arq);
    no->dir = Ler(arq);
    
    fscanf(arq, "%c", &c);
    return no;
    }
}

int Ordenada(arvore *a, int min, int max) {
//VERIFICA SE A ARVORE ESTÁ ORDENADA    
    if (a == NULL)
     return 1;

    if (a->info < min || a->info > max)
        return 0;

    return Ordenada(a->esq, min, a->info - 1) &&
           Ordenada(a->dir, a->info + 1, max);
}



void imprimirPRE(arvore *a){
//PRÉ-ORDEM!
if (a != NULL){

    printf("%d ", a->info);
    imprimirPRE(a->esq);
    imprimirPRE(a->dir);
    
    }
}
void imprimirEOR(arvore *a){
//EM ORDEM!
if (a != NULL){

    imprimirEOR(a->esq);
    printf("%d ", a->info);
    imprimirEOR(a->dir);
    
    }
}

void imprimirPOS(arvore *a){
//PÓS-ORDEM!
if(a != NULL){

  imprimirPOS(a->esq);
  imprimirPOS(a->dir);
  printf("%d ", a->info);
    
    }
}

void imprimirELG(arvore *a) {
//EM LARGURA!    
if (a == NULL) 
    return;

    arvore *fila[100];
    int frente = 0, tras = 0;

    fila[tras++] = a;

    while (frente < tras) {
        arvore *atual = fila[frente++];
        printf("%d ", atual->info);

        if (atual->esq) fila[tras++] = atual->esq;
        if (atual->dir) fila[tras++] = atual->dir;
    }
    printf("\n");
}

int Existir(arvore *a, int x){
//VERIRIFICA SE UM ELEMENTO X EXISTE
if(a == NULL)
        return 0;
  
else {

    if(a->info == x){
        return 1;
    }
     
else{

    return Existir (a->esq, x) || Existir (a->dir, x);
    printf("\n O elemento existe!");
        }
    }
}

 int Completa(arvore *a) {
//VERIFICA SE A ÁRVORE ESTÁ COMPLETA    
    if (a == NULL) 
        return 1;

    arvore *fila[100]; 
    int frente = 0, tras = 0;
    int fim = 0;

    fila[tras++] = a;

    while (frente < tras) {
        arvore *atual = fila[frente++];

        if (atual == NULL) {
            fim = 1; 
            
        } 
        else {
            if (fim) return 0;
            fila[tras++] = atual->esq;
            fila[tras++] = atual->dir;
        }
    }

    return 1;
}

int Contar(arvore *a){
//CONTA A QUANTIDADE DE ELEMENTOS
    if(a == NULL){
        return 0;
    }
    else{

        return 1 + Contar(a->esq) + Contar(a->dir); 
    }
}
void Folhas(arvore *a) {
//EXIBE NÓS FOLHAS    
    if (a == NULL) {
        return;
    }

    if (a->esq == NULL && a->dir == NULL) {

        printf("%d ", a->info);
    }
    Folhas(a->esq);
    Folhas(a->dir);
}

int Nivel(arvore *a, int x, int nivel) {
//EXIBE O NIVEL DO NÓ
    if (a == NULL){
     return -1;
    }

    if (a->info == x) 
    return nivel;

    int esq = Nivel(a->esq, x, nivel + 1);

    if (esq != -1) 
    return esq;

    return Nivel(a->dir, x, nivel + 1);
}

void Destruir(arvore *a){
//LIBERA MEMÓRIA AO TERMINAR        
    if(a != NULL){

        Destruir(a->esq);
        Destruir(a->dir);
        free(a);
    }
}

void Menu() {

    printf("\n\n*****************************************************************************************************\n");
    printf("| %-40s \t| %-40s \t|\n", "1 - Ler uma nova árvore de um arquivo", "6 - Verificar se a árvore está ordenada");
    printf("| %-40s \t| %-40s \t|\n", "2 - Imprimir a árvore", "7 - Verificar se a árvore é completa");
    printf("| %-40s \t| %-40s \t|\n", "3 - Verificar se um elemento x existe", "8 - Imprimir o nível do nó x");
    printf("| %-40s \t| %-40s \t|\n", "4 - Contar o número de elementos na árvore", "9 - Sair");
    printf("| %-40s \t| %-40s \t|\n", "5 - Imprimir nós folhas", "");
    printf("\n*****************************************************************************************************\n\n");
}

int main(){
short int op = 0;
short int escolha; 
arvore *raiz = NULL;   

printf("\t\t\tÁRVORE DE ORDENAÇÃO\n\n");

 while (raiz == NULL) {
        char nomeArq[100];
        FILE *arq;

        printf("\nAntes de começar, você precisa carregar uma árvore.\n");
        printf("Digite o nome do arquivo: ");
        scanf("%s", nomeArq);
    
        arq = fopen(nomeArq, "r");
        if (arq == NULL) {
            printf("\nErro ao abrir o arquivo! Tente novamente.\n");
        } else {
            raiz = Ler(arq);
            fclose(arq);
            printf("\nÁrvore carregada com sucesso!\n");
        }
    }
while(op != 9){

Menu();

printf("\nOpção desejada: ");

if (scanf("%hd", &op) != 1) {
    printf("\nEntrada inválida! Digite apenas números.\n");
    
    while (getchar() != '\n');
    op = 0; 
}


switch (op)
{

case 1: {
    char nomeArq[100];
    FILE *arq;

    if (raiz != NULL) {
        Destruir(raiz); 
        raiz = NULL;
    }

    printf("\nDigite o nome do arquivo: ");
    scanf("%s", nomeArq);

    arq = fopen(nomeArq, "r");
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        break;
    }

    raiz = Ler(arq);
    fclose(arq);

    printf("\nÁrvore carregada com sucesso!\n");
    break;
}

case 2:
    
    printf("\nImprimir árvore: \n");

      if (raiz == NULL){
        printf("\nA árvore está vazia!\n");
        break;
    }
    printf("\nDigite '1' - Pré Ordem/ '2' - Em Ordem/ '3' - Pós Ordem/ '4' - Em Largura: ");
    scanf("%hd", &escolha);
     
        if(escolha == 1){
            printf("\nPré Ordem:\n");
            imprimirPRE(raiz);
            
        }
        else if(escolha == 2){
            printf("\nEm Ordem:\n");
            imprimirEOR(raiz);
        }
        else if (escolha == 3){
            printf("\nPós Ordem:\n");
            imprimirPOS(raiz);
            
        }
        else{
            printf("\nEm Largura:\n");
            imprimirELG(raiz);
        
        }
        break;

case 3:

int x;
    printf("Digite o elemento a buscar: ");
    scanf("%d", &x);

    if (Existir(raiz, x))
    printf("\nO elemento %d existe na árvore.\n", x);
    else{
    printf("\nO elemento %d NÃO existe na árvore.\n", x);
    }
    break;

case 4:

    printf("\nExistem %d elementos na árvore.\n", Contar(raiz));
    break;

case 5:

    if (raiz == NULL) {
        printf("\nA árvore está vazia!\n");
        break;
    }

    printf("\nNós folhas: ");
    Folhas(raiz);
    printf("\n");
    break;

case 6:

    printf("\nVerificando a ordem:\n");
    if (raiz == NULL) {
        printf("\nA árvore está vazia!\n");
        break;
    }
    else if (Ordenada(raiz, INT_MIN, INT_MAX)){

        printf("\nA árvore está ordenada (BST).\n");
    }
    else
        printf("\nA árvore NÃO está ordenada.\n");
    break;

case 7:

    if (raiz == NULL) {
        printf("\nA árvore está vazia!\n");
        break;
    }
   else if (Completa(raiz)){
        printf("\nA árvore é completa.\n");
   }
    else
        printf("\nA árvore NÃO é completa.\n");
    break;

case 8:

    if (raiz == NULL) {
        printf("\nA árvore está vazia!\n");
        break;
    }
    int y;
    printf("\nDigite o valor do nó: ");
    scanf("%d", &y);

    int nivel = Nivel(raiz, y, 0);

    if (nivel != -1)
        printf("O nó %d está no nível %d.\n", y, nivel);
    else
        printf("O nó %d NÃO existe na árvore.\n", y);
    break;

case 9:

    Destruir(raiz);
    printf("\n...Encerrando o programa. Até mais!\n"); 
     
    break;
        
    default:
    printf("\n");
    break;
        }   
    }     
      
 return 0;  
}




    


