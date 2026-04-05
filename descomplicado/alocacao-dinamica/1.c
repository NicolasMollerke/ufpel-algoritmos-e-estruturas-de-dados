/*Crie um programa que:
(a) Aloque dinamicamente um array de 5 numeros inteiros, ´
(b) Pec¸a para o usuario digitar os 5 n ´ umeros no espac¸o alocado, ´
(c) Mostre na tela os 5 numeros, ´
(d) Libere a memoria alocada.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *numeros = malloc(5*sizeof(int));

    if (numeros == NULL) {
        printf("Erro: Memória insuficiente!\n");
        return -1; 
    }

    for(int i=0; i < 5; i++){
        printf("Digite um numero: ");
        scanf("%d", &numeros[i]);
    }

    for(int i=0; i < 5; i++){
        printf("%d\n", numeros[i]);
    }

    free(numeros);
}
