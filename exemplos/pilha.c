#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int topo;
    int capacidade;
    int *itens;
} Pilha;

Pilha *criarPilha (int n) {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->itens = malloc(n * sizeof(int));
    p->topo = -1;
    p->capacidade = n;

    return p;
}

bool vazia (Pilha *p) {
    if (p->topo == -1){
        return true;
    }

    return false;
}

void push (Pilha *p, int val){
    p->itens[++(p->topo)] = val;
}

int pop (Pilha *p) {
    if (vazia(p)) {
        return '\0';
    }

    return p->itens[(p->topo)--];
}

void liberarPilha(Pilha *p) {
    free(p->itens);
    free(p);
}

int main() {
    Pilha *p = criarPilha(10);
}