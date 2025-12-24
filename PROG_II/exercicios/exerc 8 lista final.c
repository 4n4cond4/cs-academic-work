#include <stdio.h>
#include <stdlib.h>
#define t_Max 1000

float vMaior (float v[], float vTamanho){

    float max = v[0];
    int i;

    for(i = 0; i < vTamanho; i++){

        if(v[i] > max)
        max = v[i];

    }
 return max;
}
void Menu(){

printf("\t PERCORRENDO VETORES\n");

}

int main(){

float resul;    
int tamanho;
float vet[t_Max];

Menu();
    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &tamanho);

  
for(int i=0; i < tamanho; i++){

printf("\nDigite o %dº valor: ", i+1);
scanf("%f", &vet[i]);

while (tamanho < 1 || tamanho > t_Max ){

    printf("\nEntrada inválida");
}
    }
resul = vMaior (vet, tamanho);
printf("\nO maior valor é: %.2f", resul);
printf("\n");

return 0;
}