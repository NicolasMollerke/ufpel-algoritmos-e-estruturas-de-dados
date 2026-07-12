#include <stdlib.h>

int** criarMatrizDinamica(int linhasDesejadas, int** returnColumnSizes) {
    // 1. Aloca o "esqueleto" da matriz: um array que guarda PONTEIROS (int*)
    // É como criar uma lista de "vagas" para as nossas linhas.
    int** matriz = (int**)malloc(linhasDesejadas * sizeof(int*));

    // 2. Aloca o array de controle que o LeetCode exige para saber o tamanho de cada linha
    *returnColumnSizes = (int*)malloc(linhasDesejadas * sizeof(int));

    // 3. Agora, passamos linha por linha alocando espaço para os NÚMEROS reais
    for (int i = 0; i < linhasDesejadas; i++) {
        
        // Cada linha vai ter espaço para exatamente 3 números inteiros (um trio)
        matriz[i] = (int*)malloc(3 * sizeof(int));
        
        // Avisamos no array do LeetCode que essa linha 'i' tem 3 colunas
        (*returnColumnSizes)[i] = 3;
    }

    // Pronto! Agora você pode usar a matriz normalmente, ex: matriz[0][0] = 10;
    return matriz;
}