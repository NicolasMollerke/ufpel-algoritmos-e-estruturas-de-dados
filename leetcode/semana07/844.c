#include <stdbool.h>

typedef struct {
    int capacidade;
    int topo;
    char *itens;
} Pilha;

Pilha *criarPilha (int n) {
    Pilha *p =  (Pilha*) malloc(sizeof(Pilha));
    p->topo = -1;
    p->capacidade = n;
    p->itens = (char*) malloc(n * sizeof(char));

    return p;
}

bool vazia(Pilha *p) {
    if (p->topo == -1) {
        return true;
    }

    return false;
}

void push(Pilha *p, char c) {
    p->itens[++(p->topo)] = c;
}

char pop(Pilha *p) {
    if (vazia(p)) {
        return '\0';
    }
    
    return p->itens[(p->topo)--];
}

bool backspaceCompare(char* s, char* t) {
    Pilha *p1 = criarPilha(strlen(s));
    Pilha *p2 = criarPilha(strlen(t));
    int n;
    bool resul = true;

    for(int i=0; i < strlen(s); i++){
        if(s[i] != '#'){
            push(p1, s[i]);
        } else if (!vazia(p1)) {
            pop(p1);
        }
    }

    for(int i=0; i < strlen(t); i++){
        if(t[i] != '#'){
            push(p2, t[i]);
        } else if (!vazia(p2)) {
            pop(p2);
        }
    }
    
    if (p1->topo != p2->topo) {
        free(p1->itens);
        free(p1);
        free(p2->itens);
        free(p2);
        return false;
    }

    while(!vazia(p1)) {
        if (pop(p1) != pop(p2)) {
            resul = false;
            break;
        }
    }

    free(p1->itens);
    free(p1);
    free(p2->itens);
    free(p2);

    return resul;
}