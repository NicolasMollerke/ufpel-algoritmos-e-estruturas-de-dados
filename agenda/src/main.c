#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu ( void *pBuffer );
void *adicionarPessoa ( void *pBuffer );
void buscarPessoa ( void *pBuffer );
void listarPessoa( void *pBuffer );

int main() {
    void *pBuffer;

    pBuffer = malloc(5*sizeof(int)); //aloca para a escolha no menu, contador de pessoas, tamannho da memoria
    pBuffer = realloc(pBuffer, (5*sizeof(int)) + (50*sizeof(char))); //epaço rascunho para as infromações
    *(int *)(pBuffer + sizeof(int)) = 0; //contador de pessoas = 0
    *(int *)(pBuffer + 2*sizeof(int)) = ((5 * sizeof(int))+ (50 * sizeof(char))); //tamanho da memoria = bytes dos int + bytes do char
    *(int *)(pBuffer + 3*sizeof(int)) = 0; //variavel que vai ser usada para o loop, indica o espaço de memoria de cada info
    *(int *)(pBuffer + 4*sizeof(int)) = 0; //variavel que vai ser usada para o loop,


    for ( ;; ) {
        menu( pBuffer );
        switch ( *(int *)pBuffer ) {
        case 1:
            pBuffer = adicionarPessoa( pBuffer );
            break;
        case 3:
            buscarPessoa( pBuffer );
            break;
        case 4:
            listarPessoa( pBuffer );
            break;
        default:
            free( pBuffer );
            break;
        }
    }

    return 0;
}

void menu ( void *pBuffer ) {
    do {
        printf("1. Adicinar Pessoa\n");
        printf("2. Remover Pessoa\n");
        printf("3. Buscar Pessoa\n");
        printf("4. Listar Todos\n");
        printf("5. Sair\n");
        scanf("%d", (int *)pBuffer);
    } while ( *(int *)pBuffer <= 0 || *(int *)pBuffer > 5 );
}

void *adicionarPessoa ( void *pBuffer ){
    printf("Nome: ");
    getchar(); //scanf no menu deixa um \n, limpa o buffer do teclado
    fgets((char *)pBuffer + (5*sizeof(int)), 50, stdin);
    *((char *)pBuffer + (5*sizeof(int)) + strcspn((char *)pBuffer + (5*sizeof(int)), "\n")) = '\0'; //substitui o \n por \0

    pBuffer = realloc(pBuffer, (*(int *)(pBuffer + 2*sizeof(int)) + (strlen((char *)pBuffer + (5*sizeof(int)))) + 1)); //aumenta o espaço de memoria disponivel
    strcpy((char *)pBuffer + *(int *)(pBuffer + 2*sizeof(int)), (char *)pBuffer + (5*sizeof(int))); //copia do rascunho para o espaço real
    *(int *)(pBuffer + 2*sizeof(int)) = (*(int *)(pBuffer + 2*sizeof(int)) + (strlen((char *)pBuffer + (5*sizeof(int)))) + 1); //soma o tamanho da informação ao tamanho atual, +1 devido ao \0
    
    pBuffer = realloc(pBuffer, (*(int *)(pBuffer + 2*sizeof(int))) + sizeof(int));
    printf("idade: ");
    scanf("%d", (int *)((char *)pBuffer + *(int *)(pBuffer + 2*sizeof(int))));
    *(int *)(pBuffer + 2*sizeof(int)) = (*(int *)(pBuffer + 2*sizeof(int)) + sizeof(int)); //atualiza o tamanho

    printf("Email: ");
    getchar(); //scanf no menu deixa um \n, limpa o buffer do teclado
    fgets((char *)pBuffer + (5*sizeof(int)), 50, stdin);
    *((char *)pBuffer + (5*sizeof(int)) + strcspn((char *)pBuffer + (5*sizeof(int)), "\n")) = '\0'; //substitui o \n por \0

    pBuffer = realloc(pBuffer, (*(int *)(pBuffer + 2*sizeof(int)) + (strlen((char *)pBuffer + (5*sizeof(int)))) + 1));
    strcpy((char *)pBuffer + *(int *)(pBuffer + 2*sizeof(int)), (char *)pBuffer + (5*sizeof(int))); //copia o rascunho para o espaço real
    *(int *)(pBuffer + 2*sizeof(int)) = (*(int *)(pBuffer + 2*sizeof(int)) + (strlen((char *)pBuffer + (5*sizeof(int)))) + 1); //atualiza o tamanho do buffer
    
    *(int *)(pBuffer + sizeof(int)) += 1; //aumenta 1 o contador de pessoas

    return pBuffer; //quando uso o realloc o endereço onde o buffer esta na memória pode mudar
}

