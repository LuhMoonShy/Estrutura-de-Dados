#ifndef MATRIZ_H
#define MATRIZ_H

#include <math.h>

typedef struct Celula {
    int linha;
    int coluna;
    double valor;
    struct Celula* direita;
    struct Celula* abaixo;
} Celula;

typedef struct {
    Celula* cabeca;
    int nlin;
    int ncol;
} Matriz;

Matriz inicializaMatriz(int nlin, int ncol);
void insereElemento(Matriz* mat, int linha, int coluna, double valor);
void imprimeMatriz(Matriz* mat);
void liberaMatriz(Matriz* mat);
Matriz somaMatrizes(Matriz* matA, Matriz* matB);
Matriz multiplicaMatrizes(Matriz* matA, Matriz* matB);

#endif
