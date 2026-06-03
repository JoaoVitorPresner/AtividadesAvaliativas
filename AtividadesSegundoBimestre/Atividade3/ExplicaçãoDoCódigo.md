1- Bibliotecas Utilizadas
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

2- Definição do Tamanho da Tabela
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

3- Estrutura do Nó
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

4- Tabela Hash
No *tabela[TAM];

Cria um vetor com 10 posições.

Cada posição guarda o início de uma lista encadeada.

Visualmente:

tabela

[0] -> NULL
[1] -> NULL
[2] -> NULL
[3] -> NULL
[4] -> NULL
[5] -> NULL
[6] -> NULL
[7] -> NULL
[8] -> NULL
[9] -> NULL

5- Variável Global
int totalElementos = 0;

Conta quantas palavras existem no dicionário.

Exemplo:

Inseriu 3 palavras

totalElementos = 3

6- Função Hash
int funcaoHash(char *palavra)

Recebe uma palavra e retorna o índice da tabela.

Soma dos caracteres
int soma = 0;
Laço
for (int i = 0; palavra[i] != '\0'; i++)

Percorre toda a string.

Exemplo:

"CASA"

ASCII:

C = 67
A = 65
S = 83
A = 65

Soma:

67 + 65 + 83 + 65 = 280
Retorno
return soma % TAM;

Como:

TAM = 10

Então:

280 % 10 = 0

Índice:

0

A palavra será armazenada em:

tabela[0]

7- Inserção
void inserir(char *palavra, char *definicao)

Insere um novo termo.

Descobrir posição
int indice = funcaoHash(palavra);

Exemplo:

CASA → índice 0
Percorrer lista
No *atual = tabela[indice];

Começa no primeiro nó da lista.

Verificar duplicidade
while (atual != NULL)

Percorre toda a lista.

Comparação
strcmp(atual->palavra, palavra)

Retorna:

0 → iguais

Se encontrar:

printf("Erro: palavra ja cadastrada!");
return;

Impede duplicação.

Criar novo nó
No *novo = (No *) malloc(sizeof(No));

Reserva memória.

Verificar erro
if (novo == NULL)

Se não houver memória disponível.

Copiar dados
strcpy(novo->palavra, palavra);
strcpy(novo->definicao, definicao);
Inserção no início
novo->prox = tabela[indice];

Liga o novo nó ao antigo primeiro.

tabela[indice] = novo;

Novo nó vira o primeiro.

Exemplo:

Antes:

CASA -> CARRO

Depois de inserir LIVRO:

LIVRO -> CASA -> CARRO
Atualizar contador
totalElementos++;

8- Busca
void buscar(char *palavra)

Localiza uma palavra.

Encontrar índice
int indice = funcaoHash(palavra);
Percorrer lista
while (atual != NULL)
Comparação
strcmp(atual->palavra, palavra)

Se encontrar:

printf("Palavra...");
printf("Definicao...");

Exemplo:

Palavra: Casa
Definicao: Local para morar.

Se não encontrar:

printf("Palavra nao encontrada!");

9- Remoção
void removerPalavra(char *palavra)

Remove uma palavra.

Ponteiros
No *atual
No *anterior

Exemplo:

Casa -> Carro -> Livro

Durante a busca:

anterior = Casa
atual = Carro
Caso encontrado
strcmp(...) == 0
Se for o primeiro
if (anterior == NULL)

Exemplo:

Casa -> Carro

Removendo Casa:

Carro

Código:

tabela[indice] = atual->prox;
Se estiver no meio
anterior->prox = atual->prox;

Exemplo:

Antes:

Casa -> Carro -> Livro

Depois:

Casa -> Livro
Liberar memória
free(atual);

Evita vazamento de memória.

Atualizar contador
totalElementos--;

10- Exibição da Tabela
void exibirTabela()

Mostra toda a estrutura.

Laço principal:

for (int i = 0; i < TAM; i++)

Percorre as 10 posições.

Exemplo de saída:

[0] -> (CASA) -> (CARRO) -> NULL
[1] -> NULL
[2] -> (LIVRO) -> NULL

11- Estatísticas
void estatisticas()

Calcula informações sobre a tabela.

Variáveis
int maiorLista = 0;
int totalColisoes = 0;
Contar elementos por posição
contador++;

Conta quantos nós existem em cada índice.

Exemplo:

[0] -> CASA -> CARRO -> LIVRO

contador:

3
Maior lista
if (contador > maiorLista)

Guarda a maior quantidade encontrada.

Exemplo:

posição 0 = 3 elementos
posição 1 = 1 elemento
posição 2 = 2 elementos

Resultado:

Maior lista = 3
Colisões
if (contador > 1)

Se há mais de um elemento na posição.

Exemplo:

3 elementos

Colisões:

3 - 1 = 2
Fator de carga
float fatorCarga =
(float) totalElementos / TAM;

Fórmula:

Fator de Carga=
Tamanho da Tabela
N
u
ˊ
mero de Elementos
	​


Exemplo:

15 elementos
10 posições

Resultado:

1.5

Quanto maior o fator de carga, maior tende a ser o número de colisões.

12- Liberação de Memória
void liberarTabela()

Executada ao encerrar o programa.

Percorre todas as listas:

for (int i = 0; i < TAM; i++)

Enquanto houver nós:

while (atual != NULL)

Guarda o nó atual:

No *temp = atual;

Avança:

atual = atual->prox;

Libera:

free(temp);

Ao final:

tabela[i] = NULL;

13- Função Main
int main()

Ponto de entrada do programa.

Variáveis
int opcao;
char palavra[50];
char definicao[200];
Inicializar tabela
for (int i = 0; i < TAM; i++)
{
    tabela[i] = NULL;
}

Todas as posições começam vazias.

Menu Principal
do
{
   ...
}
while(opcao != 0);

Repete até o usuário escolher sair.

Menu:

1 Inserir
2 Buscar
3 Remover
4 Exibir
5 Estatísticas
0 Sair
Leitura da opção
scanf("%d", &opcao);
getchar();

O getchar() remove o \n deixado pelo scanf.

Entrada de texto
fgets(...)

Lê a string completa.

Remover quebra de linha:

palavra[strcspn(palavra, "\n")] = '\0';

Exemplo:

Antes:

Casa\n

Depois:

Casa
Switch
switch(opcao)

Escolhe qual função executar.

Caso 1
inserir(...)
Caso 2
buscar(...)
Caso 3
removerPalavra(...)
Caso 4
exibirTabela()
Caso 5
estatisticas()
Caso 0
liberarTabela();

Libera toda memória antes de encerrar.
