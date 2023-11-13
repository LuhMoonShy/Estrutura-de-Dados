#include "matriz.h"
#include <stdio.h>

int main() {
    Matriz matA = inicializaMatriz(4, 4);
    Matriz matB = inicializaMatriz(4, 4);

    insereElemento(&matA, 1, 1, 50.0);
    insereElemento(&matA, 2, 1, 10.0);
    insereElemento(&matA, 2, 3, 20.0);
    insereElemento(&matA, 4, 1, -30.0);
    insereElemento(&matA, 4, 3, -60.0);
    insereElemento(&matA, 4, 4, -5.0);

    insereElemento(&matB, 1, 1, 50.0);
    insereElemento(&matB, 2, 1, 10.0);
    insereElemento(&matB, 2, 3, 20.0);
    insereElemento(&matB, 4, 1, -30.0);
    insereElemento(&matB, 4, 3, -60.0);
    insereElemento(&matB, 4, 4, -5.0);

    printf("Matriz A:\n");
    imprimeMatriz(&matA);

    printf("\nMatriz B:\n");
    imprimeMatriz(&matB);

    Matriz matSoma = somaMatrizes(&matA, &matB);
    printf("\nSoma de A e B:\n");
    imprimeMatriz(&matSoma);

    Matriz matProduto = multiplicaMatrizes(&matA, &matB);
    printf("\nProduto de A e B:\n");
    imprimeMatriz(&matProduto);

    liberaMatriz(&matA);
    liberaMatriz(&matB);
    liberaMatriz(&matSoma);
    liberaMatriz(&matProduto);

    return 0;
}
