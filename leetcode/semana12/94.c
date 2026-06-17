#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

 void copiaVetor (struct TreeNode* root, int* resultado, int* returnSize){
    if (root == NULL) {
        return;
    }

    copiaVetor (root->left, resultado, returnSize);

    resultado[*returnSize] = root->val;
    (*returnSize)++;

    copiaVetor (root->right, resultado, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *resultado = malloc(100*sizeof(int));
    *returnSize=0;

    copiaVetor (root, resultado, returnSize);

    return resultado;
}