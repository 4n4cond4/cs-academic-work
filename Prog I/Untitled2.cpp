#include <stdio.h>

int main() {
    float numero;
    int parte_inteira;
    float parte_decimal;

    // Lendo o número com casas decimais
    printf("Digite um número com casas decimais: ");
    scanf("%f", &numero);

    // Extraindo a parte inteira e a parte decimal
    parte_inteira = (int)numero;
    parte_decimal = numero - parte_inteira;

    // Garantindo que a parte decimal seja positiva
    parte_decimal = parte_decimal < 0 ? -parte_decimal : parte_decimal;

    // Imprimindo as partes separadamente
    printf("Parte inteira: %d\n", parte_inteira);
    printf("Parte decimal: %.2f\n", parte_decimal);

    return 0;
}

