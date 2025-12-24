#include <stdio.h>
#include <stdlib.h>

int main (){
float nota1, nota2, media;

printf("\nDigite a primeira nota P1: ");
scanf("%f", &nota1);

printf("\nDigite a segunda nota P2: ");
scanf("%f", &nota2);

media = (nota1+nota2)/2;


printf("\nMedia Final: %.2f\n", media);

if(media >=6){

printf("\nAprovado!");
}

else{

printf("\nReprovado!");
}

if(media >= 6.0 || == 8.0){

printf("Conceito C");	
}

else(media >= 8.1 || == 9.0){

printf("Conceito B");	
}
if(media >= 9.1 || == 10.0){
	
printf("Conceito A");
}

return 0;
}
