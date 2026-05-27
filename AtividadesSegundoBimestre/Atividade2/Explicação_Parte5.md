1. Bibliotecas
#include <stdio.h>
#include <stdlib.h>
stdio.h

Usada para:

printf()
scanf()
fgets()

Responsável pela entrada e saída de dados.

stdlib.h

Usada para:

malloc()
free()
exit()

Responsável pela alocação dinâmica de memória.

2. Estrutura da Lista
typedef struct NoPlaylist {
    char musica[100];
    struct NoPlaylist *prox;
    struct NoPlaylist *ant;
} NoPlaylist;

Aqui foi criada a estrutura do nó da playlist.

Cada nó representa uma música.

Componentes da estrutura
char musica[100]

Armazena o nome da música.

Exemplo:

"Bohemian Rhapsody"
struct NoPlaylist *prox

Ponteiro para a próxima música.

struct NoPlaylist *ant

Ponteiro para a música anterior.

Por que é uma lista duplamente ligada?

Porque cada nó possui:

ponteiro para frente (prox)
ponteiro para trás (ant)

Isso permite navegar:

próxima música
música anterior
Por que é circular?

Porque:

a última música aponta para a primeira;
a primeira aponta para a última.

Exemplo:

Rock -> Pop -> Jazz
 ^               |
 |_____|

Isso permite repetir infinitamente a playlist.

3. Função copiarTexto
void copiarTexto(char destino[], char origem[])

Essa função copia manualmente uma string.

Funcionamento
while (origem[i] != '\0')

Percorre a string até encontrar:

'\0'

que representa o fim da string.

Cópia caractere por caractere
destino[i] = origem[i];
Finalização da string
destino[i] = '\0';

Muito importante para indicar o fim do texto.

Por que criar essa função?

Para evitar usar:

strcpy()

da biblioteca <string.h>.

O código faz a cópia manualmente para mostrar como strings funcionam internamente.

4. Função removerEnter
void removerEnter(char texto[])

Serve para remover o ENTER capturado pelo fgets().

Problema do fgets

Quando o usuário digita:

Metallica

o fgets() salva:

Metallica\n

O ENTER (\n) fica armazenado.

Como a função resolve?

Percorre a string:

while (texto[i] != '\0')

Quando encontra:

'\n'

substitui por:

'\0'
Resultado

Antes:

Metallica\n

Depois:

Metallica
5. Função criarMusica
NoPlaylist* criarMusica(char nome[])

Cria dinamicamente um novo nó.

Alocação dinâmica
NoPlaylist *novo =
    (NoPlaylist*) malloc(sizeof(NoPlaylist));

Reserva memória para um nó.

Verificação de erro
if (novo == NULL)

Se não houver memória disponível:

printf("Erro de alocacao!\n");
exit(1);

O programa é encerrado.

Copiando nome da música
copiarTexto(novo->musica, nome);
Inicialização dos ponteiros
novo->prox = NULL;
novo->ant = NULL;

Evita lixo de memória.

Retorno
return novo;

Retorna o novo nó criado.

6. Função adicionarMusica
void adicionarMusica(NoPlaylist **head, char nome[])

Adiciona uma música na playlist.

Por que NoPlaylist **head?

Porque a função pode alterar o ponteiro principal da lista.

É necessário passar o endereço do ponteiro.

Criação do nó
NoPlaylist *novo = criarMusica(nome);
Caso 1: lista vazia
if (*head == NULL)

Se não existe música:

O nó aponta para si mesmo
novo->prox = novo;
novo->ant = novo;

Isso cria a circularidade.

Atualiza a cabeça da lista
*head = novo;
Caso 2: lista já possui músicas
Último nó
NoPlaylist *ultimo = (*head)->ant;

Como a lista é circular:

o anterior da cabeça é o último nó.
Ligando último ao novo
ultimo->prox = novo;
novo->ant = ultimo;
Ligando novo ao início
novo->prox = *head;
(*head)->ant = novo;

Agora o novo nó entra no final da lista.

Estrutura final

Antes:

A <-> B <-> C

Depois:

A <-> B <-> C <-> D

com circularidade.

7. Função proximaMusica
void proximaMusica(NoPlaylist **atual)

Move para a próxima música.

Funcionamento
*atual = (*atual)->prox;

O ponteiro atual avança.

Exemplo

Antes:

Rock

Depois:

Pop
8. Função musicaAnterior
void musicaAnterior(NoPlaylist **atual)

Volta para a música anterior.

Funcionamento
*atual = (*atual)->ant;

Como a lista é duplamente ligada, voltar é simples.

9. Função exibirPlaylist
void exibirPlaylist(NoPlaylist *head)

Mostra todas as músicas.

Verificação de lista vazia
if (head == NULL)
Percorrendo lista circular
do {

Foi usado do while porque:

a lista é circular;
precisa mostrar pelo menos um nó.
Impressão
printf("[%s] <-> ", temp->musica);
Avança
temp = temp->prox;
Condição de parada
while (temp != head);

Quando volta ao início, encerra.

10. Função totalMusicas
int totalMusicas(NoPlaylist *head)

Conta quantos nós existem.

Variável contador
int contador = 0;
Percorre lista
contador++;
temp = temp->prox;
Retorno
return contador;
11. Função tocarPlaylist
void tocarPlaylist(NoPlaylist *head)

Simula tocar músicas.

Percorre toda lista
printf("Tocando: %s\n", atual->musica);
Resultado
Tocando: Rock
Tocando: Pop
Tocando: Jazz
12. Função liberarPlaylist
void liberarPlaylist(NoPlaylist *head)

Libera toda memória alocada.

Muito importante em C.

Por que liberar memória?

Porque cada malloc() ocupa RAM.

Sem free(), ocorre:

Vazamento de memória (memory leak)
Funcionamento
Começa do segundo nó
NoPlaylist *temp = head->prox;
Percorre até voltar ao início
while (temp != head)
Guarda nó atual
NoPlaylist *aux = temp;
Avança
temp = temp->prox;
Libera memória
free(aux);
Libera cabeça
free(head);
13. Função menu
void menu()

Mostra opções do programa.

Estrutura do menu
1 - Adicionar musica
2 - Exibir playlist
3 - Mostrar musica atual
...
14. Função main

É a principal função do programa.

Variáveis principais
Playlist
NoPlaylist *playlist = NULL;

Cabeça da lista.

Música atual
NoPlaylist *atual = NULL;

Controla música sendo tocada.

Laço principal
do {

Repete menu até usuário escolher sair.

Leitura da opção
scanf("%d", &opcao);
Limpeza do ENTER
getchar();

Evita problemas no fgets().

Estrutura switch

Controla cada opção do menu.

Caso 1 — adicionar música
fgets(nome, 100, stdin);

Lê nome da música.

Remove ENTER
removerEnter(nome);
Adiciona música
adicionarMusica(&playlist, nome);
Define música atual
if (atual == NULL)

Na primeira inserção:

atual = playlist;
Caso 2 — exibir playlist
exibirPlaylist(playlist);
Caso 3 — mostrar música atual
printf("%s", atual->musica);
Caso 4 — próxima música
proximaMusica(&atual);
Caso 5 — música anterior
musicaAnterior(&atual);
Caso 6 — total de músicas
totalMusicas(playlist);
Caso 7 — tocar playlist
tocarPlaylist(playlist);
Caso 0 — sair
liberarPlaylist(playlist);

Libera memória antes de encerrar.
