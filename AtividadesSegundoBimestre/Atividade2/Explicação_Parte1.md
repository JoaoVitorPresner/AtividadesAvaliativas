1. Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
stdio.h

Biblioteca usada para entrada e saída de dados:

printf()
scanf()
stdlib.h

Biblioteca usada para:

malloc() → alocação dinâmica
free() → liberar memória
exit() → encerrar programa
2. Estrutura da Lista Encadeada
typedef struct NoSimples {
    int valor;
    struct NoSimples *prox;
} NoSimples;

Aqui foi criada a estrutura do nó da lista.

Campos da struct
int valor

Armazena o número do nó.

struct NoSimples *prox

Ponteiro que guarda o endereço do próximo nó.

Funcionamento visual

Exemplo da lista:

10 -> 20 -> 30 -> NULL

Cada nó possui:

valor	prox
10	endereço do próximo
20	endereço do próximo
30	NULL

O NULL indica o fim da lista.

3. Função criarNo()
NoSimples* criarNo(int valor)

Essa função cria dinamicamente um novo nó.

Alocação dinâmica
NoSimples *novo =
    (NoSimples*) malloc(sizeof(NoSimples));
O que acontece aqui?
sizeof(NoSimples)

Calcula quantos bytes a struct ocupa.

malloc(...)

Reserva memória na RAM.

Retorno do malloc

Retorna o endereço da memória alocada.

Conversão de tipo
(NoSimples*)

Converte o retorno do malloc para ponteiro do tipo NoSimples.

Verificação de erro
if (novo == NULL)

Se o sistema não conseguir reservar memória:

printf("Erro de alocacao!\n");
exit(1);

O programa encerra imediatamente.

Inicialização do nó
novo->valor = valor;
novo->prox = NULL;
Operador ->

Usado para acessar campos de uma struct através de ponteiro.

Equivale a:

(*novo).valor
Retorno
return novo;

Retorna o endereço do novo nó criado.

4. Inserção no final
void inserirFinal(NoSimples **head, int valor)

Essa função adiciona um elemento no final da lista.

Por que NoSimples **head?

A cabeça da lista pode mudar.

Por isso é necessário passar:

ponteiro para ponteiro

Assim a função consegue alterar a lista original.

Criação do novo nó
NoSimples *novo = criarNo(valor);
Caso especial: lista vazia
if (*head == NULL)

Se não existe nenhum nó:

*head = novo;

O novo nó se torna o primeiro da lista.

Percorrendo a lista
NoSimples *temp = *head;

Variável auxiliar para caminhar pela lista.

Loop de navegação
while (temp->prox != NULL)

Enquanto existir próximo nó:

temp = temp->prox;

Vai avançando.

Inserção final

Quando chega no último nó:

temp->prox = novo;

O último passa a apontar para o novo nó.

Exemplo visual

Antes:

10 -> 20 -> NULL

Inserindo 30:

10 -> 20 -> 30 -> NULL
5. Exibir lista
void exibirLista(NoSimples *head)

Percorre a lista mostrando todos os valores.

Lista vazia
if (head == NULL)

Se estiver vazia:

printf("Lista vazia!\n");
Percorrendo os nós
while (head != NULL)

Enquanto existir nó:

printf("%d -> ", head->valor);

Mostra o valor.

Depois avança:

head = head->prox;
Finalização
printf("NULL\n");

Mostra o fim da lista.

Exemplo

Saída:

10 -> 20 -> 30 -> NULL
6. Inserção em posição específica
void inserirPosicao(NoSimples **head,
                    int valor,
                    int posicao)

Insere um nó em qualquer posição.

Verificando posição inválida
if (posicao < 0)

Posições negativas não existem.

Criação do novo nó
NoSimples *novo = criarNo(valor);
Inserção no início
if (posicao == 0)

O novo nó vira o primeiro.

Ligação
novo->prox = *head;

O novo aponta para o antigo primeiro.

Atualização da cabeça
*head = novo;

Agora ele é o início da lista.

Percorrendo até a posição
while (temp != NULL &&
       i < posicao - 1)

O objetivo é parar no nó anterior à posição desejada.

Exemplo

Lista:

10 -> 20 -> 30

Inserir na posição 2:

O laço para no 20.

Verificação de erro
if (temp == NULL)

Significa que a posição não existe.

Inserção do nó
novo->prox = temp->prox;
temp->prox = novo;

Primeiro:

O novo aponta para o próximo do atual.

Depois:

O atual aponta para o novo.

Exemplo visual

Antes:

10 -> 20 -> 30

Inserindo 99 na posição 1:

Passo 1:

99 -> 20

Passo 2:

10 -> 99 -> 20 -> 30
7. Remover início
void removerInicio(NoSimples **head)

Remove o primeiro nó.

Lista vazia
if (*head == NULL)

Não há o que remover.

Guardando o primeiro nó
NoSimples *temp = *head;
Avançando a cabeça
*head = (*head)->prox;

Agora o segundo nó vira o primeiro.

Liberando memória
free(temp);

Remove o nó da RAM.

Exemplo

Antes:

10 -> 20 -> 30

Depois:

20 -> 30
8. Buscar valor
void buscarValor(NoSimples *head, int valor)

Procura um valor na lista.

Variáveis auxiliares
int posicao = 0;
int encontrado = 0;
posicao

Conta onde o nó está.

encontrado

Indica se o valor foi encontrado.

Percorrendo a lista
while (head != NULL)
Comparação
if (head->valor == valor)

Se encontrar:

printf("Valor encontrado...");
Avançando
head = head->prox;
posicao++;
Caso não encontre
if (!encontrado)

Equivale a:

if (encontrado == 0)
9. Liberar memória
void liberarLista(NoSimples *head)

Libera todos os nós da lista.

Isso evita vazamento de memória.

Percorrendo e liberando
while (head != NULL)
Guardando nó atual
temp = head;
Avançando
head = head->prox;
Liberando
free(temp);
10. Função principal — main()
int main()

Controla o programa inteiro.

Inicialização da lista
NoSimples *lista = NULL;

Inicialmente a lista está vazia.

Variáveis do menu
int opcao;
int valor;
int posicao;
Estrutura do menu
do {

Repete até o usuário escolher sair.

Exibição do menu
printf(...)

Mostra as opções.

Entrada do usuário
scanf("%d", &opcao);

Lê a opção escolhida.

Estrutura switch-case
switch (opcao)

Executa a função correspondente.

Caso 1 — Inserir final
inserirFinal(&lista, valor);
Caso 2 — Inserir posição
inserirPosicao(&lista,
                valor,
                posicao);
Caso 3 — Exibir
exibirLista(lista);
Caso 4 — Buscar
buscarValor(lista, valor);
Caso 5 — Remover início
removerInicio(&lista);
Caso 0 — Encerrar
printf("Encerrando programa...\n");
Repetição
} while (opcao != 0);

Continua até escolher 0.

Liberação final
liberarLista(lista);

Libera toda memória usada.

Conceitos importantes usados
1. Structs

Permitem criar tipos personalizados.

2. Ponteiros

Armazenam endereços de memória.

3. Ponteiro para ponteiro

Permite alterar a cabeça da lista.

NoSimples **head
4. Alocação dinâmica

Memória criada em tempo de execução.

malloc()
5. Liberação de memória

Evita vazamento de memória.

free()
