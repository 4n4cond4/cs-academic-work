#include<stdio.h>
#include<stdlib.h>

int compara (int a, int b, int c){

int menor = INT_MAX;
	
if (a < b)
menor = a;

else
menor = b;

if (c < b && c < a)
menor = c;


 return menor;
}

int main (){	
	
int num[3], recebe;	

for(int i=0; i<3; i++){

	printf("Digite o %do numero inteiro: ", i+1);
	scanf("%d", &num[i]);	
	
recebe = compara (num[0], num[1], num[2]);

}

printf("\n\nMenor numero: %d", recebe);


return 0;

}
