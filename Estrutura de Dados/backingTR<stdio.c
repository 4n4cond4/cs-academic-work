#include <stdio.h>
#include <stdlib.h>
#define MAX 20

char letras[] = {'a', 'e', 'i'};
int n1;

void bk_AEI(char comb[], int n, int a, int e, int i) {
    if (n == n1) {
        if (a > e + i) {
            comb[n] = '\0';
            printf("%s\n", comb);
        }
        return;
    }

    for (int j = 0; j < 3; j++) {
        comb[n] = letras[j];
        if (letras[j] == 'a')
            bk_AEI(comb, n + 1, a + 1, e, i);
        else if (letras[j] == 'e')
            bk_AEI(comb, n + 1, a, e + 1, i);
        else
            bk_AEI(comb, n + 1, a, e, i + 1);
    }
}

void comb1() {
    printf("Digite o tamanho n: ");
    scanf("%d", &n1);
    char comb[MAX];
    printf("\nCombinações válidas:\n");
    bk_AEI(comb, 0, 0, 0, 0);
}

int valores[] = {15, 31, 55, 44};
int n2;

void bk_VLR(int comb[], int n, int soma) {
    if (n == n2) {
        if (soma % 2 == 0) {
            for (int i = 0; i < n2; i++)
                printf("%d ", comb[i]);
            printf("(soma = %d)\n", soma);
        }
        return;
    }

    for (int j = 0; j < 4; j++) {
        comb[n] = valores[j];
        bk_VLR(comb, n + 1, soma + valores[j]);
    }
}

void comb2() {
    printf("Digite o tamanho n: ");
    scanf("%d", &n2);
    int comb[MAX];
    printf("\nCombinações com soma par:\n");
    bk_VLR(comb, 0, 0);
}

void bk_comb3(int n, int vlr[]) {
    if (n == 3) {
        int A = vlr[0], B = vlr[1], C = vlr[2];
        if ((A || B) && C) {
            printf("A=%c, B=%c, C=%c\n",
                   A ? 'V' : 'F',
                   B ? 'V' : 'F',
                   C ? 'V' : 'F');
        }
        return;
    }

    vlr[n] = 0; 
    bk_comb3(n + 1, vlr);
    vlr[n] = 1;
    bk_comb3(n + 1, vlr);
}

void comb3() {
    int vlr[3];
    printf("\nCombinações que tornam (A ou B) e C verdadeiro:\n");
    bk_comb3(0, vlr);
}

int moedas[] = {50, 25, 10, 5, 1};
int vlr4;

void bk_Moedas(int i, int resto, int usados[]) {
    if (resto == 0) {
        printf("| ");    

        int primeiro = 1; 
        for (int k = 0; k < 5; k++) {
            if (usados[k] > 0) {
                if (!primeiro) printf("+ ");
                printf("%d x R$0,%02d ", moedas[k], usados[k]);
                primeiro = 0;
            }
        }

        printf("|\n"); 
        return;
    }

    if (i == 5 || resto < 0)
        return;

    for (int qtd = 0; qtd * moedas[i] <= resto; qtd++) {
        usados[i] = qtd;
        bk_Moedas(i + 1, resto - qtd * moedas[i], usados);
    }
    usados[i] = 0;
}

void comb4() {
    printf("Digite o valor em centavos: ");
    scanf("%d", &vlr4);
    int usados[5] = {0};
    printf("\nFormas de representar %d centavos:\n", vlr4);
    bk_Moedas(0, vlr4, usados);
}

void Menu(){

        printf("\n\n**********************************************************************************************************\n");
        printf("| %-40s \t| %-40s \t|\n", "1. Combinações {a,e,i} com mais 'a'", "2. Combinações {15,31,55,44} com soma par");
        printf("| %-40s \t| %-40s \t|\n", "3. Combinações de V/F (A,B,C)", "4. Representar valor com moedas");
        printf("| %-40s \t", "5 - Sair\n");
        printf("\n**********************************************************************************************************\n");

}

int main() {
    int op;
    do {
        
        Menu();
        printf("Opção desejada: ");
        if(scanf("%d", &op) != 1){
        printf("Opção inválida! Digite um número.\n");
        while(getchar() != '\n');
        op = 0;
        continue;
        }

        switch (op) {
            case 1: comb1(); 
            break;

            case 2: comb2(); 
            break;

            case 3: comb3(); 
            break;

            case 4: comb4(); 
            break;

            case 5: printf("..Encerrando o programa. Até mais!\n"); 
            break;
            default: printf("Opção inválida!\n");   
        }
    } while (op != 5);

    return 0;
}
