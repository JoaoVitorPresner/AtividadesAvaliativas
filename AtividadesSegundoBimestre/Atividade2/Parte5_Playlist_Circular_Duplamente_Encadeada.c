#include <stdio.h>
#include <stdlib.h>

typedef struct NoPlaylist {
    char musica[100];
    struct NoPlaylist *prox;
    struct NoPlaylist *ant;
} NoPlaylist;

/* =========================
   COPIAR TEXTO
   ========================= */
void copiarTexto(char destino[], char origem[]) {
    int i = 0;

    while (origem[i] != '\0') {
        destino[i] = origem[i];
        i++;
    }

    destino[i] = '\0';
}

/* Remover ENTER do fgets */
void removerEnter(char texto[]) {
    int i = 0;

    while (texto[i] != '\0') {

        if (texto[i] == '\n') {
            texto[i] = '\0';
            return;
        }

        i++;
    }
}

/* =========================
   CRIAR MÚSICA
   ========================= */
NoPlaylist* criarMusica(char nome[]) {

    NoPlaylist *novo =
        (NoPlaylist*) malloc(sizeof(NoPlaylist));

    if (novo == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }

    copiarTexto(novo->musica, nome);

    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}

/* =========================
   ADICIONAR MÚSICA
   ========================= */
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

/* =========================
   PRÓXIMA MÚSICA
   ========================= */
void proximaMusica(NoPlaylist **atual) {

    if (*atual != NULL) {
        *atual = (*atual)->prox;
    }
}

/* =========================
   MÚSICA ANTERIOR
   ========================= */
void musicaAnterior(NoPlaylist **atual) {

    if (*atual != NULL) {
        *atual = (*atual)->ant;
    }
}

/* =========================
   EXIBIR PLAYLIST
   ========================= */
void exibirPlaylist(NoPlaylist *head) {

    if (head == NULL) {
        printf("\nPlaylist vazia!\n");
        return;
    }

    NoPlaylist *temp = head;

    printf("\n=== PLAYLIST ===\n");

    do {
        printf("[%s] <-> ", temp->musica);
        temp = temp->prox;
    }
    while (temp != head);

    printf("(volta ao inicio)\n");
}

/* =========================
   TOTAL DE MÚSICAS
   ========================= */
int totalMusicas(NoPlaylist *head) {

    if (head == NULL) {
        return 0;
    }

    int contador = 0;
    NoPlaylist *temp = head;

    do {
        contador++;
        temp = temp->prox;
    }
    while (temp != head);

    return contador;
}

/* =========================
   TOCAR PLAYLIST
   ========================= */
void tocarPlaylist(NoPlaylist *head) {

    if (head == NULL) {
        printf("\nPlaylist vazia!\n");
        return;
    }

    NoPlaylist *atual = head;

    printf("\n=== TOCANDO PLAYLIST ===\n");

    do {
        printf("Tocando: %s\n", atual->musica);
        atual = atual->prox;
    }
    while (atual != head);

    printf("Fim da playlist!\n");
}

/* =========================
   LIBERAR MEMÓRIA
   ========================= */
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

/* =========================
   MENU
   ========================= */
void menu() {

    printf("\n=========== MENU ===========\n");
    printf("1 - Adicionar musica\n");
    printf("2 - Exibir playlist\n");
    printf("3 - Mostrar musica atual\n");
    printf("4 - Proxima musica\n");
    printf("5 - Musica anterior\n");
    printf("6 - Total de musicas\n");
    printf("7 - Tocar playlist\n");
    printf("0 - Sair\n");
    printf("============================\n");

    printf("Escolha: ");
}

/* =========================
   MAIN
   ========================= */
int main() {

    NoPlaylist *playlist = NULL;
    NoPlaylist *atual = NULL;

    int opcao;
    char nome[100];

    do {

        menu();
        scanf("%d", &opcao);

        getchar(); /* Limpar ENTER */

        switch (opcao) {

            case 1:

                printf("\nDigite o nome da musica: ");
                fgets(nome, 100, stdin);

                removerEnter(nome);

                adicionarMusica(&playlist, nome);

                /* Definir primeira música atual */
                if (atual == NULL) {
                    atual = playlist;
                }

                printf("Musica adicionada!\n");

                break;

            case 2:

                exibirPlaylist(playlist);

                break;

            case 3:

                if (atual == NULL) {
                    printf("\nNenhuma musica na playlist!\n");
                }
                else {
                    printf("\nMusica atual: %s\n",
                           atual->musica);
                }

                break;

            case 4:

                if (atual == NULL) {
                    printf("\nPlaylist vazia!\n");
                }
                else {

                    proximaMusica(&atual);

                    printf("\nProxima musica: %s\n",
                           atual->musica);
                }

                break;

            case 5:

                if (atual == NULL) {
                    printf("\nPlaylist vazia!\n");
                }
                else {

                    musicaAnterior(&atual);

                    printf("\nMusica anterior: %s\n",
                           atual->musica);
                }

                break;

            case 6:

                printf("\nTotal de musicas: %d\n",
                       totalMusicas(playlist));

                break;

            case 7:

                tocarPlaylist(playlist);

                break;

            case 0:

                printf("\nEncerrando programa...\n");

                break;

            default:

                printf("\nOpcao invalida!\n");
        }

    }
    while (opcao != 0);

    liberarPlaylist(playlist);

    return 0;
}
