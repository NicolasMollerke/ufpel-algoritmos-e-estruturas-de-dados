#include <stdio.h>
#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine);

int main(){
    char* ramsomNote = "aa";
    char* magazine = "aab";
    bool resul;
    
    resul = canConstruct(ramsomNote, magazine);

    printf("%b", resul);
}

bool canConstruct(char* ransomNote, char* magazine) {
    bool resul;
    char *p = magazine;
    char *p_aux = p;

    for(int i=0; i < strlen(ransomNote); i++){
        while(*p_aux != '\0'){
            if(ransomNote[i] == *p_aux){
                resul = true;
                *p_aux = ' ';
                p_aux = p;
                break;
            } else {
                resul = false;
                p_aux++;
            }
        }
    }

    return resul;
}