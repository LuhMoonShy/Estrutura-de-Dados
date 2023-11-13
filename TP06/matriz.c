#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

Matriz inicializaMatriz(int nlin, int ncol) {
    Matriz mat;

    Celula* cabeca = (Celula*)malloc(sizeof(Celula));
    cabeca->linha = -1;
    cabeca->coluna = -1;
    cabeca->valor = 0.0;
    cabeca->direita = cabeca;
    cabeca->abaixo = cabeca;

    mat.cabeca = cabeca;
    mat.nlin = nlin;
    mat.ncol = ncol;

    return mat;
}

void insereElemento(Matriz* mat, int linha, int coluna, double valor) {
    if (linha < 1 || linha > mat->nlin || coluna < 1 || coluna > mat->ncol) {
        printf("Coordenadas inválidas.\n");
        return;
    }

    Celula* novaCelula = (Celula*)malloc(sizeof(Celula));
    novaCelula->linha = linha;
    novaCelula->coluna = coluna;
    novaCelula->valor = valor;

    Celula* anterior = mat->cabeca;
    while (anterior->direita != mat->cabeca && anterior->direita->coluna < coluna) {
        anterior = anterior->direita;
    }

    novaCelula->direita = anterior->direita;
    anterior->direita = novaCelula;

    anterior = mat->cabeca;
    while (anterior->abaixo != mat->cabeca && anterior->abaixo->linha < linha) {
        anterior = anterior->abaixo;
    }

    novaCelula->abaixo = anterior->abaixo;
    anterior->abaixo = novaCelula;
}

void imprimeMatriz(Matriz* mat) {
    printf("Matriz:\n");

    for (int i = 1; i <= mat->nlin; i++) {
        for (int j = 1; j <= mat->ncol; j++) {
            Celula* atual = mat->cabeca->abaixo;

            while (atual != mat->cabeca && atual->linha < i) {
                atual = atual->abaixo;
            }

            if (atual != mat->cabeca && atual->linha == i && atual->coluna == j) {
                printf("(%d, %d) = %.2f  ", i, j, atual->valor);
            } else {
                printf("(%d, %d) = 0.00  ", i, j);
            }
        }

        printf("\n");
    }
}

void liberaMatriz(Matriz* mat) {
    Celula* atual = mat->cabeca->abaixo;

    while (atual != mat->cabeca) {
        Celula* proximoLinha = atual->abaixo;
        Celula* proximoColuna = atual->direita;

        free(atual);
        atual = proximoLinha;

        // Evita loops infinitos se a matriz for irregular
        if (atual == proximoColuna) {
            break;
        }
    }

    free(mat->cabeca);
    mat->cabeca = NULL;
    mat->nlin = 0;
    mat->ncol = 0;
}

Matriz somaMatrizes(Matriz* matA, Matriz* matB) {
    Matriz resultado = inicializaMatriz(matA->nlin, matA->ncol);

    for (int i = 1; i <= matA->nlin; i++) {
        for (int j = 1; j <= matA->ncol; j++) {
            Celula* celulaA = matA->cabeca->abaixo;
            Celula* celulaB = matB->cabeca->abaixo;

            while (celulaA != matA->cabeca && (celulaA->linha < i || (celulaA->linha == i && celulaA->coluna < j))) {
                celulaA = celulaA->abaixo;
            }

            while (celulaB != matB->cabeca && (celulaB->linha < i || (celulaB->linha == i && celulaB->coluna < j))) {
                celulaB = celulaB->abaixo;
            }

            double valorA = (celulaA != matA->cabeca && celulaA->linha == i && celulaA->coluna == j) ? celulaA->valor : 0.0;
            double valorB = (celulaB != matB->cabeca && celulaB->linha == i && celulaB->coluna == j) ? celulaB->valor : 0.0;

            double soma = valorA + valorB;
            if (soma != 0.0) {
                insereElemento(&resultado, i, j, soma);
            }
        }
    }

    return resultado;
}

Matriz multiplicaMatrizes(Matriz* matA, Matriz* matB) {
    Matriz resultado = inicializaMatriz(matA->nlin, matB->ncol);

    for (int i = 1; i <= matA->nlin; i++) {
        for (int j = 1; j <= matB->ncol; j++) {
            double valor = 0.0;

            for (int k = 1; k <= matA->ncol; k++) {
                Celula* celulaA = matA->cabeca->abaixo;
                Celula* celulaB = matB->cabeca->abaixo;

                while (celulaA != matA->cabeca && (celulaA->linha < i || (celulaA->linha == i && celulaA->coluna < k))) {
                    celulaA = celulaA->abaixo;
                }

                while (celulaB != matB->cabeca && (celulaB->linha < k || (celulaB->linha == k && celulaB->coluna < j))) {
                    celulaB = celulaB->abaixo;
                }

                double valorA = (celulaA != matA->cabeca && celulaA->linha == i && celulaA->coluna == k) ? celulaA->valor : 0.0;
                double valorB = (celulaB != matB->cabeca && celulaB->linha == k && celulaB->coluna == j) ? celulaB->valor : 0.0;

                valor += valorA * valorB;
            }

            if (valor != 0.0) {
                insereElemento(&resultado, i, j, valor);
            }
        }
    }

    return resultado;
}
