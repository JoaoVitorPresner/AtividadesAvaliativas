Neste programa foi utilizada a técnica de memorização, uma estratégia usada para melhorar o desempenho de algoritmos recursivos.

A memoização funciona armazenando resultados que já foram calculados anteriormente, evitando que o programa repita os mesmos cálculos várias vezes. Isso torna a execução muito mais rápida e eficiente.

Para isso, foi utilizado um vetor dinâmico chamado memo, responsável por guardar os valores já calculados da sequência de Fibonacci.

Sempre que a função precisa calcular um valor, ela primeiro verifica se esse resultado já está armazenado no vetor:
if (memo[n] != -1)
Se o valor já existir, o programa simplesmente retorna esse resultado, sem precisar fazer novas chamadas recursivas.

Essa técnica reduz drasticamente a quantidade de chamadas da função, principalmente para valores maiores de n, onde a versão ingênua acaba repetindo muitos cálculos desnecessários.
Exemplo de saída
Digite um valor para n: 10

=== Resultado ===

Fibonacci ingenuo(10) = 55
Chamadas recursivas ingenuas: 177

Fibonacci com memoizacao(10) = 55
Chamadas recursivas com memoizacao: 19
Nesse exemplo, é possível perceber claramente a diferença de eficiência entre os dois métodos. Enquanto a versão ingênua realizou 177 chamadas recursivas, a versão com memoização precisou de apenas 19 chamadas para obter o mesmo resultado.
