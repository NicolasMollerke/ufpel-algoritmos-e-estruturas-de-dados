int numberOfSteps(int num) {
    int cont=0;
    
    while (num != 0){
        if(num % 2 == 0){
            num = num/2;
            cont++;
        } else if(num % 2 != 0){
            num = num - 1;
            cont++;
        }
    }

    return cont;
}