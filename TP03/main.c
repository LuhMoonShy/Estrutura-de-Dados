#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float X;
    float Y;
} Ponto;

float calcularArea(Ponto vertices[], int numVertices) {
    float area = 0.0;

    for (int i = 0; i < numVertices; i++) {
        int j = (i + 1) % numVertices;
        area += (vertices[i].X * vertices[j].Y) - (vertices[j].X * vertices[i].Y);
    }

    area = 0.5 * abs(area);
    return area;
}

int main() {
    FILE *arquivo;
    int numVertices;

    arquivo = fopen("vertices.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fscanf(arquivo, "%d", &numVertices);

    Ponto *vertices = (Ponto *)malloc(sizeof(Ponto) * numVertices);

    if (vertices == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < numVertices; i++) {
        fscanf(arquivo, "%f %f", &(vertices[i].X), &(vertices[i].Y));
    }

    fclose(arquivo);

    float area = calcularArea(vertices, numVertices);

    printf("A area do poligono e de %.2f\n.", area);

    free(vertices);

    return 0;
}
