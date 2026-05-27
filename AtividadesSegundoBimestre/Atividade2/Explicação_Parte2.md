Biblioteca utilizadas
#include <stdio.h>
#include <stdlib.h>
stdio.h

Usada para funções de entrada e saída:

printf()
scanf()
stdlib.h

Usada para:

malloc() → alocar memória
free() → liberar memória
exit() → encerrar programa em caso de erro
Estrutura do nó da lista
typedef struct NoSimples {
    int valor;
    struct NoSimples *prox;
} NoSimples;

Aqui foi criada a estrutura principal da lista encadeada.

Campos da struct
int valor

Armazena o valor do nó.

Exemplo:

10
20
30
struct NoSimples *prox

Ponteiro para o próximo nó da lista.

Esse ponteiro é o que faz os nós ficarem “encadeados”.

Exemplo visual:

[10 | * ] -> [20 | * ] -> [30 | NULL]
typedef

O typedef permite usar:

NoSimples

em vez de:

struct NoSimples
Função criarNo
NoSimples* criarNo(int valor)

Essa função cria dinamicamente um novo nó.

Alocação dinâmica
NoSimples *novo =
    (NoSimples*) malloc(sizeof(NoSimples));
O que acontece aqui?
malloc(sizeof(NoSimples))

Reserva memória suficiente para armazenar um nó inteiro.

Conversão de tipo
(NoSimples*)

Converte o retorno do malloc para ponteiro do tipo NoSimples.

Verificação de erro
if (novo == NULL)

Se malloc falhar, ele retorna NULL.

Então:

printf("Erro de alocacao!\n");
exit(1);

encerra o programa.

Inicialização do nó
novo->valor = valor;
novo->prox = NULL;
novo->valor

Recebe o valor enviado para a função.

novo->prox = NULL

Como o nó acabou de ser criado, ele ainda não aponta para ninguém.

Retorno
return novo;

Retorna o endereço do novo nó criado.

Inserção no final da lista
void inserirFinal(NoSimples **head, int valor)

Essa função adiciona um nó no final da lista.

Por que NoSimples **head?

Foi usado ponteiro duplo porque a função pode alterar o início da lista.

Exemplo:

*head = novo;

Isso muda o ponteiro original da main.

Criando novo nó
NoSimples *novo = criarNo(valor);

A função reaproveita a função anterior.

Caso da lista vazia
if (*head == NULL)

Se não existir nenhum nó:

*head = novo;

o novo nó vira o primeiro da lista.

Percorrendo a lista
NoSimples *temp = *head;

while (temp->prox != NULL)

A variável temp percorre os nós até encontrar o último.

Último nó

O último nó possui:

prox == NULL
Ligando o novo nó
temp->prox = novo;

O último nó passa a apontar para o novo.

Exibição da lista
void exibirLista(NoSimples *head)

Mostra todos os elementos.

Lista vazia
if (head == NULL)

Se não houver nós:

printf("Lista vazia!\n");
Percorrendo os nós
while (head != NULL)

Enquanto existir nó:

printf("%d -> ", head->valor);

mostra o valor.

Avançando para o próximo nó
head = head->prox;

Move para o próximo elemento.

Final da lista
printf("NULL\n");

Mostra o fim da lista.

Exemplo:

10 -> 20 -> 30 -> NULL
Busca de valor
int buscarValor(NoSimples *head, int valor)

Procura um valor na lista.

Variável de posição
int posicao = 0;

Conta em qual posição o elemento está.

Percorrendo
while (head != NULL)

Percorre todos os nós.

Comparação
if (head->valor == valor)

Se encontrar:

return posicao;

retorna a posição.

Avançando
head = head->prox;
posicao++;

Vai para o próximo nó e incrementa posição.

Valor não encontrado
return -1;

O -1 indica falha na busca.

Remoção de valor
void removerValor(NoSimples **head, int valor)

Remove o primeiro nó que contém o valor informado.

Lista vazia
if (*head == NULL)

Não há o que remover.

Ponteiros auxiliares
NoSimples *temp = *head;
NoSimples *anterior = NULL;
temp

Percorre a lista.

anterior

Guarda o nó anterior.

Caso especial: remover primeiro nó
if (temp->valor == valor)

Se o valor estiver no primeiro nó:

*head = temp->prox;

O início da lista passa para o próximo nó.

Liberando memória
free(temp);

Remove o nó da memória RAM.

Busca do valor
while (temp != NULL && temp->valor != valor)

Percorre até encontrar o valor.

Avançando ponteiros
anterior = temp;
temp = temp->prox;
Valor não encontrado
if (temp == NULL)

Significa que chegou ao final sem encontrar.

Removendo nó do meio/final
anterior->prox = temp->prox;

O nó anterior “pula” o nó removido.

Exemplo

Antes:

10 -> 20 -> 30

Removendo 20:

10 --------> 30
Liberação da memória
free(temp);

Evita vazamento de memória.

Liberar toda a lista
void liberarLista(NoSimples *head)

Libera todos os nós antes de encerrar o programa.

Variável auxiliar
NoSimples *temp;

Guarda temporariamente o nó atual.

Percorrendo e liberando
while (head != NULL)
Guardando nó atual
temp = head;
Avançando
head = head->prox;
Liberando
free(temp);
Função principal (main)
int main()

Controla o programa.

Inicialização da lista
NoSimples *lista = NULL;

No começo, a lista está vazia.

Variáveis auxiliares
int opcao;
int valor;
int posicao;
opcao

Guarda escolha do menu.

valor

Guarda números digitados.

posicao

Recebe resultado da busca.

Estrutura de repetição principal
do {

Executa o menu continuamente.

Menu
printf("\n========== MENU ==========\n");

Mostra as opções disponíveis.

Entrada da opção
scanf("%d", &opcao);

Lê a escolha do usuário.

switch
switch (opcao)

Executa ações diferentes conforme a opção.

Caso 1 — Inserção
inserirFinal(&lista, valor);

Adiciona novo elemento.

Caso 2 — Exibição
exibirLista(lista);

Mostra a lista.

Caso 3 — Busca
posicao = buscarValor(lista, valor);

Procura o valor.

Caso 4 — Remoção
removerValor(&lista, valor);

Remove elemento.

Caso 0 — Encerrar
printf("Encerrando programa...\n");

Sai do loop.

Condição do loop
} while (opcao != 0);

Repete enquanto o usuário não escolher sair.

Liberação final da memória
liberarLista(lista);

Importante para evitar vazamento de memória.

Funcionamento geral da lista

Exemplo de inserções:

Inserir 10
Inserir 20
Inserir 30

Memória:

lista
  |
  v
[10 | * ] -> [20 | * ] -> [30 | NULL]
