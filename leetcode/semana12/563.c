#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int calc (struct TreeNode* root, int* total){
    if(root == NULL) {
        return 0;
    }

    int esq = calc(root->left, total);
    int dir = calc(root->right, total);
    
    int inq = abs(esq - dir);

    *total += inq;

    return root->val + esq + dir;
}

int findTilt(struct TreeNode* root) {
    int total = 0;

    calc (root, &total);

    return total;
}