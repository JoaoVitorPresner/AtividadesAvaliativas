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

int main() {

    NoSimples *lista = NULL;

    /* Inserindo valores */
    inserirFinal(&lista, 10);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 30);
    inserirFinal(&lista, 40);

    /* Exibindo lista original */
    printf("Lista original:\n");
    exibirLista(lista);

    /* Invertendo lista */
    inverterLista(&lista);

    /* Exibindo lista invertida */
    printf("\nLista invertida:\n");
    exibirLista(lista);

    return 0;
}
