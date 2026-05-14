typedef struct {
    int topo;
    int topoMenores;
    int capacidade;
    int *itens;
    int *menores;
} MinStack;


MinStack* minStackCreate() {
    MinStack *obj = (MinStack *) malloc(sizeof(MinStack));

    obj->capacidade = 30000;

    obj->itens = (int *) malloc(obj->capacidade *sizeof(int));
    obj->menores = (int *) malloc(obj->capacidade *sizeof(int));

    obj->topo = -1;
    obj->topoMenores = -1;

    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->itens[++(obj->topo)] = val;
    
    if (obj->topoMenores == -1 || val <= obj->menores[obj->topoMenores]) {
        obj->menores[++(obj->topoMenores)] = val;
    }
}

void minStackPop(MinStack* obj) {
    int val = obj->itens[obj->topo];
    obj->itens[(obj->topo)--];

    if ( val == obj->menores[obj->topoMenores]) {
        obj->menores[(obj->topoMenores)--];
    }
}

int minStackTop(MinStack* obj) {
    return obj->itens[obj->topo];
}

int minStackGetMin(MinStack* obj) {
    return obj->menores[obj->topoMenores];
}

void minStackFree(MinStack* obj) {
    free(obj->itens);
    free(obj->menores);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/