#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL){
        return true;
    }

    if (root->left != NULL){
        if(root->val != root->left->val)
            return false;
    }
    
    if (root->right != NULL){
        if(root->val != root->right->val)
            return false;
    }

    int dir = isUnivalTree(root->right);
    int esq = isUnivalTree(root->left);
    
    return dir && esq;

}