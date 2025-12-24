#include<stdio.h>
#include<stdlib.h>

typedef struct avl{

    int info;
    int FB;
    struct avl *esq;
    struct avl *dir;

}avl;

int altura(avl *a){

    if(a == NULL){
        return 0;       
  }

    int he = altura(a->esq);
    int hd = altura(a->dir);

    return (he > hd ? he : hd) +1;
}

void ajustarFB(avl *a){
//AJUSTA FATOR BALANCEAMENTO     
    if(a != NULL){
        int he = altura(a->esq);
        int hd = altura(a->dir);
        a->FB =  hd-he;    

        ajustarFB(a->esq);
        ajustarFB(a->dir);

    }
}

avl *lerArvore(FILE *arq){
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

    avl *no = (avl*)malloc(sizeof(avl));

    no->info = n;
    no->esq = lerArvore(arq);
    no->dir = lerArvore(arq);

    fscanf(arq, "%c", &c);
    return no;

    }
}

avl *lerAVL(FILE *arq){
    avl *a = lerArvore(arq);
    ajustarFB(a);
    return a; 
    }

void imprimePRE(avl *a){
//PRÉ-ORDEM!
   if (a != NULL){
    
    printf(" %d ", a->info);
    imprimePRE(a->esq);
    imprimePRE(a->dir);

    }
}

void imprimeEOR(avl *a){
//EM ORDEM!
    if(a != NULL){

    imprimeEOR(a->esq);
    printf(" %d", a->info);
    imprimeEOR(a->dir);   

    }   
}

void imprimePOS(avl *a){
//PÓS-ORDEM
    if(a != NULL){

    imprimePOS(a->esq);
    imprimePOS(a->dir);
    printf(" %d", a->info);

    }
}

void imprimeELG(avl *a){
//EM LARGURA!
    if(a == NULL)
        return;

    avl *fila[100];
    int frente = 0, tras = 0;

    fila[tras++] = a;
        while (frente < tras){
        avl *atual = fila[frente++];
        printf("%d ", atual->info);

        if (atual->esq) fila[tras++] = atual->esq;
        if (atual->dir) fila[tras++] = atual->dir;
    }  
    printf("\n");    
}

