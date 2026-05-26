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
