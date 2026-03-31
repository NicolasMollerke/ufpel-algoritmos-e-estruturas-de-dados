#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int menu();
void adicionarNome(char *nomes);
void removerNome(char *nomes);
void listarNomes(char *nomes);

int main(){
    char *nomes;
    int escolha;

    for (;;){
        escolha = menu();
        switch (escolha){
        case 1:
            adicionarNome(nomes);
            break;
        case 2:
            removerNome(nomes);
            break;
        case 3:
            listarNomes(nomes);
            break;
        case 4:
            break;
        }
    }
    return 0;
}

int menu(){
    int e;
    
    printf("1. Adicionar nome \n");
    printf("2. Remover nome \n");
    printf("3. Listar \n");
    printf("4. Sair \n");
    scanf("%d", &e);

    return e;
}

void adicionarNome(char *nomes){
}

void removerNome(char *nomes){

}

void listarNomes(char *nomes){

}
