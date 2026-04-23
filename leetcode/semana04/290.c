#include <stdio.h>
#include <stdbool.h>

char findTheDifference(char* s, char* t);

int main(){
    char* s, t;
    char resul;
    
    resul = findTheDifference(s, t);


}

char findTheDifference(char* s, char* t) {
    
    for (int i=0; t[i] != '\0'; i++){
        bool verif=false;
       
        for (int j=0; s[j] != '\0'; j++){
            if(t[i] == s[j]){
                verif = true;
                s[j] = ' ';
                break;
            }
        }

        if (verif == false){
            return t[i];
        }
    }

    return 0;
}