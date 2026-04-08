int converte(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return 0;
    }
}

int romanToInt(char* s) {
    int n = strlen(s);
    int total=0;

    for(int i=0; i < n; i++){
        int atual = converte(s[i]);
        int prox = converte(s[i+1]);

        if(atual < prox){
            total -= atual;
        }
        else{
            total += atual;
        }
    }

    return total;
}