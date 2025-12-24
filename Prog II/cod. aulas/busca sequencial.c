#include<stdio.h>
#include<stdlib.h>


float *vetor , busca;
int tm, op, encontrado;

float buscaSequencial (float *v1, float chave){

    int posEncon = -1;
    for(int i=0; i < tm; i++){
        if(v1[i] == chave){
            posEncon = i;
            return (posEncon);
        }
    }
    return posEncon;
}

float* alocaVetor(float *v1, int tm){
    v1 = (float*)malloc(tm * sizeof(float));
    return v1;

}

int main(){
    int ver1 = 0;
    while(ver1 != 2){
        
        printf("Digite o tamanho do vetor a ser alocado: ");
        scanf("%d", &tm);
        vetor = alocaVetor(vetor, tm);

        printf("\nPreenchendo o vetor\n");

        for(int i=0; i<tm; i++){
            printf("\nVetor [%d] = ", (i+1));
            scanf("%f", &vetor[i]);
        }

    

    int ver2 = 0;
    while(ver2 != 2){
        printf("\nDigite o valor a ser buscado: ");
        scanf("%f", &busca);
        encontrado = buscaSequencial(vetor, busca);

        if(encontrado == -1){
            printf("\nO valor não esta na lista!\n");
        }
        else{
            printf("\nO valor (%.2f) foi encontrado na posição: ===> %d\n", busca, (encontrado+1));
        }
    

    printf("\n1 - Buscar novo valor\n2 - Sair\nDigite: ");
    scanf("%d", &ver2);
        }
    printf("\n1 - Buscar novo vetor\n2 - Finalizar\nDigite: ");
    scanf("%d", &ver1);
    }
    printf("\n");
    return 0;

}