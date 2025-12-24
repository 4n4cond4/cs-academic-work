#include <stdio.h>
#include <stdlib.h>



int main() {
    int *vetA, *vetB;
    int n, i, prodEscalar = 0;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);

    vetA= (int *)malloc(n * sizeof(int));
    vetB = (int *)malloc(n * sizeof(int));

    if (vetA== 0 || vetB == 0) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    printf("Digite os %d elementos do vetor A:\n", n);
    for (i = 0; i < n; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &vetA[i]);
    }

    printf("Digite os %d elementos do vetor B:\n", n);
    for (i = 0; i < n; i++) {
        printf("B[%d]: ", i);
        scanf("%d", &vetB[i]);
    }

    
    for (i = 0; i < n; i++) {
        prodEscalar += vetA[i] * vetB[i];
    }


    printf("\nProduto Escalar = %d\n", prodEscalar);

   
    free(vetA);
    free(vetB);

    return 0;
}

