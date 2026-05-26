typedef struct NoPlaylist {
    char musica[100];
    struct NoPlaylist *prox;
    struct NoPlaylist *ant;
} NoPlaylist;

/* Copiar string manualmente */
void copiarTexto(char destino[], char origem[]) {
    int i = 0;

    while (origem[i] != '\0') {
        destino[i] = origem[i];
        i++;
    }

    destino[i] = '\0';
}

/* Criar nó playlist */
NoPlaylist* criarMusica(char nome[]) {
    NoPlaylist *novo = (NoPlaylist*) malloc(sizeof(NoPlaylist));

    if (novo == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }

    copiarTexto(novo->musica, nome);

    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}

/* Adicionar música */
void adicionarMusica(NoPlaylist **head, char nome[]) {
    NoPlaylist *novo = criarMusica(nome);

    /* Lista vazia */
    if (*head == NULL) {
        novo->prox = novo;
        novo->ant = novo;
        *head = novo;
        return;
    }

    NoPlaylist *ultimo = (*head)->ant;

    ultimo->prox = novo;
    novo->ant = ultimo;

    novo->prox = *head;
    (*head)->ant = novo;
}

/* Próxima música */
void proximaMusica(NoPlaylist **atual) {
    if (*atual != NULL) {
        *atual = (*atual)->prox;
    }
}

/* Música anterior */
void musicaAnterior(NoPlaylist **atual) {
    if (*atual != NULL) {
        *atual = (*atual)->ant;
    }
}

/* Exibir playlist */
void exibirPlaylist(NoPlaylist *head) {
    if (head == NULL) {
        printf("Playlist vazia!\n");
        return;
    }

    NoPlaylist *temp = head;

    do {
        printf("[%s] <-> ", temp->musica);
        temp = temp->prox;
    } while (temp != head);

    printf("(volta ao inicio)\n");
}

/* Total de músicas */
int totalMusicas(NoPlaylist *head) {
    if (head == NULL) {
        return 0;
    }

    int contador = 0;
    NoPlaylist *temp = head;

    do {
        contador++;
        temp = temp->prox;
    } while (temp != head);

    return contador;
}

/* Tocar playlist uma vez completa */
void tocarPlaylist(NoPlaylist *head) {
    if (head == NULL) {
        printf("Playlist vazia!\n");
        return;
    }

    NoPlaylist *atual = head;

    do {
        printf("Tocando: %s\n", atual->musica);
        atual = atual->prox;
    } while (atual != head);

    printf("Todas as musicas foram tocadas!\n");
}

/* Liberar playlist */
void liberarPlaylist(NoPlaylist *head) {
    if (head == NULL) {
        return;
    }

    NoPlaylist *temp = head->prox;

    while (temp != head) {
        NoPlaylist *aux = temp;
        temp = temp->prox;
        free(aux);
    }

    free(head);
}
