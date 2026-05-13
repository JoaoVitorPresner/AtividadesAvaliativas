1-Faça um programa que lê três palavras do teclado e imprime as três palavras na ordem inversa.
-Código:
#include <stdio.h>
int main() {
    char p1[20], p2[20], p3[20];

    printf("Digite 3 palavras:\n");
    scanf("%s %s %s", p1, p2, p3);

    printf("Ordem inversa: %s %s %s\n", p3, p2, p1);
    return 0;
} 
-Explicação: Aqui eu não precisei usar laço, porque são só três palavras. Eu apenas li e inverti manualmente na saída. 
char p1, p2, p3 → guarda as palavras
scanf → lê do teclado
printf → imprime invertido



2-Faça um programa que cria um vetor com 5 elementos inteiros, lê 5 números do teclado, armazena os números no vetor e imprime o vetor na ordem inversa. 
-Código:
#include <stdio.h>
int main() {
    int v[5];

    printf("Digite 5 numeros:\n");

    for(int i = 0; i < 5; i++) {
        scanf("%d", &v[i]);
    }

    printf("Ordem inversa:\n");

    for(int i = 4; i >= 0; i--) {
        printf("%d ", v[i]);
    }

    return 0;
}
-Explicação: Esse programa lê 5 números e mostra eles ao contrário.
Aqui eu usei um laço for para ler os valores e outro para inverter a ordem, começando do último índice.



3-Faça um programa que lê uma matriz de 3 x 3 elementos usando um comando for, multiplica cada elemento por 5 e imprime o resultado.
-Código:
#include <stdio.h>
int main() {
    int m[3][3];

    printf("Digite os valores da matriz 3x3:\n");

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    printf("Matriz multiplicada por 5:\n");

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", m[i][j] * 5);
        }
        printf("\n");
    }

    return 0;
}
-Explicação: Esse programa lê uma matriz 3x3 e multiplica todos os valores por 5. 
Usei dois laços for porque matriz tem linha e coluna. Cada posição é acessada por dois índices. 



4-Faça um programa que imprime a matriz identidade de uma dada matriz 3 x 3. Implemente a multiplicação da matriz original pela matriz identidade, provando que se trata realmente da matriz identidade.
-Código:
#include <stdio.h>
int main() {
    int A[3][3], I[3][3], R[3][3];

    printf("Digite a matriz 3x3:\n");

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &A[i][j]);
        }
    }

 for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }

  for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            R[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                R[i][j] += A[i][k] * I[k][j];
            }
        }
    }

    printf("\nResultado da multiplicacao (A * I):\n");

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    return 0;
}
-Explicação: Esse programa cria uma matriz identidade e prova que ao multiplicar por ela, a matriz original não muda. A matriz identidade funciona como o número 1 na multiplicação. 
Quando multiplicamos qualquer matriz por ela, o resultado é a própria matriz.



