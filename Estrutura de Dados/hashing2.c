#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 11        
#define vazio -1      
#define arq "hash.dat"

typedef struct aluno{
    int matricula;
    char nome[50];
    char curso[30];
} Aluno;


int hash(int chave) {
    return chave % size;
}

void inicializararq() {
    FILE *f = fopen(arq, "wb");
    if (f == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return;
    }

    Aluno a;
    a.matricula = vazio;
    strcpy(a.nome, "");
    strcpy(a.curso, "");

    for (int i = 0; i < size; i++)
        fwrite(&a, sizeof(Aluno), 1, f);

    fclose(f);
    printf("arq inicializado com %d posições vazias.\n", size);
}

void inserirAluno() {
    FILE *f = fopen(arq, "rb+");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Aluno novo;
    printf("\nMatrícula: ");
    scanf("%d", &novo.matricula);
    getchar();
    printf("Nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0;
    printf("Curso: ");
    fgets(novo.curso, sizeof(novo.curso), stdin);
    novo.curso[strcspn(novo.curso, "\n")] = 0;

    int pos = hash(novo.matricula);
    Aluno temp;

    for (int i = 0; i < size; i++) {
        fseek(f, pos * sizeof(Aluno), SEEK_SET);
        fread(&temp, sizeof(Aluno), 1, f);

        if (temp.matricula == vazio) {
            fseek(f, pos * sizeof(Aluno), SEEK_SET);
            fwrite(&novo, sizeof(Aluno), 1, f);
            printf("\nAluno inserido na posição %d.\n", pos);
            fclose(f);
            return;
        }

        pos = (pos + 1) % size; 
    }

    printf("\nTabela cheia! Não foi possível inserir.\n");
    fclose(f);
}

void buscarAluno() {
    FILE *f = fopen(arq, "rb");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int matricula;
    printf("\nDigite a matrícula: ");
    scanf("%d", &matricula);

    int pos = hash(matricula);
    Aluno a;

    for (int i = 0; i < size; i++) {
        fseek(f, pos * sizeof(Aluno), SEEK_SET);
        fread(&a, sizeof(Aluno), 1, f);

        if (a.matricula == vazio) {
            printf("\nAluno não encontrado.\n");
            fclose(f);
            return;
        }

        if (a.matricula == matricula) {
            printf("\nAluno encontrado na posição %d:\n", pos);
            printf("Matrícula: %d\nNome: %s\nCurso: %s\n", a.matricula, a.nome, a.curso);
            fclose(f);
            return;
        }

        pos = (pos + 1) % size;
    }

    printf("\nAluno não encontrado.\n");
    fclose(f);
}

void imprimirTabela() {
    FILE *f = fopen(arq, "rb");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Aluno a;
    printf("\n--- Tabela Hash em arquivo ---\n");
    for (int i = 0; i < size; i++) {
        fseek(f, i * sizeof(Aluno), SEEK_SET);
        fread(&a, sizeof(Aluno), 1, f);

        if (a.matricula == vazio)
            printf("[%d] --- vazio ---\n", i);
        else
            printf("[%d] %d | %s | %s\n", i, a.matricula, a.nome, a.curso);
    }

    fclose(f);
}

int main() {
    int opcao;

    do {
        printf("********************************************************************************************");
        printf("\n\t\t\tHASHING EM ARQUIVO: \n\n");
        printf("%-30s \t| %-30s \t| %-30s \t\n", "1 - Inicializar arquivo",  "2 - Inserir novo aluno", "5 - Sair"); 
        printf("%-30s \t| %-30s \t|\n", "3 - Buscar aluno", "4 - Imprimir tabela hash");
        

        printf("\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                inicializararq();
                break;
            case 2:
                inserirAluno();
                break;
            case 3:
                buscarAluno();
                break;
            case 4:
                imprimirTabela();
                break;
            case 5:
                printf("\nEncerrando programa...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}
