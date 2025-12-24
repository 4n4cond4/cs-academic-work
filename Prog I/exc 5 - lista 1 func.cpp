#include<stdio.h>
#include<stdlib.h>

float fMedia (int v1, int v2, int v3){
	
float media;

media = ( v1 + v2 + v3) / 3;	 
	
return media;
	
}

int main(){

int i;
float num[3], resultado;
	
for(i = 0; i < 3; i++){

	printf(" Digite a %da nota: ", i+1);
	scanf("%f", &num[i]);
	
	resultado = fMedia (num[0], num[1], num[2]);
	}

printf("\n\n Media final: %.2f", resultado);

return 0;

}
