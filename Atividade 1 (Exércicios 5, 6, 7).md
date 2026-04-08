5- Código

#include <stdio.h>
int main() {
    int vetor[3], matriz[3][3];
    int resultado[3] = {0, 0, 0};

    // Leitura do vetor
    printf("Digite os 3 elementos do vetor:\n");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &vetor[i]);
    }

    // Leitura da matriz
    printf("Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Multiplicação do vetor pelas colunas da matriz
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            resultado[j] += vetor[i] * matriz[i][j];
        }
    }

    // Exibição do resultado
    printf("Resultado da multiplicacao:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", resultado[i]);
    }

    printf("\n");
    
    return 0;
}

6-
#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[50];
    int matricula;
    float media;
};

int main() {
    struct Aluno alunos[10];
    struct Aluno aprovados[10];
    struct Aluno reprovados[10];

    int contAprovados = 0, contReprovados = 0;

    // Leitura dos dados
    for (int i = 0; i < 10; i++) {
        printf("\nAluno %d\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);

        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Media final: ");
        scanf("%f", &alunos[i].media);

        // Separação em aprovados e reprovados
        if (alunos[i].media >= 5.0) {
            aprovados[contAprovados] = alunos[i];
            contAprovados++;
        } else {
            reprovados[contReprovados] = alunos[i];
            contReprovados++;
        }
    }

    // Exibição dos aprovados
    printf("\n--- ALUNOS APROVADOS ---\n");
    for (int i = 0; i < contAprovados; i++) {
        printf("\nNome: %s", aprovados[i].nome);
        printf("\nMatricula: %d", aprovados[i].matricula);
        printf("\nMedia: %.2f\n", aprovados[i].media);
    }

    // Exibição dos reprovados
    printf("\n--- ALUNOS REPROVADOS ---\n");
    for (int i = 0; i < contReprovados; i++) {
        printf("\nNome: %s", reprovados[i].nome);
        printf("\nMatricula: %d", reprovados[i].matricula);
        printf("\nMedia: %.2f\n", reprovados[i].media);
    }

    return 0;
}

7-Código
#include <stdio.h>
#include <string.h>

struct Livro {
    char titulo[31];
    char autor[16];
    int ano;
};

int main() {
    struct Livro livros[5];
    char busca[31];
    int encontrado = 0;

    // Leitura dos dados
    for (int i = 0; i < 5; i++) {
        printf("\nLivro %d\n", i + 1);

        printf("Titulo: ");
        scanf(" %[^\n]", livros[i].titulo);

        printf("Autor: ");
        scanf(" %[^\n]", livros[i].autor);

        printf("Ano: ");
        scanf("%d", &livros[i].ano);
    }

    // Busca
    printf("\nDigite o titulo que deseja buscar: ");
    scanf(" %[^\n]", busca);

    // Verificação
    for (int i = 0; i < 5; i++) {
        if (strcmp(livros[i].titulo, busca) == 0) {
            printf("\n--- Livro encontrado ---\n");
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Ano: %d\n", livros[i].ano);
            encontrado = 1;
        }
    }

    // Caso não encontre
    if (!encontrado) {
        printf("\nNenhum livro encontrado com esse titulo.\n");
    }

    return 0;
}
