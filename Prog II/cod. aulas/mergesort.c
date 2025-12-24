#include<stdio.h>
#include<stdlib.h>
#define max 1000

int v1[max], v2[max];
int qtdv1, qtdv2;

void merge(int v1[], int v2[], int fimv1, int fimv2){

    int i=0, j=0, k=0, tm = fimv1+fimv2;

    int VORD[tm];

    while((i < fimv1) && (j < fimv2)){

        if(v1[i] <= v2[j]){
            VORD[k] = v1[i];
            i++;
            j++;

        }
        else{
            VORD[k] = v2[j];
            j++;
            k++;
        }

    }
    if(i >= fimv1){
        while (k < tm){
        VORD[k] = v2[j];
        k++;
        j++;
        }     
    }
    else {
        while(k < tm){
            VORD[k] = v1[i];
            k++;
            i++;
        }
    }
}
    void imprimir(int vetor[], int tm){
        printf("[ ");

        for(int i=0; i < tm; i++){
            printf(" %d ", vetor[i]);
        }
        printf(" ] ");
    }

int main(){

    printf("\nPrograma combina vetores de forma ordenada (MERGE)\n");

    printf("\nDigite a quantidade de elementos do vetor 1: ");
    scanf("%d", &qtdv1);

    printf("\nPREENCHA O VETOR 1 DE FORMA ORDENADA!!!\n");

    for(int i = 0; i < qtdv1; i++){
        printf("V1[%d] = ", (i+1));
        scanf("%d", &v1[i]);

    }

    printf("\n*********************************************************\n");

    printf("Digite a quantidade de elementos do vetor 2: ");
    scanf("%d", &qtdv2);


    printf("\nPREENCHA O VETOR 2 DE FORMA ORDENADA!!!\n");


    for(int j = 0; j < qtdv2; j++){
        printf("V2[%d] = ", (j+1));
        scanf("%d", &v2[j]);

    }
    
    printf("\n*********************************************************\n");
    printf("\nVetor 1 = ");
    imprimir(v1, qtdv1);

    printf("\n\nVetor 2 = ");
    imprimir(v2, qtdv2);


    merge(v1, v2, qtdv1, qtdv2);

    printf("\n");

    return 0;

}