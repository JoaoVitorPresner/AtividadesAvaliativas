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

/* Buscar valor */
int buscarValor(NoSimples *head, int valor) {

    int posicao = 0;

    while (head != NULL) {

        if (head->valor == valor) {
            return posicao;
        }

        head = head->prox;
        posicao++;
    }

    return -1;
}

/* Remover primeiro valor encontrado */
void removerValor(NoSimples **head, int valor) {

    if (*head == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    NoSimples *temp = *head;
    NoSimples *anterior = NULL;

    /* Caso o primeiro nó seja o valor */
    if (temp->valor == valor) {
        *head = temp->prox;
        free(temp);

        printf("Valor %d removido!\n", valor);
        return;
    }

    while (temp != NULL && temp->valor != valor) {
        anterior = temp;
        temp = temp->prox;
    }

    /* Valor não encontrado */
    if (temp == NULL) {
        printf("Valor nao encontrado!\n");
        return;
    }

    anterior->prox = temp->prox;

    free(temp);

    printf("Valor %d removido!\n", valor);
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

        printf("\n========== MENU ==========\n");
        printf("1 - Inserir valor\n");
        printf("2 - Exibir lista\n");
        printf("3 - Buscar valor\n");
        printf("4 - Remover valor\n");
        printf("0 - Sair\n");
        printf("==========================\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:

                printf("Digite o valor: ");
                scanf("%d", &valor);

                inserirFinal(&lista, valor);

                printf("Valor inserido com sucesso!\n");

                break;

            case 2:

                printf("\nLista encadeada:\n");
                exibirLista(lista);

                break;

            case 3:

                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);

                posicao = buscarValor(lista, valor);

                if (posicao != -1) {
                    printf("Valor %d encontrado na posicao %d\n",
                           valor, posicao);
                } else {
                    printf("Valor %d nao encontrado!\n",
                           valor);
                }

                break;

            case 4:

                printf("Digite o valor para remover: ");
                scanf("%d", &valor);

                removerValor(&lista, valor);

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
