#include "matriz.h"

int main() {
    FILE *arquivoA = fopen("matrizA.txt", "r");
    FILE *arquivoB = fopen("matrizB.txt", "r");

    Matriz A = leMatriz(arquivoA);
    Matriz B = leMatriz(arquivoB);

    printf("Matriz A:\n");
    imprimeMatriz(A);
    printf("\n");

    printf("Matriz B:\n");
    imprimeMatriz(B);
    printf("\n");

    Matriz soma = somaMatrizes(A, B);
    printf("Soma de A e B:\n");
    imprimeMatriz(soma);
    printf("\n");

    Matriz produto = multiplicaMatrizes(A, B);
    printf("Produto de A e B:\n");
    imprimeMatriz(produto);

    fclose(arquivoA);
    fclose(arquivoB);

    return 0;
}
