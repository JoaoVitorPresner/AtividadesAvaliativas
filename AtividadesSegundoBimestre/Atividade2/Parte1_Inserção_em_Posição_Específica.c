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
