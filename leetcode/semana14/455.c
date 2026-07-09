int comparar( const void *a, const void *b ) {
    int num1 = *(int*) a;
    int num2 = *(int*) b;

    if ( num1 < num2 ) return -1;
    if ( num2 < num1 ) return 1;
    return 0;
} 

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int cont = 0;
    int i = 0;
    int j = 0;
    
    qsort( g, gSize, sizeof(int), comparar );
    qsort( s, sSize, sizeof(int), comparar );

    while ( i < gSize && j < sSize ) {
        if ( g[i] <= s[j] ) {
            cont++;
            i++;
            j++;
        } else {
            j++;
        }
    }

    return cont;
}