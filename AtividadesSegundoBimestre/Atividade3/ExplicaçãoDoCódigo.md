1. Bibliotecas Utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<stdio.h>

Biblioteca responsável pelas operações de entrada e saída.

Funções utilizadas:

printf();
scanf();
fgets();
getchar();

Exemplo:

printf("Olá");

Mostra texto na tela.

<stdlib.h>

Biblioteca usada para:

malloc();
free();

Responsável pela alocação dinâmica de memória.

Exemplo:

malloc(sizeof(No));

Cria espaço na memória para um nó.

<string.h>

Biblioteca usada para manipular strings.

Funções utilizadas:

strcmp();
strcpy();
strcspn();
2. Definição do Tamanho da Tabela
#define TAM 10

Cria uma constante chamada TAM.

Significa que a tabela hash terá:

10 posições

Visualmente:

[0]
[1]
[2]
[3]
[4]
[5]
[6]
[7]
[8]
[9]
3. Estrutura do Nó
typedef struct No {
    char palavra[50];
    char definicao[200];
    struct No *prox;
} No;

Cria o tipo de dado que será armazenado na tabela.

Campo palavra
char palavra[50];

Armazena a palavra.

Exemplo:

"Computador"
Campo definição
char definicao[200];

Armazena a explicação da palavra.

Exemplo:

"Máquina capaz de processar dados."
Ponteiro para próximo nó
struct No *prox;

Liga um nó ao próximo.

Exemplo:

Casa -> Carro -> Caneta -> NULL
typedef
typedef struct No {...} No;

Permite escrever:

No *novo;

ao invés de:

struct No *novo;
