#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void criaVetor(struct TreeNode* root, int *vet, int *p) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        vet[*p] = root->val;
        (*p)++;
    }

    criaVetor(root->right, vet, p);
    criaVetor(root->left, vet, p);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int *vet1 = malloc(200*sizeof(int));
    int *vet2 = malloc(200*sizeof(int));
    int p = 0;
    int q = 0;
    int maior;

    criaVetor(root1, vet1, &p);
    criaVetor(root2, vet2, &q);

    if (p != q) {
        return false;
    }

    for (int i=0; i <= p; i++){
        if (vet1[i] != vet2[i]) {
            return 0;
        }
    }

    return 1;
}