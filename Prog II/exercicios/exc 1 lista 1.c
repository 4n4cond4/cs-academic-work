#include<stdio.h>
#include<stdlib.h>

typedef struct {
   float x;
   float y; 
}Calc;


float Soma (Calc n){

    return n.x + n.y;
}

float Sub (Calc n){

    return n.x-n.y;
}

float Mult (Calc n){

    return (n.x) * (n.y);
}

float Div (Calc n){

    if(n.y != 0){
       return n.x/n.y;
    }
else 
printf("\nDivisão inválida! Tente novamente");

return 0;
   
}

void Menu (){

printf("\tCALCULADORA\n\n");
printf("Digite 1 - Soma/ 2 - Subtração/ 3 - Multiplicação/ 4 - Divisão/ 5 - Sair\n\n");

}

int main (){
char escolha;
Calc calc;


Menu();

while (escolha != '5'){

    printf("\nEscolha uma opçao: ");
    scanf(" %c", &escolha);

if (escolha == '1'){

    printf("\nDigite 2 números inteiros: ");
    scanf("%f %f", &calc.x, &calc.y);
    
    float resultado = Soma(calc);
    printf("\nResultado: %.2f\n", resultado);

} else if (escolha == '2'){

    printf("\nDigite 2 números inteiros: ");
    scanf("%f %f", &calc.x, &calc.y);
    
    float resultado =  Sub(calc);
    printf("\nResultado: %.2f\n", resultado);

} else if (escolha == '3'){


    printf("\nDigite 2 números inteiros: ");
    scanf("%f %f", &calc.x, &calc.y);
    
    float resultado = Mult(calc);
    printf("\nResultado: %.2f\n", resultado);

} else if (escolha == '4'){

printf("\nDigite 2 números inteiros: ");
    scanf("%f %f", &calc.x, &calc.y);
    
    float resultado = Div(calc);
    printf("\nResultado: %.2f\n", resultado);

} else if (escolha == '5'){

   printf("\n...Encerrando o programa, até mais!\n");

}else {

     printf("\nEntrada inválida! Tente novamente. \n");
     printf("\n-------------------------------\n");

    }

}

return 0;
}
