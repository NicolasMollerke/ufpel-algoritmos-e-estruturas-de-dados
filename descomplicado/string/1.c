/* Fac¸a um programa que entao leia uma string e a imprima*/

#include <stdio.h>
#include <string.h>

int main(){
    char string[50];

    printf("Digite uma string: ");
    fgets(string, 50, stdin);

    puts(string);
}