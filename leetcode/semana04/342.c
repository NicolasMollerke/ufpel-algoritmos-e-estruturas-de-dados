#include <stdio.h>
#include <stdbool.h>

bool isPowerOfFour(int n);

int main(){
    int n;
    bool resul;
    
    resul = findTheDifference(n);

}

bool isPowerOfFour(int n) {    
    
    if(n <= 0){
        return 0;
    }
    
    
    while (n % 4 == 0){
        n = n/4;
    }

    if( n == 1 ){
        return 1;
    }

    return 0;
}