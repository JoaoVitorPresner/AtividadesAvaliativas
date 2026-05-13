Explicação Completa do Código
1. Bibliotecas utilizadas
#include <stdio.h>

A biblioteca stdio.h é utilizada para permitir:

entrada de dados com scanf();
saída de dados com printf().

Nenhuma biblioteca pronta para Fibonacci foi utilizada, respeitando as restrições da atividade.

2. Função Recursiva Fibonacci
long long fibonacci(int n, int *chamadas)

Essa função é responsável por:

calcular o valor do termo de Fibonacci;
contar quantas chamadas recursivas foram realizadas.
Parâmetros
int n
→ representa o termo da sequência que será calculado.
int *chamadas
→ ponteiro para a variável que armazena a quantidade de chamadas recursivas.

O uso do ponteiro permite modificar a variável diretamente sem utilizar variáveis globais, o que atende às exigências da atividade.

3. Contagem das chamadas recursivas
(*chamadas)++;

Cada vez que a função é executada, o contador é incrementado.

Isso serve para demonstrar o problema da recursão ingênua:
o programa recalcula os mesmos valores várias vezes.

Por exemplo:

Para calcular fibonacci(5):

calcula fibonacci(4) e fibonacci(3)
fibonacci(4) calcula novamente fibonacci(3) e fibonacci(2)
vários valores se repetem.

Isso aumenta drasticamente o número de chamadas.

4. Caso Base
if (n == 0)
    return 0;

if (n == 1)
    return 1;

O caso base é a condição que encerra a recursão.

Sem ele, a função chamaria a si mesma infinitamente.

Na sequência de Fibonacci:

F(0) = 0
F(1) = 1

Esses são os menores problemas possíveis e servem como base para os cálculos maiores.

A atividade exigia que o caso base estivesse claramente definido no código.

5. Redução do Problema
return fibonacci(n - 1, chamadas) + fibonacci(n - 2, chamadas);

Aqui acontece a recursão.

O problema é reduzido em partes menores:

para calcular F(n),
o programa calcula:
F(n-1)
F(n-2)

Isso segue diretamente a definição matemática da sequência de Fibonacci:

F(n)=F(n−1)+F(n−2)

A cada chamada:

o valor de n diminui;
o problema fica menor;
até chegar ao caso base.
6. Função Principal (main)
int main()

A função principal controla a execução do programa.

Entrada do usuário
printf("Digite o valor de n: ");
scanf("%d", &n);

O usuário informa qual termo da sequência deseja calcular.

Inicialização do contador
int chamadas = 0;

A variável começa em zero porque nenhuma chamada foi feita ainda.

Chamada da função recursiva
long long resultado = fibonacci(n, &chamadas);

Aqui:

a função recursiva é executada;
o resultado é armazenado;
o contador é atualizado.

O operador & envia o endereço da variável chamadas.

Exibição dos resultados
printf("\nFibonacci(%d) = %lld\n", n, resultado);
printf("Total de chamadas recursivas: %d\n", chamadas);

O programa mostra:

o valor calculado;
a quantidade total de chamadas recursivas.

Isso evidencia o custo computacional da abordagem ingênua.

7. Por que essa abordagem é considerada ingênua?

A solução é chamada de ingênua porque:

recalcula os mesmos valores muitas vezes;
não armazena resultados anteriores;
possui crescimento exponencial de chamadas.

Exemplo:

Para calcular F(6):

F(4) é calculado várias vezes;
F(3) também;
o número de chamadas cresce rapidamente.

Isso torna o algoritmo ineficiente para valores altos de n.

8. Complexidade
Complexidade de Tempo

A complexidade aproximada é:

O(2
n
)

Isso significa que o número de operações cresce exponencialmente.

Complexidade de Memória

A memória utilizada é proporcional à profundidade das chamadas recursivas:

O(n)

Porque cada chamada fica armazenada na pilha de execução até terminar.

9. Como o código atende às restrições da atividade
✔ Usa recursão no núcleo da solução

A decisão principal ocorre dentro da própria função recursiva.

✔ Não utiliza variáveis globais

O contador é passado por parâmetro usando ponteiro.

✔ Caso base está claro

Os casos n == 0 e n == 1 estão explícitos.

✔ Não usa bibliotecas prontas

Todo o cálculo foi implementado manualmente.

✔ Mostra a ineficiência da abordagem ingênua

A contagem de chamadas recursivas demonstra claramente o excesso de processamento.


