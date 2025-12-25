#include<stdio.h>
#include<stdlib.h>
#include<float.h>

//função para calcular media de 3

float fMedia (float a, float b, float c){
	 
return ( a + b + c)/3.0;

}

//estrutura do aluno
typedef struct {
	
	char nome [31];
	int matricula;
	float nota [3];
	
} Aluno;

int main(){

float mediaFinal[3], maior, resultado;	
int maiorNota = 0, notaJ = 0;
Aluno aluno[2];
	
	maior = -FLT_MAX; // para reconhecer maior nota
	
for(int i = 0; i < 2; i++){
	
	printf("Digite o nome do %do aluno(a): ", i+1);
	scanf("%30s", aluno[i].nome);

	printf("\nDigite a matricula do %do aluno(a): ", i+1);
	scanf(" %d", &aluno[i].matricula);
		
for(int j = 0; j < 3; j++ ){

	printf("\n%da nota do %do aluno(a): ", j+1, i+1);
	scanf("%f", &aluno[i].nota[j]);
	
	}

 mediaFinal[i] = fMedia (aluno[i].nota[0], aluno[i].nota[1], aluno[i].nota[2]); // chamando função

	printf("\n   (MEDIA FINAL DE %s = %.2f)", aluno[i].nome, mediaFinal[i]);
	
if (mediaFinal[i] < 6.0){
	
	printf("\n\n	Reprovado(a)!");
		
	}
	
else {
	
	printf("\n\n	Aprovado(a)!");
}	
	
	printf("\n\n----------------------------------\n\n ");


if(mediaFinal[i] > maior){ 	//TENTANDO IMPRIMIR MAIOR NOTA
maior = mediaFinal[i];
maiorNota = i;

}
	}
	
	printf("\n MAIOR MEDIA: %s - NOTA: %.2f ", aluno[maiorNota].nome, mediaFinal[maiorNota]);
	
return 0;	
			
}
