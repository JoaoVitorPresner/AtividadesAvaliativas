-CÓDIGO DO EXERCÍCIO 3

#include <stdio.h>

// Funcao recursiva para resolver as Torres de Hanoi
void torresDeHanoi(int discos, char origem, char destino, char auxiliar, int *movimentos) {

    // Caso base:
    // Se existir apenas 1 disco, move diretamente para o destino.
    if (discos == 1) {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        (*movimentos)++;
        return;
    }

    // Reducao do problema:
    // Move os discos menores para a torre auxiliar,
    // depois move o maior disco,
    // e por fim move novamente os discos menores para o destino.

    torresDeHanoi(discos - 1, origem, auxiliar, destino, movimentos);

    printf("Mover disco %d de %c para %c\n", discos, origem, destino);
    (*movimentos)++;

    torresDeHanoi(discos - 1, auxiliar, destino, origem, movimentos);
}

int main() {

    int discos;
    int movimentos = 0;

    printf("Digite a quantidade de discos: ");
    scanf("%d", &discos);

    printf("\nMovimentos realizados:\n\n");

    torresDeHanoi(discos, 'A', 'C', 'B', &movimentos);

    printf("\nTotal de movimentos: %d\n", movimentos);

    return 0;
}



