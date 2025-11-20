#include <stdio.h>

struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

int main() {
    struct Aluno alunos[5];

    for (int i = 0; i < 5; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %49[^\n]", alunos[i].nome);
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
    }

    int indice;
    printf("\nEscolha o indice do aluno que deseja atualizar (0 a 4): ");
    scanf("%d", &indice);

    if (indice < 0 || indice > 4) {
        printf("Índice inválido!\n");
        return 0;
    }

    printf("Nova nota para %s: ", alunos[indice].nome);
    scanf("%f", &alunos[indice].nota);

    printf("\n--- DADOS ATUALIZADOS ---\n");
    printf("Nome: %s\n", alunos[indice].nome);
    printf("Idade: %d\n", alunos[indice].idade);
    printf("Nota: %.2f\n", alunos[indice].nota);

    return 0;
}
