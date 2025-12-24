#include<stdio.h>
#include<stdlib.h>

int *v, tm;

int main(){

printf("Digite o tamanho do vetor: ");
scanf("%d", &tm);

v = (int*) malloc (tm* sizeof(int));

printf("\nPreenchendo o Vetor: ");

for(int i = 0; i < tm; i++){
printf("\nV[%d] = ", i+1);
scanf("%d", &v[i]);
}
printf("\nImprime o vetor: \n");
for(int j=0; j<tm; j++){
    printf("\n[%d] = %d", j+1, v[j]);
}
printf("\n");
return 0;
}