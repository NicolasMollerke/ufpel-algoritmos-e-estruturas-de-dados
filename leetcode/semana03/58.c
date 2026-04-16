#include <stdio.h>

int lengthOfLastWord(char* s);

int main() {
    char *s;
    int cont;

    cont = lengthOfLastWord(s);
}

int lengthOfLastWord(char* s) {
    char *p = s;
    int cont=0;

    while(*p != '\0'){
        p++;
    }
    p--;


    while(p >= s && *p == ' '){
        p--;
    }
    while(p >= s && *p != ' '){
        p--;
        cont++;
    }
    return cont;
}