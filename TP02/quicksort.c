#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

char *median(char *arr[], int left, int right) {
    int mid = left + (right - left) / 2;
    if (strcmp(arr[left], arr[mid]) > 0) {
        swap(&arr[left], &arr[mid]);
    }
    if (strcmp(arr[left], arr[right]) > 0) {
        swap(&arr[left], &arr[right]);
    }
    if (strcmp(arr[mid], arr[right]) > 0) {
        swap(&arr[mid], &arr[right]);
    }
    return arr[mid];
}

void quicksort(char *arr[], int left, int right, int *comparisons, int *swaps) {
    if (left < right) {
        char *pivot = median(arr, left, right);
        int i = left;
        int j = right;
        while (i <= j) {
            while (strcmp(arr[i], pivot) < 0) {
                (*comparisons)++;
                i++;
            }
            while (strcmp(arr[j], pivot) > 0) {
                (*comparisons)++;
                j--;
            }
            if (i <= j) {
                (*swaps)++;
                swap(&arr[i], &arr[j]);
                i++;
                j--;
            }
        }
        quicksort(arr, left, j, comparisons, swaps);
        quicksort(arr, i, right, comparisons, swaps);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga",
        "abacate", "kiwi", "cereja", "morango", "pessego", "goiaba", "melancia",
        "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int comparisons = 0;
    int swaps = 0;

    quicksort(arr, 0, 19, &comparisons, &swaps);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < 20; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    FILE *outputFile = fopen("saida.txt", "w");
    if (outputFile == NULL) {
        perror("Erro ao criar arquivo de saida");
        return 1;
    }
    for (int i = 0; i < 20; i++) {
        fprintf(outputFile, "%s\n", arr[i]);
    }
    fclose(outputFile);

    printf("Numero de comparacoes: %d\n", comparisons);
    printf("Numero de trocas: %d\n", swaps);

    printf("Mediana: %s\n", arr[10]); 

    return 0;
}
