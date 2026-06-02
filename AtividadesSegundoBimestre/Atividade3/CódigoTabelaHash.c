#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct No {
    char palavra[50];
    char definicao[200];
    struct No *prox;
} No;

No *tabela[TAM];

int totalElementos = 0;
int totalColisoes = 0;

int funcaoHash(char *palavra) {
    int soma = 0;

    for (int i = 0; palavra[i] != '\0'; i++) {
        soma += palavra[i];
    }

    return soma % TAM;
}

void inserir(char *palavra, char *definicao) {
    int indice = funcaoHash(palavra);

    No *novo = (No *)malloc(sizeof(No));

    strcpy(novo->palavra, palavra);
    strcpy(novo->definicao, definicao);
    novo->prox = NULL;

    if (tabela[indice] != NULL) {
        totalColisoes++;
    }

    novo->prox = tabela[indice];
    tabela[indice] = novo;

    totalElementos++;

    printf("Palavra inserida com sucesso!\n");
}

void buscar(char *palavra) {
    int indice = funcaoHash(palavra);

    No *atual = tabela[indice];

    while (atual != NULL) {
        if (strcmp(atual->palavra, palavra) == 0) {
            printf("\nPalavra: %s\n", atual->palavra);
            printf("Definicao: %s\n", atual->definicao);
            return;
        }
        atual = atual->prox;
    }

    printf("Palavra nao encontrada!\n");
}

void removerPalavra(char *palavra) {
    int indice = funcaoHash(palavra);

    No *atual = tabela[indice];
    No *anterior = NULL;

    while (atual != NULL) {

        if (strcmp(atual->palavra, palavra) == 0) {

            if (anterior == NULL) {
                tabela[indice] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            free(atual);
            totalElementos--;

            printf("Palavra removida!\n");
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    printf("Palavra nao encontrada!\n");
}

void exibirTabela() {
    printf("\n===== TABELA HASH =====\n");

    for (int i = 0; i < TAM; i++) {

        printf("[%d] -> ", i);

        No *atual = tabela[i];

        while (atual != NULL) {
            printf("(%s) -> ", atual->palavra);
            atual = atual->prox;
        }

        printf("NULL\n");
    }
}

void estatisticas() {
    int maiorLista = 0;

    for (int i = 0; i < TAM; i++) {

        int contador = 0;
        No *atual = tabela[i];

        while (atual != NULL) {
            contador++;
            atual = atual->prox;
        }

        if (contador > maiorLista) {
            maiorLista = contador;
        }
    }

    float fatorCarga = (float) totalElementos / TAM;

    printf("\n===== ESTATISTICAS =====\n");
    printf("Quantidade de elementos: %d\n", totalElementos);
    printf("Quantidade de colisoes: %d\n", totalColisoes);
    printf("Fator de carga: %.2f\n", fatorCarga);
    printf("Maior lista encadeada: %d\n", maiorLista);
}

int main() {

    int opcao;
    char palavra[50];
    char definicao[200];

    for (int i = 0; i < TAM; i++) {
        tabela[i] = NULL;
    }

    do {

        printf("\n===== DICIONARIO HASH =====\n");
        printf("1 - Inserir palavra\n");
        printf("2 - Buscar palavra\n");
        printf("3 - Remover palavra\n");
        printf("4 - Exibir tabela\n");
        printf("5 - Estatisticas\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {

            case 1:
                printf("Palavra: ");
                fgets(palavra, sizeof(palavra), stdin);
                palavra[strcspn(palavra, "\n")] = '\0';

                printf("Definicao: ");
                fgets(definicao, sizeof(definicao), stdin);
                definicao[strcspn(definicao, "\n")] = '\0';

                inserir(palavra, definicao);
                break;

            case 2:
                printf("Digite a palavra: ");
                fgets(palavra, sizeof(palavra), stdin);
                palavra[strcspn(palavra, "\n")] = '\0';

                buscar(palavra);
                break;

            case 3:
                printf("Digite a palavra: ");
                fgets(palavra, sizeof(palavra), stdin);
                palavra[strcspn(palavra, "\n")] = '\0';

                removerPalavra(palavra);
                break;

            case 4:
                exibirTabela();
                break;

            case 5:
                estatisticas();
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