void buscarPessoa ( void *pBuffer ){
    *(int *)(pBuffer + 3*sizeof(int)) = (5*sizeof(int)) + (50*sizeof(char)); //variavel que vai ser usada para o loop, começa onde as informações reais começam, pula os int de controle
    *(int *)(pBuffer + 4*sizeof(int)) = 0; //variavel que vai ser usada para o loop,

    printf("Nome: ");
    getchar(); //scanf no menu deixa um \n, limpa o buffer do teclado
    fgets((char *)pBuffer + (5*sizeof(int)), 50, stdin); //coloca o nome lido no espaço de rascunho
    *((char *)pBuffer + (5*sizeof(int)) + strcspn((char *)pBuffer + (5*sizeof(int)), "\n")) = '\0'; //substitui o \n por \0

    while(*(int *)(pBuffer + 4*sizeof(int)) < *(int *)(pBuffer + sizeof(int))) {
        if (strcmp((char *)pBuffer + (5 * sizeof(int)), (char *)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) == 0) {
            printf("\nNome: %s,", (char *)pBuffer + *(int *)(pBuffer + 3 * sizeof(int)));

            printf("\nIdade", *(int *)((char *)pBuffer + *(int *)(pBuffer + 3 * sizeof(int)) + strlen((char *)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) + 1)); //imprime a informação seguinte do nome = idade

            printf("\nEmail: %s\n", (char *)pBuffer + *(int *)(pBuffer + 3 * sizeof(int)) + strlen((char *)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) + 1 + sizeof(int)); //imprime a informação seguinte da idade = email
        }

        *(int *)(pBuffer + 3 *sizeof(int)) += strlen((char*)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) + 1;  //move indicador das informações reais para a idade, +1 por causa do \0
        
        *(int *)(pBuffer + 3*sizeof(int)) += sizeof(int); //move indicador das informações reais para a idade

        *(int *)(pBuffer + 3 *sizeof(int)) += strlen((char*)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) + 1;  //move indicador das informações para o proximo nome
        
        *(int *)(pBuffer + 4*sizeof(int)) += 1; //variavel de controle do loop
    }
}

void listarPessoa ( void *pBuffer ) {
    *(int *)(pBuffer + 3*sizeof(int)) = (5*sizeof(int)) + (50*sizeof(char)); //variavel que vai ser usada para o loop, começa onde as informações reais começam, pula os int de controle
    *(int *)(pBuffer + 4*sizeof(int)) = 0; //variavel que vai ser usada para o loop,

    while(*(int *)(pBuffer + 4*sizeof(int)) < *(int *)(pBuffer + sizeof(int))) { //variavel de controle < numero de pessoas
        printf("\n------------------------------------------------------");
        printf("\nNome: %s", (char*)pBuffer + *(int *)(pBuffer + 3*sizeof(int)));
        *(int *)(pBuffer + 3 *sizeof(int)) += strlen((char*)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) + 1;  //move indicador das informações reais para a idade, +1 por causa do \0
        
        printf("\nIdade %d", *(int *)((char *)pBuffer + *(int *)(pBuffer + 3*sizeof(int)))); 
        *(int *)(pBuffer + 3*sizeof(int)) += sizeof(int); //move indicador das informações reais para a idade

        printf("\nEmail: %s", (char*)pBuffer + *(int *)(pBuffer + 3*sizeof(int)));
        *(int *)(pBuffer + 3 *sizeof(int)) += strlen((char*)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) + 1;  //move indicador das informações para o proximo nome

        *(int *)(pBuffer + 4*sizeof(int)) += 1; //variavel de controle do loop
    }
}