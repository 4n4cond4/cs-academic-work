#include<stdio.h>
#include<stdlib.h>

typedef struct arvore{
    int info;
    struct arvore *esq;
    struct arvore *dir;
}arvore;

arvore *lerABB(FILE *arq){
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
    no->esq = lerABB(arq);
    no->dir = lerABB(arq);

    fscanf(arq, "%c", &c);
    return no;

    }
}

void imprimePRE(arvore *a){
//PRÉ-ORDEM!
   if (a != NULL){
    
    printf(" %d ", a->info);
    imprimePRE(a->esq);
    imprimePRE(a->dir);

    }
}

void imprimeEOR(arvore *a){
//EM ORDEM!
    if(a != NULL){

    imprimeEOR(a->esq);
    printf(" %d", a->info);
    imprimeEOR(a->dir);   

    }   
}

void imprimePOS(arvore *a){
//PÓS-ORDEM
    if(a != NULL){

    imprimePOS(a->esq);
    imprimePOS(a->dir);
    printf(" %d", a->info);

    }
}

void imprimeELG(arvore *a){
//EM LARGURA!
    if(a == NULL)
        return;

    arvore *fila[100];
    int frente = 0, tras = 0;

    fila[tras++] = a;
        while (frente < tras){
        arvore *atual = fila[frente++];
        printf("%d ", atual->info);

        if (atual->esq) fila[tras++] = atual->esq;
        if (atual->dir) fila[tras++] = atual->dir;
    }  
    printf("\n");    
}

int Existe(arvore *a, int x){
//VERIFICA SE ELEMENTO X EXISTE     
    if(a == NULL){
        return 0;
    }

    else if (a->info == x){
        return 1;
    }

    else if (a->info > x){
        return Existe(a->esq, x);
    }

    else{ 
        return Existe(a->dir, x);
    }
}   

void Destruir(arvore *a){
//LIBERA MEMÓRIA AO ENCERRAR PROGRAMA

    if(a != NULL){

        Destruir(a->esq);
        Destruir(a->dir);
        free(a);
    }
}

int Nivel(arvore *a, int x, int ni){
 //EXIBE NÍVEL DE X ELEMENTO   

    if (a == NULL){
        return 0;
    }

    if (a->info == x){
        return ni;
    }

    int esquerda = Nivel(a->esq, x, ni + 1);                            
    if (esquerda != -1){ 
        return esquerda;
    }

        return Nivel(a->dir, x, ni + 1);
}

arvore *Inserir(arvore *a, int x){
//INSERE UM NÓ X NA ÁRVORE

if(a == NULL){

    a = (arvore*)malloc(sizeof(arvore));

    a->info = x; 
    a->esq = NULL;
    a->dir = NULL;
    }
else if(x <= a->info){

    a->esq = Inserir(a->esq, x);
  }

else {

    a->dir = Inserir(a->dir, x);
    }
    return a;
}

arvore *Remover(arvore *a, int x){
    if (a == NULL) return NULL;

    if (x < a->info) {
        a->esq = Remover(a->esq, x);
    }
    else if (x > a->info) {
        a->dir = Remover(a->dir, x);
    }
    else { 
        if (a->esq == NULL && a->dir == NULL) {
            free(a);
            return NULL;
        }
        else if (a->esq == NULL) {
            arvore *aux = a->dir;
            free(a);
            return aux;
        }
        else if (a->dir == NULL) {
            arvore *aux = a->esq;
            free(a);
            return aux;
        }
        else {
            arvore *aux = a->esq;
            while (aux->dir != NULL) aux = aux->dir;
            a->info = aux->info;
            a->esq = Remover(a->esq, aux->info);
        }
    }
    return a;
}
void folhasMenores(arvore *a, int x){
//IMPRIME FOLHAS MENORES QUE ELEMENTO 'X'    
    if(a == NULL){
        return;
    }
    if(a->esq == NULL && a->dir == NULL){
        if(a->info < x){
            printf(" %d", a->info);
        }
    }
    folhasMenores(a->esq, x);
    folhasMenores(a->dir, x);

}

