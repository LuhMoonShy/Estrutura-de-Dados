#include "matriz.h"
#include <stdlib.h>

Matriz inicializaMatriz(int nlin, int ncol) {
    Matriz mat;
    mat.nlin = nlin;
    mat.ncol = ncol;
    mat.cabeca = malloc(sizeof(Celula));
    mat.cabeca->direita = mat.cabeca;
    mat.cabeca->abaixo = mat.cabeca;
    mat.cabeca->linha = -1;
    mat.cabeca->coluna = -1;
    mat.cabeca->valor = 0.0;

    return mat;
}

void insere(Matriz *mat, int linha, int coluna, float valor) {
    Celula *nova = malloc(sizeof(Celula));
    nova->linha = linha;
    nova->coluna = coluna;
    nova->valor = valor;

    Celula *atual = mat->cabeca;
    while (atual->abaixo != mat->cabeca && atual->abaixo->linha < linha) {
        atual = atual->abaixo;
    }

    while (atual->direita != mat->cabeca && atual->direita->coluna < coluna) {
        atual = atual->direita;
    }

    nova->abaixo = atual->abaixo;
    atual->abaixo = nova;

    nova->direita = atual->direita;
    atual->direita = nova;
}

void imprimeMatriz(Matriz A) {
    for (int i = 1; i <= A.nlin; i++) {
        for (int j = 1; j <= A.ncol; j++) {
            float valor = obtemValor(A, i, j);
            printf("(%.2f)  ", valor);
        }
        printf("\n");
    }
}

Matriz leMatriz(FILE *arquivo) {
    int m, n;
    fscanf(arquivo, "%d, %d", &m, &n);

    Matriz mat = inicializaMatriz(m, n);

    int linha, coluna;
    float valor;

    while (fscanf(arquivo, "%d, %d, %f", &linha, &coluna, &valor) == 3) {
        insere(&mat, linha, coluna, valor);
    }

    return mat;
}

float obtemValor(Matriz A, int linha, int coluna) {
    Celula *atual = A.cabeca->abaixo;
    while (atual != A.cabeca && atual->linha < linha) {
        atual = atual->abaixo;
    }

    while (atual != A.cabeca && atual->coluna < coluna) {
        atual = atual->direita;
    }

    if (atual != A.cabeca && atual->linha == linha && atual->coluna == coluna) {
        return atual->valor;
    } else {
        return 0.0;
    }
}

Matriz somaMatrizes(Matriz A, Matriz B) {
    Matriz C = inicializaMatriz(A.nlin, A.ncol);

    for (int i = 1; i <= A.nlin; i++) {
        for (int j = 1; j <= A.ncol; j++) {
            float valorA = obtemValor(A, i, j);
            float valorB = obtemValor(B, i, j);
            insere(&C, i, j, valorA + valorB);
        }
    }

    return C;
}

Matriz multiplicaMatrizes(Matriz A, Matriz B) {
    Matriz C = inicializaMatriz(A.nlin, B.ncol);

    for (int i = 1; i <= A.nlin; i++) {
        for (int j = 1; j <= B.ncol; j++) {
            float soma = 0.0;
            for (int k = 1; k <= A.ncol; k++) {
                soma += obtemValor(A, i, k) * obtemValor(B, k, j);
            }
            insere(&C, i, j, soma);
        }
    }

    return C;
}
