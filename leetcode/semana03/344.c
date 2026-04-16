#include <stdio.h>

void reverseString(char *s, int sSize);

int main(){
    char *s;
    int sSize;

    reverseString(s, sSize);
}

void reverseString(char *s, int sSize){
    for(int i=0; i < sSize / 2;i++){
        char temp = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = temp;
    }
}
