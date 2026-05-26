void dividirLista(NoSimples *head, NoSimples **lista1, NoSimples **lista2) {
    if (head == NULL) {
        *lista1 = NULL;
        *lista2 = NULL;
        return;
    }

    NoSimples *lento = head;
    NoSimples *rapido = head;

    while (rapido->prox != NULL && rapido->prox->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }

    *lista1 = head;
    *lista2 = lento->prox;

    lento->prox = NULL;
}

void liberarLista(NoSimples *head) {
    NoSimples *temp;

    while (head != NULL) {
        temp = head;
        head = head->prox;
        free(temp);
    }
}
