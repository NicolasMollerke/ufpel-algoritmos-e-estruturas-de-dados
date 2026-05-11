#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int topo;
    int capacidade;
    int *itens;
} Pilha;

Pilha *criarPilha(int n) {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p->topo = -1;
    p->capacidade = n;
    p->itens = (int *) malloc(n *sizeof(int));

    return p;
}

bool vazia(Pilha *p) {
    if(p->topo == -1){
        return true;
    }
    return false;
}

void push(Pilha *p, int c) {
    p->itens[++(p->topo)] = c;
}

int pop (Pilha *p){
    if (vazia(p)) {
        return '\0';
    }

    return p->itens[(p->topo)--];
}

int calPoints(char** operations, int operationsSize) {
    Pilha *p = criarPilha(operationsSize);
    
    for (int i=0; i < operationsSize; i++) {
        char *op = operations[i];
        int ant = p->topo - 1;
        
        if(strcmp(op, "C") == 0){
            pop(p);
        } else if (strcmp(op, "D") == 0){
            int val = p->itens[p->topo];
            push(p, val*2);
        } else if (strcmp(op, "+") == 0) {
            int val1 = p->itens[p->topo];
            int val2 = p->itens[p->topo - 1];

            push(p, val1 + val2);
        } else {
            int val = atoi(op);
            push(p, val);
        }
    }

    int total = 0;
    
    for (int i=0; i <= p->topo; i++) {
        
        total += p->itens[i];
    }

    return total;
}