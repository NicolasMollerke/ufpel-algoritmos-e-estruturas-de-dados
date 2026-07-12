/*Implemente uma Celula simplesmente encadeada com estruturas auto referenciadas e
ponteiros. Inclua as funções de pesquisa, impressão, adição e remoção por
ponteiros. Utilize alocação dinâmica.
*/

#include <stdio.h>
#include<stdlib.h>

typedef struct cel {
    int numero;
    struct cel *prox;
} Celula;


Celula *cria(void);
void inserir_numero(Celula *ini, int x);
void inserir_numerofim(Celula *ini, int x);
void listar_numeros(Celula *ini);
void liberar(Celula *ini, int x);

int main() {
    Celula *ini;
    int escolha;

    ini = cria();
    
    for (int i=0; i < 10; i++){
        inserir_numero(ini, i);
    }

    for (int i=10; i < 20; i++){
        inserir_numerofim(ini, i);
    }

    listar_numeros(ini);

    liberar(ini, 5);
}

Celula *cria(void) {
    Celula *start;

    start = (Celula *) malloc(sizeof(Celula));
    start->prox = NULL;
    return start;
}

void inserir_numero(Celula *ini, int x){
    Celula *nova;

    nova = (Celula *) malloc(sizeof(Celula)); //reserva memoria para o item novo 

    nova->numero = x;

    nova->prox = ini->prox;
    ini->prox = nova;
}

void inserir_numerofim(Celula *ini, int x){
    Celula *nova, *atual;

    nova = (Celula *) malloc(sizeof(Celula));
    nova->prox = NULL; //nova se tornar o ultimo item
    nova->numero = x;

    atual = ini;

    while(atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = nova;

    /*sem While ini -> A -> B -> C -> NULL
    nova -> NULL  (← isolado, não conectado!)*/

    //com while ini -> A -> B -> C -> nova -> NULL
}

void listar_numeros(Celula *ini){
    Celula *atual;
    int cont=0;

    atual = ini->prox;

    while (atual != NULL){
        printf("%d\n", atual->numero);
        cont++;

        atual = atual->prox;
    }

    printf("Numero de elemntos: %d\n", cont);
}

void liberar(Celula *ini, int x){
    Celula *atual = ini->prox, *anterior=ini;
    Celula *liberado;

    while (atual != NULL){
        
        if (atual->numero == x){
            liberado = atual;
            
            anterior->prox = atual->prox;
            atual = atual->prox;

            printf("Liberado o item %d na posição %000000X\n", liberado->numero, liberado);
            free(liberado);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }

    listar_numeros(ini);
}

