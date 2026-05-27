#include <stdio.h>
#include <stdlib.h>

typedef struct NoSimples {
    int valor;
    struct NoSimples *prox;
} NoSimples;

/* Criar nó */
NoSimples* criarNo(int valor) {

    NoSimples *novo =
        (NoSimples*) malloc(sizeof(NoSimples));

    if (novo == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }

    novo->valor = valor;
    novo->prox = NULL;

    return novo;
}

/* Inserir no final */
void inserirFinal(NoSimples **head, int valor) {

    NoSimples *novo = criarNo(valor);

    /* Lista vazia */
    if (*head == NULL) {
        *head = novo;
        return;
    }

    NoSimples *temp = *head;

    while (temp->prox != NULL) {
        temp = temp->prox;
    }

    temp->prox = novo;
}

/* Exibir lista */
void exibirLista(NoSimples *head) {

    if (head == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    while (head != NULL) {
        printf("%d -> ", head->valor);
        head = head->prox;
    }

    printf("NULL\n");
}

/* Inserir em posição específica */
void inserirPosicao(NoSimples **head,
                    int valor,
                    int posicao) {

    if (posicao < 0) {
        printf("Posicao invalida!\n");
        return;
    }

    NoSimples *novo = criarNo(valor);

    /* Inserção no início */
    if (posicao == 0) {
        novo->prox = *head;
        *head = novo;
        return;
    }

    NoSimples *temp = *head;
    int i = 0;

    while (temp != NULL &&
           i < posicao - 1) {

        temp = temp->prox;
        i++;
    }

    if (temp == NULL) {
        printf("Posicao invalida!\n");
        free(novo);
        return;
    }

    novo->prox = temp->prox;
    temp->prox = novo;
}

/* Remover do início */
void removerInicio(NoSimples **head) {

    if (*head == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    NoSimples *temp = *head;

    *head = (*head)->prox;

    free(temp);

    printf("Elemento removido!\n");
}

/* Buscar valor */
void buscarValor(NoSimples *head, int valor) {

    int posicao = 0;
    int encontrado = 0;

    while (head != NULL) {

        if (head->valor == valor) {
            printf("Valor encontrado na posicao %d\n",
                   posicao);
            encontrado = 1;
        }

        head = head->prox;
        posicao++;
    }

    if (!encontrado) {
        printf("Valor nao encontrado!\n");
    }
}

/* Liberar memória */
void liberarLista(NoSimples *head) {

    NoSimples *temp;

    while (head != NULL) {
        temp = head;
        head = head->prox;
        free(temp);
    }
}

int main() {

    NoSimples *lista = NULL;

    int opcao;
    int valor;
    int posicao;

    do {

        printf("\n=============================\n");
        printf("   MENU LISTA ENCADEADA\n");
        printf("=============================\n");

        printf("1 - Inserir no final\n");
        printf("2 - Inserir em posicao\n");
        printf("3 - Exibir lista\n");
        printf("4 - Buscar valor\n");
        printf("5 - Remover inicio\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:

                printf("Digite o valor: ");
                scanf("%d", &valor);

                inserirFinal(&lista, valor);

                printf("Valor inserido!\n");

                break;

            case 2:

                printf("Digite o valor: ");
                scanf("%d", &valor);

                printf("Digite a posicao: ");
                scanf("%d", &posicao);

                inserirPosicao(&lista,
                                valor,
                                posicao);

                break;

            case 3:

                printf("\nLista:\n");
                exibirLista(lista);

                break;

            case 4:

                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);

                buscarValor(lista, valor);

                break;

            case 5:

                removerInicio(&lista);

                break;

            case 0:

                printf("Encerrando programa...\n");

                break;

            default:

                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    liberarLista(lista);

    return 0;
}
