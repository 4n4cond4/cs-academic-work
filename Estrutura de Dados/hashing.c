#include<stdio.h>
#include<stdlib.h>


typedef struct aluno{

int mat;
char nome[100];
char email[50];

}Aluno;


typedef struct registro {

    int info;
    int disponibilidade;

}registro;

void inicializar (char *nomeArq){

registro a;
int i;
a.disponibilidade = 1;


for(i=0; i<N; i++)

    fwrite(&a, sizeof(registro), 1, arq);
    fclose(arq);

}

void inserir (char *nomeArq, int x){

 int pos = acharPosicao(nomeArq, x); 
 FILE *arq = fopen(nomeArq, "r+b");
 registro a;

    a.info = x;
    a.disponibilidade = 0;
    fseek(arq, pos*sizeof(registro), SEEK_SET);
    fwrite(&a, sizeof(registro), 1, arq);
    fclose(arq);
 }

int AcharPosicao(char *nomeArq, int x){

int pos = hash(x);
registro a;

FILE *arq = fopen(nomeArq, "rb");


}


int buscar (int *vet, int x, int *ret){

int pos = hash(x);
while (pos[pos] != x && vet[pos] != -1)
pos = (pos+1)%N;
    
    if(vet[pos] == -1)
        return 0;

    else{
        *ret = pos;
        return 1;
    }    
}