#include <stdio.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int esq = maxDepth(root->left);
    int dir = maxDepth(root->right);

    if (esq > dir) {
        return esq + 1;
    } else {
        return dir + 1;
    }
}