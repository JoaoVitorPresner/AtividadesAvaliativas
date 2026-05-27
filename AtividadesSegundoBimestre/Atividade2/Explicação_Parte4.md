1. Bibliotecas
#include <stdio.h>
#include <stdlib.h>
stdio.h

Usada para:

printf() → mostrar mensagens na tela
scanf() → ler dados do usuário
stdlib.h

Usada para:

malloc() → alocar memória dinamicamente
free() → liberar memória
exit() → encerrar programa em caso de erro
2. Estrutura do nó
typedef struct NoSimples {
    int valor;
    struct NoSimples *prox;
} NoSimples;

Aqui foi criada a estrutura da lista encadeada.

Como funciona

Cada nó possui:

int valor;

Armazena o número digitado.

E:

struct NoSimples *prox;

Guarda o endereço do próximo nó da lista.

Representação visual

Se a lista tiver:

10 -> 20 -> 30

Na memória fica assim:

+------+-------+
| 10   |   •---|----+
+------+-------+    |
                    v
              +------+-------+
              | 20   |   •---|----+
              +------+-------+    |
                                  v
                            +------+-------+
                            | 30   | NULL  |
                            +------+-------+
typedef

O typedef permite usar:

NoSimples

em vez de:

struct NoSimples
3. Função criarNo
NoSimples* criarNo(int valor)

Essa função cria um novo nó dinamicamente.

Passo 1 — Alocação de memória
NoSimples *novo =
    (NoSimples*) malloc(sizeof(NoSimples));
O que acontece aqui

malloc() reserva espaço na memória RAM para armazenar um nó.

sizeof(NoSimples)

pega o tamanho da estrutura.

Conversão de ponteiro
(NoSimples*)

Converte o retorno do malloc para o tipo correto.

4. Verificação de erro
if (novo == NULL)

Se o computador não conseguir reservar memória:

printf("Erro de alocacao!\n");
exit(1);

O programa encerra.

5. Inicialização do nó
novo->valor = valor;

Armazena o valor recebido.

novo->prox = NULL;

O novo nó ainda não aponta para ninguém.

Retorno
return novo;

Retorna o endereço do nó criado.

6. Inserção no final
void inserirFinal(NoSimples **head, int valor)

Essa função adiciona um novo elemento no final da lista.

Por que NoSimples **head?

A cabeça da lista pode mudar.

Exemplo:

Antes:

head = NULL

Depois da primeira inserção:

head -> novo nó

Então precisamos alterar o ponteiro original.

Por isso é usado:

NoSimples **head

(ponteiro para ponteiro)

Criando o novo nó
NoSimples *novo = criarNo(valor);
Caso lista vazia
if (*head == NULL)

Se não existe nenhum elemento:

*head = novo;

O novo nó vira o primeiro da lista.

Percorrendo a lista
NoSimples *temp = *head;

temp é usado para caminhar pela lista.

Laço de repetição
while (temp->prox != NULL)

Enquanto existir próximo nó:

temp = temp->prox;

Avança para frente.

Inserção final

Quando chega no último nó:

temp->prox = novo;

O último nó passa a apontar para o novo.

7. Função exibirLista
void exibirLista(NoSimples *head)

Mostra todos os elementos.

Lista vazia
if (head == NULL)

Se estiver vazia:

printf("Lista vazia!\n");
Percorrendo a lista
while (head != NULL)

Enquanto existir nó:

printf("%d -> ", head->valor);

Mostra o valor.

Avançando
head = head->prox;

Vai para o próximo nó.

Final da lista

Quando chega no fim:

printf("NULL\n");

Indica que não existe próximo elemento.

8. Função dividirLista
void dividirLista(
    NoSimples *head,
    NoSimples **lista1,
    NoSimples **lista2
)

Essa função divide a lista em duas metades.

Objetivo

Exemplo:

Lista original:

10 -> 20 -> 30 -> 40 -> 50 -> NULL

Resultado:

Lista1: 10 -> 20 -> 30
Lista2: 40 -> 50
Caso lista vazia
if (head == NULL)

As duas listas ficam vazias.

Técnica do ponteiro lento e rápido
NoSimples *lento = head;
NoSimples *rapido = head;

Essa é uma técnica clássica.

Funcionamento
Ponteiro lento

Anda 1 nó por vez.

Ponteiro rápido

Anda 2 nós por vez.

Laço principal
while (
    rapido->prox != NULL &&
    rapido->prox->prox != NULL
)

Enquanto o rápido conseguir avançar dois passos:

lento = lento->prox;
rapido = rapido->prox->prox;
Exemplo visual

Lista:

10 -> 20 -> 30 -> 40 -> 50
Iteração 1
Lento = 20
Rápido = 30
Iteração 2
Lento = 30
Rápido = 50

Fim do laço.

Separando as listas
*lista1 = head;

A primeira lista começa no início.

*lista2 = lento->prox;

A segunda começa após o lento.

Quebrando a ligação
lento->prox = NULL;

Agora as listas ficam independentes.

Resultado visual

Antes:

10 -> 20 -> 30 -> 40 -> 50

Depois:

Lista1:
10 -> 20 -> 30 -> NULL

Lista2:
40 -> 50 -> NULL
9. Função liberarLista
void liberarLista(NoSimples *head)

Responsável por liberar a memória usada pela lista.

Por que isso é importante?

Em C, memória alocada com malloc()
não é liberada automaticamente.

Se não liberar:

ocorre vazamento de memória;
o programa consome RAM desnecessariamente.
Processo
while (head != NULL)

Enquanto existir nó:

Guarda nó atual
temp = head;
Avança a lista
head = head->prox;
Libera memória
free(temp);
10. Função menu
void menu()

Apenas mostra as opções na tela.

Interface
1 - Inserir elemento
2 - Exibir lista
3 - Dividir lista
4 - Sair
11. Função principal (main)
int main()

Controla todo o programa.

Criação das listas
NoSimples *lista = NULL;
NoSimples *lista1 = NULL;
NoSimples *lista2 = NULL;
lista → lista original
lista1 → primeira metade
lista2 → segunda metade
Variáveis auxiliares
int opcao;
int valor;
opcao → escolha do menu
valor → número digitado
Estrutura principal
do {

Repete o menu até o usuário escolher sair.

Leitura da opção
scanf("%d", &opcao);
switch

Executa uma ação dependendo da opção escolhida.

CASE 1 — Inserção
inserirFinal(&lista, valor);

Adiciona um novo valor.

CASE 2 — Exibição
exibirLista(lista);

Mostra a lista.

CASE 3 — Divisão
dividirLista(lista, &lista1, &lista2);

Divide a lista em duas partes.

Importante

Depois:

lista = NULL;

A lista original deixa de existir como lista única.

Agora existem duas listas separadas.

CASE 4 — Encerramento

Finaliza o programa.

DEFAULT
printf("\nOpcao invalida!\n");

Executado quando o usuário digita uma opção inexistente.

12. Liberação final da memória
liberarLista(lista);
liberarLista(lista1);
liberarLista(lista2);

Evita vazamento de memória.
