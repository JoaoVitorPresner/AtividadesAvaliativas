#include <stdio.h>
#include <stdlib.h>

typedef struct NoSimples {
    int valor;
    struct NoSimples *prox;
} NoSimples;

/* =========================
   CRIAR NÓ
   ========================= */
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

/* =========================
   INSERIR NO FINAL
   ========================= */
void inserirFinal(NoSimples **head, int valor) {

    NoSimples *novo = criarNo(valor);

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

/* =========================
   EXIBIR LISTA
   ========================= */
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

/* =========================
   DIVIDIR LISTA
   ========================= */
void dividirLista(
    NoSimples *head,
    NoSimples **lista1,
    NoSimples **lista2
) {

    if (head == NULL) {
        *lista1 = NULL;
        *lista2 = NULL;
        return;
    }

    NoSimples *lento = head;
    NoSimples *rapido = head;

    while (
        rapido->prox != NULL &&
        rapido->prox->prox != NULL
    ) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }

    *lista1 = head;
    *lista2 = lento->prox;

    lento->prox = NULL;
}

/* =========================
   LIBERAR LISTA
   ========================= */
void liberarLista(NoSimples *head) {

    NoSimples *temp;

    while (head != NULL) {
        temp = head;
        head = head->prox;
        free(temp);
    }
}

/* =========================
   MENU
   ========================= */
void menu() {

    printf("\n=========== MENU ===========\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Exibir lista\n");
    printf("3 - Dividir lista\n");
    printf("4 - Sair\n");
    printf("============================\n");
    printf("Escolha uma opcao: ");
}

/* =========================
   MAIN
   ========================= */
int main() {

    NoSimples *lista = NULL;
    NoSimples *lista1 = NULL;
    NoSimples *lista2 = NULL;

    int opcao;
    int valor;

    do {

        menu();
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:

                printf("\nDigite o valor: ");
                scanf("%d", &valor);

                inserirFinal(&lista, valor);

                printf("Valor inserido com sucesso!\n");

                break;

            case 2:

                printf("\nLista atual:\n");
                exibirLista(lista);

                break;

            case 3:

                if (lista == NULL) {
                    printf("\nA lista esta vazia!\n");
                    break;
                }

                dividirLista(lista, &lista1, &lista2);

                printf("\nPrimeira metade:\n");
                exibirLista(lista1);

                printf("\nSegunda metade:\n");
                exibirLista(lista2);

                /* Após dividir,
                   lista original deixa de existir */
                lista = NULL;

                break;

            case 4:

                printf("\nEncerrando programa...\n");

                break;

            default:

                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 4);

    /* Liberando memória */
    liberarLista(lista);
    liberarLista(lista1);
    liberarLista(lista2);

    return 0;
}