int Existe(avl *a, int x){
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

void Destruir(avl *a){
//LIBERA MEMÓRIA AO ENCERRAR PROGRAMA

    if(a != NULL){

        Destruir(a->esq);
        Destruir(a->dir);
        free(a);
    }
}

int Nivel(avl *a, int x, int ni){
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

avl *RotacaoEsqSimples(avl *r){

    avl *a = r;
    avl *b = a->dir;

    a->dir = b->esq;
    b->esq = a;
    if(b->FB == 1)
    {
        a->FB = 0;
        b->FB = 0;
    }
    else
    {
        a->FB = 1;
        b->FB = -1;
    }
    r = b;

    return r;
    }
    
avl *RotacaoEsqDupla(avl *r){

    avl *a = r;
    avl *c = a->dir;
    avl *b = c->esq; 

    c->esq = b->dir;
    a->dir = b->esq;
    b->esq = a;
    b->dir = c;

switch(b->FB)
{
case -1:
    a->FB = 0;
    c->FB = 1;
break;

case 0:
    a->FB = 0;
    c->FB = 0;
break;

case +1:
    a->FB = -1;
    c->FB = 0;
break;
}

    b->FB = 0;
    r = b;
return r;
}

avl *RotacaoEsq(avl *r){

    if(r->dir->FB == -1)
        r = RotacaoEsqDupla(r);
    
    else 

        r = RotacaoEsqSimples(r);

    return r;
}

avl *RotacaoDirSimples(avl *r){

avl *a = r->esq;
avl *b = r;
    b->esq = a->dir;
    a->dir = b;
if (a->FB == -1)
{
    a->FB = 0;
    b->FB = 0;
}
else{
    a->FB = 1;
    b->FB = -1;
    }
r = a;
return r;
}

avl *RotacaoDirDupla(avl *r){

avl *c = r;
avl *a = c->esq;
avl *b = a->dir;
    c->esq = b->dir;
    a->dir = b->esq;
    b->esq = a;
    b->dir = c;

switch(b->FB)
{
case -1:
    a->FB = 0;
    c->FB = 1;
break;

case 0:
    a->FB = 0;
    c->FB = 0;
break;

case +1:
    a->FB = -1;
    c->FB = 0;
break;
}

    b->FB = 0;
    r = b;
return r;
}

avl *RotacaoDir (avl *r){

    if (r->esq->FB == 1)
      r = RotacaoDirDupla(r);

    else

      r = RotacaoDirSimples(r);
      
    return r;
}

avl *Inserir(avl *r, int x, int *hMudou){
    if(r == NULL){

    r = (avl*)malloc(sizeof(avl));
    r->info = x;
    r->esq = NULL;
    r->dir =  NULL;
    r->FB = 0;   
    *hMudou = 1;    
    }
   
    else{
        if(x <= r->info){
            r->esq = Inserir(r->esq, x, hMudou);
            if(*hMudou == 1){
                switch (r->FB)
                {
                case -1:
                    r = RotacaoDir(r);
                    *hMudou = 0;
                    break;
                
                case 0:
                    r->FB = -1;
                    *hMudou = 1;
                    break;
                
                case +1:
                    r->FB = 0;
                    *hMudou = 0;
                    break;
                }
            }
        }
        else{

         r->dir = Inserir(r->dir, x, hMudou);   
         if(*hMudou == 1){

            switch (r->FB)
            {
            case -1:
                r->FB = 0;
                *hMudou = 0;
                break;
            
            case 0:
                r->FB = +1;
                *hMudou = 0;
                break;
            
            case +1:
                r = RotacaoEsq(r);
                *hMudou = 0;
                break;
                }
            }   
        }
    }

    return r;
}

avl *Remover(avl *r, int x, int *hMudou) {
    if (r == NULL) {
        *hMudou = 0;
        return NULL;
    }

    if (x < r->info) {  
        // remover na subárvore esquerda
        r->esq = Remover(r->esq, x, hMudou);

        if (*hMudou == 1) {
            switch (r->FB) {
                case -1:
                    r->FB = 0;
                    *hMudou = 1;
                    break;
                case 0:
                    r->FB = 1;
                    *hMudou = 0;
                    break;
                case +1: {
                    int aux = r->dir->FB;
                    r = RotacaoEsq(r);
                    *hMudou = (aux != 0);
                    break;
                }
            }
        }
    } 
    else if (x > r->info) {  
        // remover na subárvore direita
        r->dir = Remover(r->dir, x, hMudou);

        if (*hMudou == 1) {
            switch (r->FB) {
                case +1:
                    r->FB = 0;
                    *hMudou = 1;
                    break;
                case 0:
                    r->FB = -1;
                    *hMudou = 0;
                    break;
                case -1: {
                    int aux = r->esq->FB;
                    r = RotacaoDir(r);
                    *hMudou = (aux != 0);
                    break;
                }
            }
        }
    } 
    else {  
        // achou o nó a remover
        if (r->esq == NULL && r->dir == NULL) {
            free(r);
            *hMudou = 1;
            return NULL;
        } 
        else if (r->esq == NULL || r->dir == NULL) {
            avl *aux = (r->esq != NULL) ? r->esq : r->dir;
            free(r);
            *hMudou = 1;
            return aux;
        } 
        else {
            // dois filhos: substituir pelo maior da esquerda
            avl *maiorEsq = r->esq;
            while (maiorEsq->dir != NULL)
                maiorEsq = maiorEsq->dir;

            r->info = maiorEsq->info;
            r->esq = Remover(r->esq, r->info, hMudou);

            if (*hMudou == 1) {
                switch (r->FB) {
                    case -1:
                        r->FB = 0;
                        *hMudou = 1;
                        break;
                    case 0:
                        r->FB = 1;
                        *hMudou = 0;
                        break;
                    case +1: {
                        int aux = r->dir->FB;
                        r = RotacaoEsq(r);
                        *hMudou = (aux != 0);
                        break;
                    }
                }
            }
        }
    }
    ajustarFB(r);
    return r;  
}
void folhasMenores(avl *r, int x){
//IMPRIME FOLHAS MENORES QUE ELEMENTO 'X'    
    if(r == NULL){
        return;
    }
    if(r->esq == NULL && r->dir == NULL){
        if(r->info < x){
            printf(" %d", r->info);
        }
    }
    folhasMenores(r->esq, x);
    folhasMenores(r->dir, x);
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

short int op;
short int escolha;
int hMudou = 0; 
avl *raiz = NULL;

printf("\t\t\tÁRVORE AVL\n\n");

    while (raiz == NULL){
    
        char nomeArq[100];
        FILE *arq;
        printf("\nAntes de começar, você precisa carregar uma árvore.\n");
        printf("Digite o nome do arquivo: ");
        scanf("%s", &nomeArq);

        arq = fopen(nomeArq, "r");
        if(arq == NULL){

        printf("\nErro ao abri o arquivo! Tente novamente.");
        }
        else {
            raiz = lerAVL(arq);
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

    raiz = lerAVL(arq);
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

    raiz = Inserir(raiz, vlr, &hMudou);
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

        raiz = Remover(raiz, vlr, &hMudou);
        ajustarFB(raiz);
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
        printf("\nOpção inválida! Tente novamente.\n");
        printf("\n");
        break;
            }
        }    
    }         
    
    return 0;
    
}