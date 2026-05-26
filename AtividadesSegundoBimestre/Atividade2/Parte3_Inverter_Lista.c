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
