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

void inserirPosicao(NoSimples **head, int valor, int posicao) {
    if (posicao < 0) {
        printf("Posicao invalida!\n");
        return;
    }

    NoSimples *novo = criarNo(valor);

    /* Inserir no início */
    if (posicao == 0) {
        novo->prox = *head;
        *head = novo;
        return;
    }

    NoSimples *temp = *head;
    int i = 0;

    while (temp != NULL && i < posicao - 1) {
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
