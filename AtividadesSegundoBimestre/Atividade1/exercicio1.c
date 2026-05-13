#include <stdio.h>

// Função recursiva para calcular Fibonacci
// Caso base: quando n é 0 ou 1, retorna o próprio valor.
// Redução do problema: fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)
long long fibonacci(int n, int *chamadas) {
    (*chamadas)++; // Conta cada chamada recursiva

    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacci(n - 1, chamadas) + fibonacci(n - 2, chamadas);
}

int main() {
    int n;
    int chamadas = 0;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    long long resultado = fibonacci(n, &chamadas);

    printf("\nFibonacci(%d) = %lld\n", n, resultado);
    printf("Total de chamadas recursivas: %d\n", chamadas);

    return 0;
}
