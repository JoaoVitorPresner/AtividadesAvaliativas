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

/* Inverter lista */
void inverterLista(NoSimples **head) {

    NoSimples *anterior = NULL;
    NoSimples *atual = *head;
    NoSimples *proximo = NULL;

    while (atual != NULL) {

        proximo = atual->prox;

        atual->prox = anterior;

        anterior = atual;
        atual = proximo;
    }

    *head = anterior;
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

    do {

        printf("\n=========== MENU ===========\n");
        printf("1 - Inserir valor\n");
        printf("2 - Exibir lista\n");
        printf("3 - Inverter lista\n");
        printf("0 - Sair\n");
        printf("============================\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:

                printf("Digite um valor: ");
                scanf("%d", &valor);

                inserirFinal(&lista, valor);

                printf("Valor inserido com sucesso!\n");

                break;

            case 2:

                printf("\nLista atual:\n");
                exibirLista(lista);

                break;

            case 3:

                inverterLista(&lista);

                printf("Lista invertida com sucesso!\n");

                break;

            case 0:

                printf("Encerrando programa...\n");

                break;

            default:

                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    /* Liberar memória */
    liberarLista(lista);

    return 0;
}
