1. Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
stdio.h

Biblioteca usada para:

printf() → mostrar mensagens na tela
scanf() → ler dados do teclado
stdlib.h

Biblioteca usada para:

malloc() → alocar memória dinamicamente
free() → liberar memória
exit() → encerrar o programa em caso de erro
2. Estrutura do nó da lista
typedef struct NoSimples {
    int valor;
    struct NoSimples *prox;
} NoSimples;

Aqui é criada a estrutura principal da lista encadeada.

O que existe dentro do nó?

Cada nó possui:

Campo	Função
valor	Armazena o número inteiro
prox	Guarda o endereço do próximo nó
Funcionamento visual

Se a lista possuir:

10 -> 20 -> 30

Na memória fica parecido com:

[10 | * ] -> [20 | * ] -> [30 | NULL]

O último nó aponta para NULL, indicando o fim da lista.

3. Função criarNo()
NoSimples* criarNo(int valor)

Essa função cria um novo nó dinamicamente.

Passo 1 — Alocação de memória
NoSimples *novo =
    (NoSimples*) malloc(sizeof(NoSimples));
O que acontece aqui?
malloc() reserva memória na RAM
sizeof(NoSimples) pega o tamanho da estrutura
O retorno é um ponteiro para o espaço criado
Passo 2 — Verificar erro de memória
if (novo == NULL)

Se malloc() falhar:

não existe memória disponível
o ponteiro será NULL

Então o programa:

printf("Erro de alocacao!\n");
exit(1);

encerra imediatamente.

Passo 3 — Inicializar os dados
novo->valor = valor;
novo->prox = NULL;
Significado
guarda o valor recebido
define que inicialmente o nó não aponta para ninguém
Passo 4 — Retornar o nó
return novo;

A função devolve o endereço do novo nó criado.

4. Função inserirFinal()
void inserirFinal(NoSimples **head, int valor)

Essa função insere um novo elemento no final da lista.

Entendendo o parâmetro **head
Por que ponteiro duplo?
NoSimples **head

O head é o ponteiro que guarda o início da lista.

Como a função pode alterar esse ponteiro, precisamos passar:

endereço do ponteiro

Por isso usamos:

NoSimples **
Passo 1 — Criar novo nó
NoSimples *novo = criarNo(valor);

A função reaproveita a função anterior.

Passo 2 — Verificar lista vazia
if (*head == NULL)

Se a lista estiver vazia:

*head = novo;

O novo nó se torna o primeiro da lista.

Passo 3 — Percorrer a lista
NoSimples *temp = *head;

while (temp->prox != NULL) {
    temp = temp->prox;
}
Objetivo

Encontrar o último nó.

Funcionamento

Enquanto existir próximo nó:

temp = temp->prox;

o ponteiro avança.

Passo 4 — Inserir no final
temp->prox = novo;

O último nó passa a apontar para o novo.

Exemplo visual

Antes:

10 -> 20 -> NULL

Inserindo 30:

10 -> 20 -> 30 -> NULL
5. Função exibirLista()
void exibirLista(NoSimples *head)

Mostra todos os elementos da lista.

Passo 1 — Verificar lista vazia
if (head == NULL)

Se estiver vazia:

printf("Lista vazia!\n");
Passo 2 — Percorrer a lista
while (head != NULL)

Enquanto existir nó:

printf("%d -> ", head->valor);
head = head->prox;

Mostra o valor atual e avança.

Exemplo

Saída:

10 -> 20 -> 30 -> NULL
6. Função inverterLista()
void inverterLista(NoSimples **head)

Essa é a parte mais importante do código.

Ela inverte completamente a direção da lista.

Ideia principal

Transformar:

10 -> 20 -> 30 -> NULL

em:

30 -> 20 -> 10 -> NULL
Variáveis usadas
NoSimples *anterior = NULL;
NoSimples *atual = *head;
NoSimples *proximo = NULL;
Variável	Função
anterior	Nó anterior
atual	Nó atual
proximo	Guarda o próximo nó
Funcionamento do algoritmo
Antes da inversão
NULL <- 10 -> 20 -> 30
         ^
       atual
Passo 1 — Guardar próximo nó
proximo = atual->prox;

Evita perder o restante da lista.

Passo 2 — Inverter ponteiro
atual->prox = anterior;

O nó atual passa a apontar para trás.

Passo 3 — Avançar ponteiros
anterior = atual;
atual = proximo;

Os ponteiros avançam.

Processo visual
Iteração 1
10 -> NULL
20 -> 30
Iteração 2
20 -> 10 -> NULL
30
Iteração 3
30 -> 20 -> 10 -> NULL
Finalização
*head = anterior;

O início da lista agora é o último nó antigo.

7. Função liberarLista()
void liberarLista(NoSimples *head)

Responsável por liberar toda memória alocada.

Por que isso é importante?

Como usamos malloc(), a memória fica ocupada até ser liberada manualmente.

Sem free(), ocorre:

Vazamento de memória (Memory Leak)
Funcionamento
while (head != NULL)

Percorre toda a lista.

Guardar nó atual
temp = head;
Avançar lista
head = head->prox;
Liberar memória
free(temp);

Apaga o nó da RAM.

8. Função main()

É o ponto inicial do programa.

Criação da lista
NoSimples *lista = NULL;

Inicialmente a lista está vazia.

Variáveis do menu
int opcao;
int valor;
opcao → escolha do usuário
valor → número digitado
Estrutura principal do menu
do {
    ...
} while (opcao != 0);

Repete até o usuário escolher sair.

Menu exibido
printf("\n=========== MENU ===========\n");

Mostra as opções disponíveis.

Leitura da opção
scanf("%d", &opcao);

Lê o número digitado.

Estrutura switch
switch(opcao)

Executa ações diferentes conforme a escolha.

Caso 1 — Inserir valor
inserirFinal(&lista, valor);

Adiciona elemento no final.

Caso 2 — Exibir lista
exibirLista(lista);

Mostra os elementos.

Caso 3 — Inverter lista
inverterLista(&lista);

Inverte os ponteiros.

Caso 0 — Encerrar
printf("Encerrando programa...\n");

Sai do menu.

Caso inválido
default:
    printf("Opcao invalida!\n");

Trata entradas incorretas.

Finalização do programa
liberarLista(lista);

Libera toda memória antes de encerrar.
