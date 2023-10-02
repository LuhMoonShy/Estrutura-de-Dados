#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[] = "tags.html";
    char outputFileName[] = "output.txt"; 
    char ch, prevCh;

    inputFile = fopen(inputFileName, "r");

    if (inputFile == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    outputFile = fopen(outputFileName, "w");

    if (outputFile == NULL) {
        perror("Erro ao criar o arquivo de saida");
        fclose(inputFile);
        return 1;
    }

    int insideTag = 0;

    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch == '<') {
            insideTag = 1;
        }
        else if (ch == '>') {
            insideTag = 0;
        }
        else if (!insideTag) {
            fputc(ch, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Tags HTML removidas. O resultado foi salvo em %s.\n", outputFileName);

    return 0;
}
