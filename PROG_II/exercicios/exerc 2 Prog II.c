#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//2) Utilize funções para criar um programa que escolha entre o cálculo da área do quadrado, triângulo e retângulo.

//Considere:

//Quadrado = Lado x Lado
//Triângulo = (Base x Altura)/2
//Retângulo = Base x Altura

// 22/04 - TEM QUE CONTINUAR

float Qua (float a){

return a*a;
}

float Tri (float a, float b){

    return (a*b)/2;
}

float Ret (float a, float b){

    return a*b;
}
void Menu (){

    printf("\n\t OPERAÇÕES GEOMÉTRICAS\n");
    printf("\n '1' - Quadrado \\ '2' - Triângulo \\ '3' - Retângulo\\ '4' - Sair \n");

}
int main (){

    char choice;
    float n1, n2; 

    Menu();
    
while (choice != 4){

    printf("\n Digite uma opção: ");
    scanf(" %c", &choice);


switch (choice)
{
case '1':
{
    printf("\n Informe a medida do quadrado: ");
    scanf("%f", &n1);

    printf("\n Lado x Lado: %.2f\n", Qua(n1));
    printf("\n-------------------------------\n");
    break;
}
case '2':
{
    printf("\n\tCalculando o triângulo:\n");
    printf("\n Informe a medida da base e da altura consecutivamente: ");
    scanf("%f %f", &n1, &n2);

    printf("\n (Base x Altura) / 2: %.2f\n", Tri(n1, n2));
    printf("\n-------------------------------\n");
    break;
}
case '4':
{
    printf("\n...Encerrando o programa. Até mais!\n\n");
    return 0;    
}

default:

   printf("\n Entrada inválida! Digite novamente.\n");
    
    }
   
}
    return 0;

}