#include <stdio.h>
#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize);

int main(int argc, char const *argv[]){
    int *bills;
    int billsSize;
    bool resul;
    
    resul = (bills, billsSize);

    return 0;
}

bool lemonadeChange(int* bills, int billsSize){
    int cont5=0;
    int cont10=0;
    
    for (int i=0; i < billsSize; i++){
        if (bills[i] == 5){
            cont5 ++;
        } if (bills[i] == 10){
            cont5--;
            cont10++;
        } if (bills[i] == 20) {
            if(cont10 >= 1 && cont5 > 0){
                cont10 = cont10 -1;
                cont5 --;
            }else if (cont10 == 0 && cont5 >= 3) {
                cont5 -= 3;
            }else{
                return false;
            }
        }
    }

    if (cont5 >= 0){
        return true;
    } else {
        return false;
    }
}

