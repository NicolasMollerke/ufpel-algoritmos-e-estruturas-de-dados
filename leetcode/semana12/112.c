#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;
    }

    if (root->left == NULL && root->right == NULL) {
        return (root->val == targetSum);
    }

    bool esq = hasPathSum(root->left, targetSum - root->val);
    bool dir = hasPathSum(root->right, targetSum - root->val);

    return esq || dir;
}