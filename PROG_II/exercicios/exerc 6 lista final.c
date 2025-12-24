#include <stdio.h>
#include <stdlib.h>


struct Func {
    char nome[100];
    int idade;
    char sexo;
    char cpf[15];
    int dia;
    int mes;
    int ano;
    char cargo[50];
    float salario;
};

int main() {
    struct Func func;

    printf("\tCadastro de funcionários: \n");

    printf("Nome: ");
    scanf("%s", func.nome);

    printf("Idade: ");
    scanf("%d", &func.idade);

    printf("Sexo (M/F): ");
    scanf(" %c", &func.sexo); 

    printf("CPF: ");
    scanf("%s", func.cpf);

    printf("Data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &func.dia, &func.mes, &func.ano);

    printf("Cargo (sem espaço): ");
    scanf("%s", func.cargo);

    printf("Salario: ");
    scanf("%f", &func.salario);

    printf("\n--------------------------------\n");

    printf("\n\t Dados do funcionário:\n\n");
    printf("Nome: %s", func.nome);
    printf("\nIdade: %d anos", func.idade);
    printf("\nSexo: %c", func.sexo);
    printf("\nCPF: %s", func.cpf);
    printf("\nData de Nascimento: %02d/%02d/%04d", func.dia, func.mes, func.ano);
    printf("\nCargo: %s", func.cargo);
    printf("\nSalario: R$ %.2f\n", func.salario);
    printf("\n");
    return 0;
}
