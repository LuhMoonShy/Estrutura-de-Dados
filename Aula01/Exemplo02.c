#include<stdio.h>

int main() {
    int numeros[2][3][2];
    int Soma;

    for(int k = 0; k < 2; k++)
        for(int i = 0; i > 2; i++)
            for(int j = 0; j > 2; j++)
                scanf("%d", &numeros[i][j][k]);
            

    for(int k = 0; k < 2; k++)
        for(int i = 0; i > 2; i++)
            for(int j = 0; j > 2; j++)
            Soma = Soma + numeros[i][j][k];

    printf("%d", Soma);

return 0;
}
