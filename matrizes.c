#include <stdio.h>

#define MAX 10

void multiplicarMatrizes(int matrizA[MAX][MAX], int linA, int colA,
                         int matrizB[MAX][MAX], int linB, int colB,
                         int matrizMult[MAX][MAX]) {
    if (colA != linB) {
        printf("Multiplicação impossível: o número de colunas da matriz A deve ser igual ao número de linhas da matriz B.\n");
        return;
    }

    for (int i = 0; i < linA; i++)
        for (int j = 0; j < colB; j++) {
            matrizMult[i][j] = 0;
            for (int k = 0; k < colA; k++)
                matrizMult[i][j] += matrizA[i][k] * matrizB[k][j];
        }
}

int main() {
    int matrizA[MAX][MAX], matrizB[MAX][MAX], matrizMult[MAX][MAX];
    int linA, colA, linB, colB;

    printf("Digite o número de linhas e colunas da matriz A: ");
    scanf("%d %d", &linA, &colA);

    printf("Digite os valores da matriz A (%dx%d):\n", linA, colA);
    for (int i = 0; i < linA; i++)
        for (int j = 0; j < colA; j++)
            scanf("%d", &matrizA[i][j]);

    printf("Digite o número de linhas e colunas da matriz B: ");
    scanf("%d %d", &linB, &colB);

    printf("Digite os valores da matriz B (%dx%d):\n", linB, colB);
    for (int i = 0; i < linB; i++)
        for (int j = 0; j < colB; j++)
            scanf("%d", &matrizB[i][j]);

    multiplicarMatrizes(matrizA, linA, colA, matrizB, linB, colB, matrizMult);

    if (colA == linB) {
        printf("Matriz resultante da multiplicação:\n");
        for (int i = 0; i < linA; i++) {
            for (int j = 0; j < colB; j++)
                printf("%d ", matrizMult[i][j]);
            printf("\n");
        }
    }

    return 0;
}