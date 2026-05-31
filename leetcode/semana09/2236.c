#include <stdbool.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

bool checkTree(struct TreeNode* root) {
    int soma = root->left->val + root->right->val;
    
    if (soma == root){
        return true;
    } else {
        return false;
    }
}