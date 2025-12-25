#include<stdio.h>
#include<stdlib.h>

//FUN��O PARA CALCULAR O VALOR DE DELTA


int Delta(int a, int b, int c){
	
	return (b*b)-4*a*c;
	
}

int main(){
	
int num[3], resultado;
	
printf("\t ACHE O VALOR DE DELTA / (b*b)-4*a*c ");
printf("\n\nDigite os valores de 'a' 'b' e 'c' consecutivamente: \n");
	

for(int i = 0; i<3; i++){


printf("\n %do valor: ", i+1);
scanf("%d", &num[i]);

resultado = Delta (num[0], num[1], num[2]);
	
}


printf("\n Delta: %d", resultado);
printf("\n");

return 0;

}


	

