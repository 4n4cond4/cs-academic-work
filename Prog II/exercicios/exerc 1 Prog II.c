#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//1) Utilize funções e o comando while para criar um programa que escolha entre as operações de soma, subtração, multiplicação, divisão,
//módulo e potência. O programa deve: Solicitar ao usuário que insira dois números, apresentar um menu para escolha da operação
//desejada, executar a operação correspondente com base na escolha do usuário, garantir que a divisão só seja realizada se o divisor for
//diferente de zero e exibir o resultado da operação escolhida.

// DEU CERTO!!!

// 22/04 - FALTOU MÓDULO E POTENCIA :(

float Soma (float a, float b){
    

    return a+b;
}

float Sub (float a, float b){
    
    return a-b;
}

float Mult (float a, float b){
    
    return a*b;
}

float Divi (float a, float b){

    float divide;
    
    divide = a/b;

        while (b == 0){
        printf("\nDigite um divisor diferente de 0: ");
        scanf("%f", &b); // Prompt user to input a valid divisor
        divide = a/b;
    }
    return divide;
}

float Mod (float a, float b){

 return (int)a % (int)b;

}

void Menu (){

        printf("\n\t OPERAÇÕES MATEMÁTICAS\n");
        printf("\n '1' - Adição\\ '2' - Subtração\\ '3' - Multiplicação\\ '4' - Divisão\\ '5' - Módulo \\ '6' - Sair\n");
    
    }
    
    int main (){

    float num1, num2;
    char escolha;
    
     Menu();

while (escolha != 5)
{

do{
    printf("\nDigite uma opção: ");
    scanf(" %c", &escolha);
    
} while(escolha < 1 && escolha <= 4);

if(escolha == '1'){

    printf("\nDigite dois números:  ");
    scanf("%f %f", &num1, &num2);

    printf("\nResultado: %.2f\n", Soma(num1, num2));
    printf("\n-----------------------------------------\n");
}

else if (escolha == '2'){
    printf("\nDigite dois números: ");
    scanf("%f %f", &num1, &num2);

    printf("\nResultado: %.2f\n", Sub(num1, num2));
    printf("\n-----------------------------------------\n");
}
else if (escolha == '3'){
    printf("\nDigite dois números: ");
    scanf("%f %f", &num1, &num2);

    printf("\nResultado: %.2f\n", Mult(num1, num2));
    printf("\n-----------------------------------------\n");
}
else if (escolha == '4'){
    printf("\nDigite dois números: ");
    scanf("%f %f", &num1, &num2);

    printf("\nResultado: %.2f\n", Divi(num1, num2));
    printf("\n-----------------------------------------\n");
}
else if (escolha == '5'){
    printf("\nDigite dois números: ");
    scanf("%f %f", &num1, &num2);

    printf("\nResultado: %.2f\n", Mod (num1, num2));
    printf("\n-----------------------------------------\n");
}
else if (escolha == '6'){ 
    printf ("\n Encerrando o programa. Até mais! \n\n");
    break;
}

else {
    printf("\nEntrada inválida! Tente novamente.\n");

}
    }
    
return 0;
     }












