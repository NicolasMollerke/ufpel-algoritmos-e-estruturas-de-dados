#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *itens;
    int capacidade;
    int atras;
    int frente;
    int total;
} Fila;

Fila *criarFila(int n) {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->itens = (int*) malloc(n * sizeof(int));
    f->capacidade = 0;
    f->frente = 0;
    f->atras = 0;
    f->total = 0;

    return f;
}

bool vazia(Fila *f) {
    if(f->total == 0){
        return true;
    }

    return false;
}

void inserir(Fila *f, int val) {
    if (f->total == f->capacidade) {
        return; //fila cheia
    }

    f->itens[f->atras] = val;

    f->atras = (f->atras + 1) % f->capacidade;
    f->total++;
}

int remover(Fila *f) {
    if (f->total == 0) {
        return -1;
    }

    int val = f->itens[f->frente];
    f->frente = (f->frente + 1) % f->capacidade;
    f->total--;
    return val;
}

int main() {
    Fila *f = criarFila(20);
}