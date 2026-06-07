#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if ( root == NULL ) {
        struct TreeNode *novo = malloc(sizeof(struct TreeNode));
        novo->val = val;
        novo->left = NULL;
        novo->right = NULL;

        return novo;
    }

    if ( val < root->val ) {
        root->left = insertIntoBST(root->left, val);
    }

    if ( val > root->val ) {
        root->right = insertIntoBST(root->right, val);
    }

    return root;

}