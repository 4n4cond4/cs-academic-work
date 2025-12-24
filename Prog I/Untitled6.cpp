#include <stdio.h>
#include <stdlib.h>

int main (){
float nota1, nota2, media, conceito_c, conceito_b, conceito_a;

printf("\nDigite a primeira nota P1: ");
scanf("%f", &nota1);

printf("\nDigite a segunda nota P2: ");
scanf("%f", &nota2);

media = (nota1+nota2)/2;

conceito_c = media >= 6.0 || 8.0;

printf("\nMedia Final: %.2f\n", media);

if(media >=6){

printf("\nAprovado!");
}

else{

printf("\nReprovado!");
}

if(media >= 6.0 || 8.0){

printf("\nConceito: %.2f", conceito_c);	
}

return 0;
}
