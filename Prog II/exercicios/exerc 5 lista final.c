#include <stdio.h>
#include<stdlib.h>

int mult(int a, int b) {
    
    if (b == 0)
        return 0;

    if (b > 0)
        return a + mult(a, b - 1);

    return -mult(a, -b);
}

int main() {
    int a, b;

    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &a, &b);

    int resultado = mult(a, b);

    printf("\nResultado: %d\n", resultado);
    printf("\n");

    return 0;
}
