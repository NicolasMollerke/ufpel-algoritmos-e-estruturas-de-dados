#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int topo;
    int capacidade;
    char *itens;
} Pilha;

Pilha* criarPilha(int n) {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->capacidade = n;
    p->topo = -1;
    p->itens = (char*) malloc(n*sizeof(char));
    return p;
}

bool vazia(Pilha *p) {
    if(p->topo == -1){
        return true;
    } else {
        return false;
    }
}

void push(Pilha *p, char c){
    /*
    p->topo++;
    p->itens[pilha->topo];
    */
    p->itens[++(p->topo)] = c;
}

char pop(Pilha *p){
    if (vazia(p)) {
        return '\0'; 
    }
    return p->itens[(p->topo)--];
}

void liberarPilha(Pilha *p) {
    free(p->itens);
    free(p);
}

bool isValid(char* s) {
    Pilha *p = criarPilha(strlen(s));
    
    for (int i=0; s[i] != '\0'; i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '[' ){
            push(p, s[i]);
        } else {
            if (vazia(p)) {
                return false; 
            }
            
            char top = pop(p);
        
            if (s[i] == ')' && top != '(') return false;
            if (s[i] == ']' && top != '[') return false;
            if (s[i] == '}' && top != '{') return false;
        }
    }

    bool resul = vazia(p);

    liberarPilha(p);

    return resul;
}