#include <stdio.h>
#include <stdlib.h>

typedef struct NoSimples {
    int valor;
    struct NoSimples *prox;
} NoSimples;

/* Criar nó */
NoSimples* criarNo(int valor) {
    NoSimples *novo = (NoSimples*) malloc(sizeof(NoSimples));

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
    while (head != NULL) {
        printf("%d -> ", head->valor);
        head = head->prox;
    }

    printf("NULL\n");
}

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

int main() {

    NoSimples *lista = NULL;

    /* Inserindo valores */
    inserirFinal(&lista, 10);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 30);
    inserirFinal(&lista, 40);

    /* Exibindo lista */
    printf("Lista encadeada:\n");
    exibirLista(lista);

    /* Buscando valor */
    int valorBusca = 30;

    int posicao = buscarValor(lista, valorBusca);

    if (posicao != -1) {
        printf("Valor %d encontrado na posicao %d\n",
               valorBusca, posicao);
    } else {
        printf("Valor %d nao encontrado na lista\n",
               valorBusca);
    }

    return 0;
}
