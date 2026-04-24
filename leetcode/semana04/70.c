#include <stdio.h>

int climbStairs(int n);

int main(){
    int n;
    int resul;
    
    resul = climbStairs(n);

}

int climbStairs(int n) {
    int n1=1, n2=2, resul;

    
    if(n == 1 || n == 2){
        return n;
    }
    
    for (int i=3; i <= n; i++) {
        resul = n1 + n2;
        n1 = n2;
        n2 = resul;
    }

    return resul;
    
}