#include<stdlib.h>
#include<stdio.h>

struct cadastro{   

char nome [10];
char tel [10];
char matricula [10];   
int idade;  

};


void Menu (){
    printf("\tCADASTRO DE ALUNOS\n");
    
}

int main(){
int qtd = 0;

Menu();
    
printf("\nDigite a quantidade de alunos: ");
scanf("%d", &qtd); 

struct cadastro aluno[qtd];

for(int i = 0; i < qtd; i++){
    printf("\nDigite o nome do %do aluno(a): ", i+1);
    scanf("%s", aluno[i].nome);

    printf("\nDigite o telefone do %do aluno(a): ", i+1);
    scanf("%s", aluno[i].tel);

    printf("\nDigite a matrícula do %do aluno(a): ", i+1);
    scanf("%s", aluno[i].matricula);

    printf("\nDigite a idade do %do aluno(a): ", i+1);
    scanf("%d", &aluno[i].idade);
    
    printf("\n------------------------------------\n");
}
for(int i = 0; i < qtd; i++) {
    printf(" %dº Aluno: \n", i+1);
    printf("\nNome: %s\nTel: %s\nMatrícula: %s\nIdade: %d anos", aluno[i].nome, aluno[i].tel, aluno[i].matricula, aluno[i].idade);

    printf("\n------------------------------------\n");
}
return 0;

}