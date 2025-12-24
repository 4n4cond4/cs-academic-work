#include<stdio.h>
#include<stdlib.h>
#define max 100


//A estrutura de dados que representa uma pilha é uma metáfora emprestada do mundo real que a
//computação utiliza para resolver muitos problemas de forma simplificada. Nessa estrutura a inserção e
//retirada de elementos ocorre em uma de suas extremidades (Topo). Utilize Struct com alocação de
//memória de forma estática para implementar uma pilha.

int dado, ver = 0, op = 0;

typedef struct {

    int elem[max];
    int topo;

}Pilha;

void iniciaPilha (Pilha *p){
    p -> topo = - 1;

}

void inserirPilha (Pilha *p, int vlr){

   if(p -> topo > max -1){
        printf("\nA pilha está cheia!\n");
    } 
    else{
        p -> topo++;
        p -> elem[p->topo] = vlr;
    } 

}

void removerPilha (Pilha *p){
    if(p -> topo == -1){
        printf("\nA pilha está vazia!\n");
    }
    else {
        p -> topo--;
    }
}

void mostrarTopo (Pilha *p){
    if(p -> topo == -1){
        printf("\nA pilha está vazia!\n");
        
    }
    else {
        printf("\nTopo = [ %d ]\n", p -> elem[p->topo]);

    }
}

void mostrarPilha (Pilha *p){

    if(p -> topo == -1){
        printf("\nA pilha está vazia!\n");
    }
    else{

    for(int i = p -> topo; i >= 0; i--) {

    if(i == p -> topo){

        printf("\nPILHA ÍNDICE [ %d ] = '%d' TOPO \n", i+1, p -> elem[i]);
        }       
    else if (i == 0){

        printf("\nPILHA ÍNDICE [ %d ] = '%d' BASE \n", i+1, p -> elem[i]);
    }
    else{

        printf("\nPILHA ÍNDICE [ %d ] = '%d' \n", i+1, p -> elem[i]);
            }
        }
    } 
}      

int main(){

Pilha p;
iniciaPilha(&p);

printf("\tPROGRAMA DE PILHA ESTÁTICA \n");

while(ver != 2){

    printf("\n**************************************************\n");
    printf("\n1 - Inserir elemento/ 2 - Remover elemento / 3 - Mostrar topo / 4 - Mostrar pilha \n");
    printf("\nDigite: ");
    scanf("%d", &op);

if(op == 1){

    printf("\nDigite o valor inteiro a ser inserido: ");
    scanf("%d", &dado);

    inserirPilha(&p, dado);

}

else if(op == 2){

    printf("\nRemovendo elemento!\n");
    removerPilha(&p);
}
else if(op == 3){

    mostrarTopo(&p);
}

else if(op == 4){

    mostrarPilha(&p);
}

else {

    printf("\nOpção inválida!\n");

}

    printf("\n1 - Continuar inserindo/ 2 - Encerrar");
    printf("\nDigite: ");
    scanf("%d", &ver);

}


if(ver != 2){

    printf("\n...Encerrando o programa. Até mais!\n");

}
    return 0;
}