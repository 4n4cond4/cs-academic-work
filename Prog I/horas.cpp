#include<stdio.h>
#include<stdlib.h>

//Faça um programa para ler do teclado uma quantidade de segundos e imprimir na tela a
//conversão para horas, minutos e segundos.
//Exemplo:
//Entrada: 3672
//Saída: 1:1:12

int main(){
	
int hora, min, seg, entrada;

printf("\nDigite alguns segundos: ");
scanf("%d", &entrada);

seg = entrada / 12;
min = seg * 60;
hora = min * 3.5;
	
printf("\n\n Hora: %d:%d:%d", hora, min, seg);	

return 0;
}
