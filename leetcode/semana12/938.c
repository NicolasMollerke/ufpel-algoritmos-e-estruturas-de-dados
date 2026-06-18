#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int rangeSumBST(struct TreeNode* root, int low, int high) {
    if (root == NULL){
        return 0;
    }

    if (root->val >= low && root->val <= high) {
        int dir = rangeSumBST(root->right, low, high);
        int esq = rangeSumBST(root->left, low, high);

        return root->val + esq + dir;
    }

    if (root->val < low) {
        int dir = rangeSumBST(root->right, low, high);
        return dir;
    }

    if (root->val > high) {
        int esq = rangeSumBST(root->left, low, high);
        return esq;
    }

    return 0;
}