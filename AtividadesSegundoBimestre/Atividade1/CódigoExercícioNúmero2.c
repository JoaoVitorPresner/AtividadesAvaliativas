#include <stdio.h>
#include <stdlib.h>

int chamadasIngenua = 0;
int chamadasMemo = 0;

// Fibonacci sem otimização
int fibonacciIngenuo(int n) {
    chamadasIngenua++;

    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacciIngenuo(n - 1) + fibonacciIngenuo(n - 2);
}

// Fibonacci com memoização
int fibonacciMemo(int n, int *memo) {
    chamadasMemo++;

    if (memo[n] != -1)
        return memo[n];

    if (n == 0)
        memo[n] = 0;
    else if (n == 1)
        memo[n] = 1;
    else
        memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);

    return memo[n];
}

int main() {
    int n;

    printf("Digite um valor para n: ");
    scanf("%d", &n);

    // Parte ingênua
    int resultadoIngenuo = fibonacciIngenuo(n);

    // Alocação dinâmica do vetor memo
    int *memo = (int *) malloc((n + 1) * sizeof(int));

    // Inicializa vetor com -1
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    // Parte otimizada
    int resultadoMemo = fibonacciMemo(n, memo);

    printf("\n=== Resultado ===\n");

    printf("Fibonacci ingenuo(%d) = %d\n", n, resultadoIngenuo);
    printf("Chamadas recursivas ingenuas: %d\n\n", chamadasIngenua);

    printf("Fibonacci com memoizacao(%d) = %d\n", n, resultadoMemo);
    printf("Chamadas recursivas com memoizacao: %d\n", chamadasMemo);

    free(memo);

    return 0;
}

