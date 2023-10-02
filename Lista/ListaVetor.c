#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int chave;
    //poderiam ser inseridos outros campos (nome, telefone, etc)
} Item;

typedef struct{
    Item *array;
    int Tamanho; //número de itens inseridos na lista
    int Capacidade; //número ma´ximo de itens que a lista suporta
} Lista;

Lista* criarLista(int Capacidade){
    Lista *X = (Lista*) malloc(sizeof(Lista));
    if(X == NULL){
        perror("Erro ao alocar memória para a lista...");
        exit(1);
    }
    X->array = (Item *) malloc(Capacidade * sizeof(Item));
    if(X->array == NULL){
        perror("Erro ao alocar memória para os itens da lista...");
        free(X);
        exit(1);
    }
    X->Capacidade = Capacidade;
    X->Tamanho = 0;


    return X;
}

void inserirElemento(Lista *X, Item Elemento){

    if(X->Tamanho >= X->Capacidade){
        printf("Erro : a lista esta cheia...");
        return;
    }
    X->array[X->Tamanho] = Elemento;
    X->Tamanho++;
}

void removerElemento(Lista* X, int indice){
    if(indice < 0 || indice > X->Tamanho){
        printf("Erro : indice fora dos limites...");
        return;
    }
    for (int i = indice; i < X->Tamanho; i++) X->array[i] = X->array[i+1];
    X->Tamanho --;
}

void imprimirLista(Lista* X){
    for (int i = 0; i < X->Tamanho; i++) printf("Elementos da lista: %d. \n", X->array[i]);
}

Item* localizarElemento(Lista* X, int indice){
    if(indice < 0 || indice > X->Tamanho){
        printf("Erro : indice fora dos limites...");
        return NULL;
    }
    return (&X->array[indice]);
}

int main(){
     
    int capacidade = 10;
    Lista* lista = criarLista(capacidade);

    Item elemento1 = {1};
    Item elemento2 = {2};
    Item elemento3 = {3};
    Item elemento4 = {4};
    inserirElemento(lista,elemento1);
    inserirElemento(lista,elemento2);
    inserirElemento(lista,elemento3);
    inserirElemento(lista,elemento4);
    inserirElemento(lista,(Item){5});

    imprimirLista(lista);

    printf("Tamanho : %d. \n", lista->Tamanho);

    printf("Memoria alocada : %d. \n", sizeof(lista));

    printf("Primeiro item da lista : %d. \n", lista->array[0]);

    removerElemento(lista,3);

    imprimirLista(lista);

    printf("Tamanho : %d. \n", lista->Tamanho);

    Item *elementoLocalizado = localizarElemento(lista, 2);
    printf("Localizando elemento : %d. \n", elementoLocalizado->chave);

    free(lista->array);
    free(lista);

    return 0;
}