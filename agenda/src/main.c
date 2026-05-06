#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu ( void *pBuffer );
void *AdicionarPessoa ( void *pBuffer );
void *RemoverPessoa ( void *pBuffer );
void BuscarPessoa ( void *pBuffer );
void ListarPessoas( void *pBuffer );

int main() {
    void *pBuffer;

    pBuffer = malloc(6*sizeof(int)); //aloca para a escolha no Menu, contador de pessoas, tamannho da memoria
    pBuffer = realloc(pBuffer, (6*sizeof(int)) + (50*sizeof(char))); //espaço rascunho para as infromações
    *(int *)(pBuffer) = 0; //ecolha do Menu
    *(int *)(pBuffer + sizeof(int)) = 0; //contador de pessoas = 0
    *(int *)(pBuffer + 2*sizeof(int)) = (6*sizeof(int)) + (50*sizeof(char));  //tamanho total da memoria = bytes dos int + bytes do char + pessoas
    *(int *)(pBuffer + 3*sizeof(int)) = 0; //int que vai ser usado para o loop, começa onde as informações reais começam, pula os bytes de controle
    *(int *)(pBuffer + 4*sizeof(int)) = 0; //int que vai ser usado para começar o loop
    *(int *)(pBuffer + 5*sizeof(int)) = 0; //int que vai ser para calculr o tamanho das informações da pessoa removida


    for ( ;; ) {
        Menu ( pBuffer );
        switch ( *(int *)pBuffer ) {
        case 1:
            pBuffer = AdicionarPessoa ( pBuffer );
            break;
        case 2:
            pBuffer = RemoverPessoa ( pBuffer );
            break;
        case 3:
            BuscarPessoa ( pBuffer );
            break;
        case 4:
            ListarPessoas ( pBuffer );
            break;
        case 5:
            free ( pBuffer );
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}

void Menu ( void *pBuffer ) {
    do {
        printf("\n");
        printf("\n1. Adicinar Pessoa");
        printf("\n2. Remover Pessoa");
        printf("\n3. Buscar Pessoa");
        printf("\n4. Listar Todos");
        printf("\n5. Sair\n");
        scanf("%d", (int *)pBuffer);
    } while ( *(int *)pBuffer <= 0 || *(int *)pBuffer > 5 );
}

void *AdicionarPessoa ( void *pBuffer ){
    printf("Nome: ");
    getchar(); //scanf no Menu deixa um \n, limpa o buffer do teclado
    fgets((char *)pBuffer + (6*sizeof(int)), 50, stdin);
    *((char *)pBuffer + (6*sizeof(int)) + strcspn((char *)pBuffer + (6*sizeof(int)), "\n")) = '\0'; //substitui o \n por \0

    pBuffer = realloc(pBuffer, (*(int *)(pBuffer + 2*sizeof(int)) + (strlen((char *)pBuffer + (6*sizeof(int)))) + 1)); //aumenta o espaço de memoria disponivel
    strcpy((char *)pBuffer + *(int *)(pBuffer + 2*sizeof(int)), (char *)pBuffer + (6*sizeof(int))); //copia do rascunho para o espaço real
    *(int *)(pBuffer + 2*sizeof(int)) = (*(int *)(pBuffer + 2*sizeof(int)) + (strlen((char *)pBuffer + (6*sizeof(int)))) + 1); //soma o tamanho da informação ao tamanho atual, +1 devido ao \0
    
    pBuffer = realloc(pBuffer, (*(int *)(pBuffer + 2*sizeof(int))) + sizeof(int));
    printf("idade: ");
    scanf("%d", (int *)((char *)pBuffer + *(int *)(pBuffer + 2*sizeof(int))));
    *(int *)(pBuffer + 2*sizeof(int)) = (*(int *)(pBuffer + 2*sizeof(int)) + sizeof(int)); //atualiza o tamanho

    printf("Email: ");
    getchar(); //scanf no Menu deixa um \n, limpa o buffer do teclado
    fgets((char *)pBuffer + (6*sizeof(int)), 50, stdin);
    *((char *)pBuffer + (6*sizeof(int)) + strcspn((char *)pBuffer + (6*sizeof(int)), "\n")) = '\0'; //substitui o \n por \0

    pBuffer = realloc(pBuffer, (*(int *)(pBuffer + 2*sizeof(int)) + (strlen((char *)pBuffer + (6*sizeof(int)))) + 1));
    strcpy((char *)pBuffer + *(int *)(pBuffer + 2*sizeof(int)), (char *)pBuffer + (6*sizeof(int))); //copia o rascunho para o espaço real
    *(int *)(pBuffer + 2*sizeof(int)) = (*(int *)(pBuffer + 2*sizeof(int)) + (strlen((char *)pBuffer + (6*sizeof(int)))) + 1); //atualiza o tamanho do buffer
    
    *(int *)(pBuffer + sizeof(int)) += 1; //aumenta 1 o contador de pessoas

    printf("\nPessoa adicionada com sucesso!");

    return pBuffer; //quando uso o realloc o endereço onde o buffer esta na memória pode mudar
}

void *RemoverPessoa ( void *pBuffer ){
    *(int *)(pBuffer + 3*sizeof(int)) = (6*sizeof(int)) + (50*sizeof(char)); 
    *(int *)(pBuffer + 4*sizeof(int)) = 0;
    *(int *)(pBuffer + 5*sizeof(int)) = 0;

    printf("Nome: ");
    getchar(); //scanf no Menu deixa um \n, limpa o buffer do teclado
    fgets((char *)pBuffer + (6*sizeof(int)), 50, stdin); //coloca o nome lido no espaço de rascunho
    *((char *)pBuffer + (6*sizeof(int)) + strcspn((char *)pBuffer + (6*sizeof(int)), "\n")) = '\0'; //substitui o \n por \0

    while (*(int *)(pBuffer + 4*sizeof(int)) < *(int *)(pBuffer + sizeof(int))) {
        if (strcmp((char *)pBuffer + (6* sizeof(int)), (char *)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) == 0) {
            *(int *)(pBuffer + 5*sizeof(int)) += strlen((char *)pBuffer + *(int *)(pBuffer + 3*sizeof(int))) + 1; //nome

            *(int *)(pBuffer + 5*sizeof(int)) += sizeof(int); //idade

            *(int *)(pBuffer + 5*sizeof(int)) += strlen((char *)pBuffer + *(int *)(pBuffer + 3*sizeof(int)) + *(int *)(pBuffer + 5*sizeof(int))) + 1; //le o email = memoria do inicio de pessoa + memoria de tudo que foi lido até o momento

            //*(int *)(pBuffer + 5*sizeof(int)) int da memoria total que as informações da pessoa ocupa
            //*(int *)(pBuffer + 3 *sizeof(int)) int da memoria em que as informações da pessoa começam
            *(int *)(pBuffer + 4*sizeof(int)) = *(int *)(pBuffer + 3 *sizeof(int)) + *(int *)(pBuffer + 5*sizeof(int));

            //*(int *)(pBuffer + 4*sizeof(int)) esta no final da informação da pessoa excluida

            while (*(int *)(pBuffer + 4*sizeof(int)) < *(int *)(pBuffer + 2*sizeof(int))){
                *((char *)pBuffer + (*(int *)(pBuffer + 4*sizeof(int)) - *(int *)(pBuffer + 5*sizeof(int)))) = *((char *)pBuffer + *(int *)(pBuffer + 4*sizeof(int)));
                //pega o inicio da proxima pessoa e coloca no lugar da excluida

                *(int *)(pBuffer + 4*sizeof(int)) += 1;
            }

            *(int *)(pBuffer + 2*sizeof(int)) -= *(int *)(pBuffer + 5*sizeof(int)); //atualiza o tamanho total
            *(int *)(pBuffer + sizeof(int)) -= 1; //atualiza o contador de pessoas

            pBuffer = realloc(pBuffer, *(int *)(pBuffer + 2*sizeof(int)));

            printf("\nPessoa removida com sucesso!");

            return pBuffer;   
        }

        *(int *)(pBuffer + 3 *sizeof(int)) += strlen((char*)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) + 1;  //move indicador das informações reais para a idade, +1 por causa do \0
        
        *(int *)(pBuffer + 3*sizeof(int)) += sizeof(int); //move indicador das informações reais para a idade

        *(int *)(pBuffer + 3 *sizeof(int)) += strlen((char*)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) + 1;  //move indicador das informações para o proximo nome

        *(int *)(pBuffer + 4*sizeof(int)) += 1;
    }
    return pBuffer;
}


void BuscarPessoa ( void *pBuffer ){
    *(int *)(pBuffer + 3*sizeof(int)) = (6*sizeof(int)) + (50*sizeof(char)); //variavel que vai ser usada para o loop, começa onde as informações reais começam, pula os int de controle
    *(int *)(pBuffer + 4*sizeof(int)) = 0; //variavel que vai ser usada para o loop,

    printf("Nome: ");
    getchar(); //scanf no Menu deixa um \n, limpa o buffer do teclado
    fgets((char *)pBuffer + (6*sizeof(int)), 50, stdin); //coloca o nome lido no espaço de rascunho
    *((char *)pBuffer + (6*sizeof(int)) + strcspn((char *)pBuffer + (6*sizeof(int)), "\n")) = '\0'; //substitui o \n por \0

    while(*(int *)(pBuffer + 4*sizeof(int)) < *(int *)(pBuffer + sizeof(int))) {
        if (strcmp((char *)pBuffer + (6 * sizeof(int)), (char *)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) == 0) {
            printf("\n");
            
            printf("\nNome: %s", (char *)pBuffer + *(int *)(pBuffer + 3 * sizeof(int)));

            printf("\nIdade: %d", *(int *)((char *)pBuffer + *(int *)(pBuffer + 3 * sizeof(int)) + strlen((char *)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) + 1)); //imprime a informação seguinte do nome = idade

            printf("\nEmail: %s\n", (char *)pBuffer + *(int *)(pBuffer + 3 * sizeof(int)) + strlen((char *)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) + 1 + sizeof(int)); //imprime a informação seguinte da idade = email
        }

        *(int *)(pBuffer + 3 *sizeof(int)) += strlen((char*)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) + 1;  //move indicador das informações reais para a idade, +1 por causa do \0
        
        *(int *)(pBuffer + 3*sizeof(int)) += sizeof(int); //move indicador das informações reais para a idade

        *(int *)(pBuffer + 3 *sizeof(int)) += strlen((char*)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) + 1;  //move indicador das informações para o proximo nome

        *(int *)(pBuffer + 4*sizeof(int)) += 1;
    }
}

void ListarPessoas ( void *pBuffer ) {
    *(int *)(pBuffer + 3*sizeof(int)) = (6*sizeof(int)) + (50*sizeof(char)); //variavel que vai ser usada para o loop, começa onde as informações reais começam, pula os int de controle
    *(int *)(pBuffer + 4*sizeof(int)) = 0; //variavel que vai ser usada para o loop,

    printf("\n------------------------------------------------------");
    while(*(int *)(pBuffer + 4*sizeof(int)) < *(int *)(pBuffer + sizeof(int))) { //variavel de controle < numero de pessoas
        printf("\nNome: %s", (char*)pBuffer + *(int *)(pBuffer + 3*sizeof(int)));
        *(int *)(pBuffer + 3 *sizeof(int)) += strlen((char*)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) + 1;  //move indicador das informações reais para a idade, +1 por causa do \0
        
        printf("\nIdade %d", *(int *)((char *)pBuffer + *(int *)(pBuffer + 3*sizeof(int)))); 
        *(int *)(pBuffer + 3*sizeof(int)) += sizeof(int); //move indicador das informações reais para a idade

        printf("\nEmail: %s", (char*)pBuffer + *(int *)(pBuffer + 3*sizeof(int)));
        *(int *)(pBuffer + 3 *sizeof(int)) += strlen((char*)pBuffer + *(int *)(pBuffer + 3 * sizeof(int))) + 1;  //move indicador das informações para o proximo nome
        printf("\n------------------------------------------------------");


        *(int *)(pBuffer + 4*sizeof(int)) += 1; //variavel de controle do loop
    }
}