void Menu(){

    printf("\n\n*****************************************************************************************************\n");
    printf("| %-40s \t| %-40s \t|\n", "1 - Ler uma nova árvore de um arquivo", "5 - Imprimir folhas menores que um valor 'x'");
    printf("| %-40s \t| %-40s \t|\n", "2 - Imprimir a árvore", "6 - Inserir nó 'x' na árvore");
    printf("| %-40s \t| %-40s \t|\n", "3 - Verificar se um elemento 'x' existe", "7 - Remover nó 'x' na árvore");
    printf("| %-40s \t| %-40s \t|\n", "4 - Imprimir o nível do nó", "8 - Sair");
    printf("\n*****************************************************************************************************\n\n");
}

int main(){ 
short int op = 0;
short int escolha;
arvore *raiz = NULL;

printf("\t\t\tÁRVORE BINÁRIA DE BUSCA (ABB)\n\n");

    while (raiz == NULL){
    
        char nomeArq[100];
        FILE *arq;
        printf("\nAntes de começar, você precisa carregar uma árvore.\n");
        printf("Digite o nome do arquivo: ");
        scanf(" %s", &nomeArq);

        arq = fopen(nomeArq, "r");
        if(arq == NULL){

        printf("\nErro ao abri o arquivo! Tente novamente.");
        }
        else {
            raiz = lerABB(arq);
            fclose(arq);
            printf("\nÁrvore carregada com sucesso!\n");

        }
    }
    
while (op != 8){
    Menu();

    printf("\nOpção desejada: ");
    if (scanf("%hd", &op) != 1) {
    printf("\nEntrada inválida! Digite apenas números.\n");
    
    while (getchar() != '\n');
    op = 0; 
    }

switch (op){
        
    case 1:

    printf("\nCarregar nova árvore.\n");

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

    raiz = lerABB(arq);
    fclose(arq);

    printf("\nÁrvore carregada com sucesso!\n");
            break;
    
    case 2:

    printf("\nImprimir Árvore: \n");

        if(raiz == NULL){
            printf("\nA árvore esta vazia!\n");
            break;
        }

    printf("\nDigite '1' - Pré Ordem/ '2' - Em Ordem/ '3' - Pós Ordem/ '4' - Em Largura: ");
    scanf("%hd", &escolha);
     
        if(escolha == 1){
            printf("\nPré Ordem:\n");
            imprimePRE(raiz);
         
        }
        else if(escolha == 2){
            printf("\nEm Ordem:\n");
            imprimeEOR(raiz);
        }
        else if (escolha == 3){
            printf("\nPós Ordem:\n");
            imprimePOS(raiz);
            
        }
        else{
            printf("\nEm Largura:\n");
            imprimeELG(raiz);
        
        }
        break;

    case 3:

    int x;
    printf("Digite o elemento a buscar: ");
    scanf("%d", &x);

    if (Existe(raiz, x))
    printf("\nO elemento %d existe na árvore.\n", x);
    else{
    printf("\nO elemento %d NÃO existe na árvore.\n", x);
    }
        break;

    case 4:

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
    
    case 5:
    if (raiz == NULL){
        printf("\nA árvore está vazia!\n");
        break;
    } 

    int vlr;
    printf("\nDigite um valor: ");
    scanf("%d", &vlr);

    printf("Folhas menores que %d: ", vlr);
    folhasMenores(raiz, vlr);
    printf("\n");
    break;

    case 6: {
    if(raiz == NULL){
        printf("\nA árvore está vazia!\n");
        break;
    }
    int vlr;
    printf("\nDigite um novo nó: ");
     if (scanf("%d", &vlr) != 1) { 
        printf("Entrada inválida.\n");
        while (getchar()!='\n'); 
        break;  
    }

    raiz = Inserir(raiz, vlr);
    printf("Valor %d inserido.\n", vlr);
    break;
    }

    case 7:{
    if(raiz == NULL){
        printf("\nA árvore está vazia!\n");
        break;
    }

    int vlr;
    printf("\nDigite o valor a ser removido: ");
    if (scanf("%d", &vlr) != 1) {
        printf("Entrada inválida.\n"); 
        while (getchar()!='\n'); 
        break;
    }
    if(Existe(raiz, vlr)){
        raiz =  Remover(raiz, vlr);
        printf("Valor %d removido (se existia).\n", vlr);

    } 
    else {
        printf("Valor %d não encontrado.\n", vlr);
    }
    break;
    }

    case 8:
     Destruir(raiz);
     printf("\n...Encerrando o programa. Até mais!\n"); 
    
        default:
        while(op < 1 || op > 8){
        printf("\nOpção inválida! Tente novamente.");
        printf("\n");
        break;
            }
        }    
    }         
    
    return 0;
 }