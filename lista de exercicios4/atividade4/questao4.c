#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

void exibirAluno(struct Aluno a) {
    printf("Nome: %s | Idade: %d | Nota: %.2f\n", a.nome, a.idade, a.nota);
}

struct Aluno criarAluno() {
    struct Aluno novo;
    printf("Nome: ");
    scanf(" %49[^\n]", novo.nome);
    printf("Idade: ");
    scanf("%d", &novo.idade);
    printf("Nota: ");
    scanf("%f", &novo.nota);
    return novo;
}

int main() {
    struct Aluno alunos[4];
    int qtd = 0;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Criar novo aluno\n");
        printf("2 - Exibir alunos\n");
        printf("3 - Remover aluno\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (qtd == 4) {
                printf("Limite de alunos atingido!\n");
            } else {
                alunos[qtd] = criarAluno();
                qtd++;
            }
        }

        else if (opcao == 2) {
            if (qtd == 0) {
                printf("Nenhum aluno cadastrado!\n");
            } else {
                for (int i = 0; i < qtd; i++) {
                    printf("%d - ", i);
                    exibirAluno(alunos[i]);
                }
            }
        }

        else if (opcao == 3) {
            if (qtd == 0) {
                printf("Nenhum aluno para remover!\n");
            } else {
                int idx;
                printf("Informe o índice do aluno para remover: ");
                scanf("%d", &idx);

                if (idx < 0 || idx >= qtd) {
                    printf("Índice inválido!\n");
                } else {
                    for (int i = idx; i < qtd - 1; i++) {
                        alunos[i] = alunos[i + 1];
                    }
                    qtd--;
                    printf("Aluno removido!\n");
                }
            }
        }

    } while (opcao != 0);

    return 0;
}
