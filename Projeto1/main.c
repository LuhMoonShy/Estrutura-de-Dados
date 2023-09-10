#include <stdio.h>
#include <stdlib.h>

int main() {
    // Abre o arquivo de entrada para leitura
    FILE *entrada = fopen("DadosEntrada.csv", "r");
    if (entrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    // Abre o arquivo de saída para escrita
    FILE *saida = fopen("SituacaoFinal.csv", "w");
    if (saida == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        fclose(entrada);
        return 1;
    }

    // Lê e processa os dados dos alunos
    char linha[1000];
    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        char nome[100], telefone[100], curso[100];
        float nota1, nota2;

        // Lê os dados de cada linha do arquivo
        sscanf(linha, "%[^,],%[^,],%[^,],%f,%f", nome, telefone, curso, &nota1, &nota2);

        // Calcula a média das notas
        float media = (nota1 + nota2) / 2.0;

        // Determina a situação do aluno
        const char *situacao = (media >= 7.0) ? "APROVADO" : "REPROVADO";

        // Escreve os dados no arquivo de saída
        fprintf(saida, "%s, %.2f, %s\n", nome, media, situacao);
    }

    // Fecha os arquivos
    fclose(entrada);
    fclose(saida);

    printf("Processamento concluido. Os resultados foram salvos em SituacaoFinal.csv.\n");

    return 0;
}
